#include <iostream>
#include <algorithm>
#include <cstdio>
#include <array>
#include <vector>
using namespace std;

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
const int N = 1e6 + 5, M = 2e6 + 5;
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
namespace T {

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
namespace Rst {

int cnt, tp, tot;
array <int, N> dfn, low;
array <int, 2 * N> stk, siz;
array <vector <int>, N> cur;
void tarjan(int x) {
	/* write(x), puts(""); */
	cnt++;
	dfn[x] = low[x] = cnt;
	stk[++tp] = x;
	for (int i = G::fir[x]; i; i = G::nex[i]) {
		if (!dfn[G::to[i]]) {
			tarjan(G::to[i]);
			low[x] = min(low[x], low[G::to[i]]);
			if (low[G::to[i]] != dfn[x]) continue;
			tot++;
			cur[x].push_back(tot);
			T::add(x, tot);
			T::add(tot, x);
			/* write(x), putchar(32); */
			/* write(tot), puts("@"); */
			stk[tp + 1] = 0;
			siz[tot]++;
			while (stk[tp + 1] != G::to[i]) {
				cur[stk[tp]].push_back(tot);
				/* write(stk[tp]), putchar(32); */
				/* write(tot), puts("@"); */
				T::add(stk[tp], tot);
				T::add(tot, stk[tp--]);
				siz[tot]++;
			}
		}
		else
			low[x] = min(low[x], dfn[G::to[i]]);
	}
}
}
namespace Hpt {

array <int, N> fa, siz, dep, son;
using T::fir, T::nex, T::to;
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
array <int, N> dfn, idx, top;
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
array <int, N> s;
namespace Sgt {

array <int, N * 4> edge;
using Hpt::idx;
void pushup(int x) {
	edge[x] = edge[x * 2] ^ edge[x * 2 + 1];
}
void build(int x, int l, int r) {
	if (l == r) {
		edge[x] = s[idx[l]];
		return;
	}
	int mid = (l + r) >> 1;
	build(x * 2, l, mid);
	build(x * 2 + 1, mid + 1, r);
	pushup(x);
}
int query(int x, int l, int r, int L, int R) {
	if (L > r || R < l) return 0;
	if (L <= l && R >= r) return edge[x];
	int mid = (l + r) >> 1, ans = 0;
	if (L <= mid) ans ^= query(x * 2, l, mid, L, R);
	if (R > mid) ans ^= query(x * 2 + 1, mid + 1, r, L, R);
	return ans;
}

}
namespace solve {

using Hpt::top, Hpt::fa, Hpt::dep, Hpt::dfn;
int query(int x, int y, int m) {
	int ans = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans ^= Sgt::query(1, 1, m, dfn[top[x]], dfn[x]);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ans ^= Sgt::query(1, 1, m, dfn[x], dfn[y]);
	return ans;
}

}
void dfs(int x) {
	s[x] = Hpt::siz[x];
	for (int i = T::fir[x]; i; i = T::nex[i]) {
		if (T::to[i] == Hpt::fa[x]) continue;
		s[x] ^= Hpt::siz[T::to[i]];
		dfs(T::to[i]);
	}
}
int main() {
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	int n = read(), m = read();
	for (int i = 1; i <= m; i++) {
		int x = read(), y = read();
		G::add(x, y), G::add(y, x);
	}
	Rst::tot = n;
	Rst::tarjan(1);
	/* for (int i = 1; i <= n; i++) */
		/* for (auto x : Rst::cur[i]) */
			/* s[i] ^= Rst::siz[x] - 1; */
	m = Rst::tot;
	/* for (int i = n + 1; i <= m; i++) */
		/* s[i] = Rst::siz[i] - 1; */


	/* puts("fp[s]dpfs"); */
	Hpt::dfs1(1), Hpt::dfs2(1, 0);
	/* for (int i = 1; i <= m; i++) */
		/* s[i] = Hpt::siz[i]; */
	dfs(1);
	for (int i = 1; i <= m; i++)
		write(s[i]), putchar(32);
	Sgt::build(1, 1, m);
	int q = read();
	while (q--) {
		int x = read(), y = read();
		write(solve::query(Hpt::fa[x], Hpt::fa[y], m)), puts("");
	}
	return 0;
}
