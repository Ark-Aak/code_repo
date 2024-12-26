#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 2e5 + 5;

namespace LCT {

	int rt, tot, fa[MAXN], ch[MAXN][2], val[MAXN], cnt[MAXN];
	int mx[MAXN], tag[MAXN];

#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
#define get(x) ((x) == ch[fa[x]][1])
#define isRoot(x) (ch[fa[x]][0] != x && ch[fa[x]][1] != x)

	inline void pushup(int x) {
		mx[x] = val[mx[ls(x)]] > val[mx[rs(x)]] ? mx[ls(x)] : mx[rs(x)];
		mx[x] = val[x] > val[mx[x]] ? x : mx[x];
	}
	inline void reverse(int x) { swap(ls(x), rs(x)), tag[x] ^= 1; }
	inline void pushdown(int x) {
		if (tag[x]) {
			if (ls(x)) reverse(ls(x));
			if (rs(x)) reverse(rs(x));
			tag[x] = 0;
		}
	}
	void rotate(int x) {
		int y = fa[x], z = fa[y], k = ch[y][1] == x, w = ch[x][!k];
		if (!isRoot(y)) ch[z][ch[z][1] == y] = x;
		ch[x][!k] = y, ch[y][k] = w;
		if (w) fa[w] = y;
		fa[y] = x, fa[x] = z;
		pushup(y), pushup(x);
	}
	void pushall(int x) { if (!isRoot(x)) pushall(fa[x]); pushdown(x); }
	void splay(int x) {
		int y = x, z = 0;
		pushall(x);
		while (!isRoot(x)) {
			y = fa[x], z = fa[y];
			if (!isRoot(y))
				rotate((ls(y) == x) ^ (ls(z) == y) ? x : y);
			rotate(x);
		}
		pushup(x);
	}
	void access(int x) { for (int y = 0; x; x = fa[y = x]) splay(x), rs(x) = y, pushup(x); }
	inline void makeRoot(int x) { access(x), splay(x), reverse(x); }
	inline int find(int x) {
		access(x), splay(x);
		while (ls(x)) pushdown(x), x = ls(x);
		splay(x);
		return x;
	}
	inline void split(int x, int y) { makeRoot(x), access(y), splay(y); }
	inline void link(int x, int y) { makeRoot(x); if (find(y) != x) fa[x] = y; }
	inline void cut(int x, int y) {
		split(x, y);
		if (find(y) == x && fa[y] == x && !ls(y))
			fa[y] = rs(x) = 0, pushup(x);
	}
#undef ls
#undef rs
#undef get
#undef isRoot
} // namespace LCT

int fa[MAXN];
int n, m;

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	fa[find(x)] = find(y);
}

int u[MAXN], v[MAXN], w[MAXN], ans[MAXN];

signed main() {
	n = read(), m = read();
	rep (i, 1, m) ans[i] = 1e9;
	rep (i, 1, m) fa[i] = i;
	rep (i, 1, m) {
		u[i] = read(), v[i] = read(), w[i] = read();
		LCT::val[n + i] = w[i];
	}
	rep (i, 1, m) {
		if (LCT::find(u[i]) != LCT::find(v[i])) {
			LCT::link(u[i], n + i);
			LCT::link(n + i, v[i]);
			continue;
		}
		else {
			LCT::split(u[i], v[i]);
			int mx = LCT::mx[v[i]];
			if (LCT::val[mx] <= w[i]) {
				ans[i] = min(ans[i], LCT::val[mx]);
				merge(i, mx - n);
			}
			else {
				ans[mx - n] = min(ans[mx - n], w[i]);
				merge(mx - n, i);
				LCT::cut(u[mx - n], mx);
				LCT::cut(mx, v[mx - n]);
				LCT::link(u[i], i + n);
				LCT::link(i + n, v[i]);
			}
		}
	}
	rep (i, 1, m) ans[i] = min(ans[i], w[find(i)]);
	rep (i, 1, m) print(ans[i]), puts("");
	return 0;
}
