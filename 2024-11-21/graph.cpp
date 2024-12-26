#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 1e6 + 5;

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

int con, n, m, ui[MAXN], vi[MAXN];
multiset <int> s;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	con = n;
	rep (i, 1, m) {
		int u = read(), v = read(), w = read();
		ui[n + i] = u, vi[n + i] = v;
		LCT::val[n + i] = w;
		if (LCT::find(u) != LCT::find(v)) {
			con--;
			LCT::link(u, n + i);
			LCT::link(n + i, v);
			s.insert(w);
		}
		else {
			LCT::split(u, v);
			if (LCT::val[LCT::mx[v]] > w) {
				int mx = LCT::mx[v];
				s.erase(s.lower_bound(LCT::val[mx]));
				s.insert(w);
				LCT::cut(ui[mx], mx);
				LCT::cut(mx, vi[mx]);
				LCT::link(u, n + i);
				LCT::link(n + i, v);
			}
		}
		if (con != 1) {
			puts("-1");
		}
		else {
			print(*s.rbegin()), puts("");
		}
	}
	return 0;
}
