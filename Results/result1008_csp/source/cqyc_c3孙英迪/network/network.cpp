#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
using namespace std;


#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
char buf[1 << 23], *p1 = buf, *p2 = buf, ubuf[1 << 23], *u = ubuf;


int read() {
	int p = 0, flg = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') flg = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		p = p * 10 + c - '0';
		c = getchar();
	}
	return p * flg;
}
string read_() {
	string ans;
	char c = getchar();
	while (c != 'J' && c != 'C' && c != 'Q' && c != 'u' && c != 'e' && c != 'r' && c != 'y')
		c = getchar();
	while (c == 'J' || c == 'C' || c == 'Q' || c == 'u' || c == 'e' || c == 'r' || c == 'y') {
		ans += c;
		c = getchar();
	}
	return ans;
}
void write(int x) {
	if (x < 0) {
		x = -x;
		putchar('-');
	}
	if (x > 9) {
		write(x / 10);
	}
	putchar(x % 10 + '0');
}
const int N = 1e6 + 5, M = 2e6 + 5, inf = 0x7f7f7f7f;


namespace G {

array <int, N> fir;
array <int, M> nex, to;
int cnt;
void add(int x, int y) {
	cnt++;
	nex[cnt] = fir[x];
	to[cnt] = y;
	fir[x] = cnt;
}

}


namespace Hpt {

array <int, N> son, siz, fa, dep;

using G::fir, G::nex, G::to;
void dfs1(int x) {
	siz[x] = 1;
	for (int i = fir[x]; i; i = nex[i]) {
		if (to[i] == fa[x]) continue;
		fa[to[i]] = x;
		dep[to[i]] = dep[x] + 1;
		dfs1(to[i]);
		siz[x] += siz[to[i]];
		if (siz[to[i]] > siz[son[x]]) son[x] = to[i];
	}
}

array <int, N> dfn, top, idx;
int cnt;
void dfs2(int x, int Mgn) {
	cnt++;
	dfn[x] = cnt;
	idx[cnt] = x;
	top[x] = Mgn;
	if (son[x]) dfs2(son[x], Mgn);
	for (int i = fir[x]; i; i = nex[i]) {
		if (to[i] == fa[x] || to[i] == son[x]) continue;
		dfs2(to[i], to[i]);
	}
}

}


namespace Sgt {

array <int, N * 4> edge;
void pushup(int x) {
	edge[x] = min(edge[x * 2], edge[x * 2 + 1]);
}
void build(int x, int l, int r) {
	edge[x] = inf;
	if (l == r) {
		edge[x] = Hpt::idx[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	pushup(x);
}
void modify(int x, int l, int r, int y, int k) {
	if (y > r || y < l) return;
	if (l == r) {
		edge[x] = min(edge[x], k);
		return;
	}
	int mid = (l + r) >> 1;
	if (y <= mid) modify(x * 2, l, mid, y, k);
	else modify(x * 2 + 1, mid + 1, r, y, k);
	pushup(x);
}
int query(int x, int l, int r, int L, int R) {
	if (L > r || R < l) return inf;
	if (L <= l && R >= r) return edge[x];
	int mid = (l + r) >> 1, ans = inf;
	if (L <= mid) ans = min(ans, query(x * 2, l, mid, L, R));
	if (R > mid) ans = min(ans, query(x * 2 + 1, mid + 1, r, L, R))	;
	return ans;
}

}

using Hpt::top, Hpt::fa, Hpt::dep, Hpt::dfn;
int query(int x, int y, int n) {
	int ans = inf;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans = min(ans, Sgt::query(1, 1, n, dfn[top[x]], dfn[x]));
		x = fa[top[x]];
	}
	if (dfn[x] > dfn[y]) swap(x, y);
	ans = min(ans, Sgt::query(1, 1, n, dfn[x], dfn[y]));
	return ans;
}
int lca(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if (dfn[x] > dfn[y]) swap(x, y);
	return x;
}
int main() {
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	int n = read(), q = read();
	for (int i = 2; i <= n; i++) {
		int x = read(), y = read();
		G::add(x, y), G::add(y, x);
	}
	Hpt::dfs1(1), Hpt::dfs2(1, 0);
	Sgt::build(1, 1, n);
	int lcA = 0;
	while (q--) {
		string s = read_();
		/* write(query(85, 1599, n)), puts(""); */
		if (s[0] == 'J') {
			int x = read();
			if (!lcA) lcA = x;
			else lcA = lca(lcA, x);
			Sgt::modify(1, 1, n, dfn[lcA], query(x, lcA, n));
		}
		else {
			int x = read();
			write(query(x, lcA, n)), puts("");
		}
	}
	return 0;
}
