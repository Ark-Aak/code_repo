#include <bits/stdc++.h>
#define int ll

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

const int MAXN = 1e5 + 5;
namespace LCT {
	int rt, tot, fa[MAXN], ch[MAXN][2], cnt[MAXN];
	int tag[MAXN], siz[MAXN];

#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
#define get(x) ((x) == ch[fa[x]][1])
#define isRoot(x) (ch[fa[x]][0] != x && ch[fa[x]][1] != x)

	inline void pushup(int x) { siz[x] = siz[ls(x)] + siz[rs(x)] + 1; }

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

	void pushall(int x) {
		if (!isRoot(x)) pushall(fa[x]);
		pushdown(x);
	}

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
	inline void link(int x, int y) { split(x, y); if (find(y) != x) fa[x] = y; }

	inline void cut(int x, int y) {
		split(x, y);
		if (find(y) == x && fa[y] == x && !ls(y)) {
			fa[y] = rs(x) = 0;
			pushup(x);
		}
	}
#undef ls
#undef rs
#undef get
#undef isRoot
} // namespace LCT

int n, m;

signed main() {
	n = read(), m = read();
	rep (i, 1, n) LCT::siz[i] = 1;
	rep (i, 1, m) {
		int tp = read();
		if (tp == 1) {
			int u = read(), v = read();
			LCT::link(u, v);
		}
		else {
			int u = read(), v = read();
			if (LCT::find(u) != LCT::find(v)) { puts("0"); continue; }
			LCT::split(u, v);
			if (LCT::siz[v] != 3) { puts("0"); continue; }
			print(LCT::ch[LCT::ch[v][0]][1]), puts("");
			/* print(LCT::ch[v][1]), puts(""); */
		}
	}
	return 0;
}
