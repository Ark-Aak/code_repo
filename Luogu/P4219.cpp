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
	int tag[MAXN], siz[MAXN], siz2[MAXN];

#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
#define get(x) ((x) == ch[fa[x]][1])
#define isRoot(x) (ch[fa[x]][0] != x && ch[fa[x]][1] != x)

	inline void pushup(int x) {
		assert(siz[0] == 0 && siz2[0] == 0);
		if (x) siz[x] = siz[ls(x)] + siz[rs(x)] + 1 + siz2[x];
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

	void access(int x) {
		for (int y = 0; x; x = fa[y = x]) {
			splay(x);
			siz2[x] -= siz[y];
			siz2[x] += siz[rs(x)];
			rs(x) = y, pushup(x);
		}
	}
	inline void makeRoot(int x) { access(x), splay(x), reverse(x); }

	inline int find(int x) {
		access(x), splay(x);
		while (ls(x)) pushdown(x), x = ls(x);
		splay(x);
		return x;
	}

	inline void split(int x, int y) { makeRoot(x), access(y), splay(y); }
	inline void link(int x, int y) {
		/* cout << "link:" << x << " " << y << endl; */
		makeRoot(x);
		makeRoot(y);
		if (find(y) != x) {
			fa[x] = y;
			siz2[y] += siz[x];
			pushup(y);
		}
	}

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
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	rep (i, 1, n) LCT::siz[i] = 1;
	rep (i, 1, m) {
		char op;
		int x, y;
		cin >> op >> x >> y;
		if (op == 'A') LCT::link(x, y);
		else {
			LCT::split(x, y);
			ll val = 1ll * (LCT::siz2[x] + 1) * (LCT::siz2[y] + 1);
			/* cout << LCT::siz2[x] << " " << LCT::siz2[y] << endl; */
			print(val), puts("");
		}
	}
	return 0;
}
