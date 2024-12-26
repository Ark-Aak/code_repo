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

const int MAXN = 4e5 + 5;
const int MAXC = 65;
int n, m, a[MAXN];
vector <int> G[MAXN];
int dfn[MAXN], fa[MAXN], siz[MAXN], son[MAXN];
int top[MAXN], dep[MAXN], clk;

bitset <MAXC> rv[MAXN];

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

void dfs0(int u, int f) {
	dep[u] = dep[f] + 1;
	siz[u] = 1; fa[u] = f;
	for (auto v : G[u]) {
		if (v == f) continue;
		dfs0(v, u);
		siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs1(int u, int h) {
	top[u] = h;
	dfn[u] = ++clk;
	rv[clk][a[u]] = 1;
	if (!son[u]) return;
	dfs1(son[u], h);
	for (auto v : G[u]) {
		if (v == son[u] || v == fa[u]) continue;
		dfs1(v, v);
	}
}

namespace seg {

	bitset <MAXC> sum[MAXN << 2];
	int lazy[MAXN << 2];

	void pushup(int x) {
		sum[x] = sum[ls(x)] | sum[rs(x)];
	}

	void build(int x, int L, int R) {
		if (L == R) {
			sum[x] = rv[L];
			return;
		}
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
		pushup(x);
	}

	void pushdown(int x, int L, int R) {
		if (!lazy[x]) return;
		sum[ls(x)].reset();
		sum[rs(x)].reset();
		sum[ls(x)][lazy[x]] = 1;
		sum[rs(x)][lazy[x]] = 1;
		lazy[ls(x)] = lazy[x];
		lazy[rs(x)] = lazy[x];
		lazy[x] = 0;
	}

	void modify(int x, int L, int R, int l, int r, int v) {
		if (l <= L && R <= r) {
			sum[x].reset();
			sum[x][v] = 1;
			lazy[x] = v;
			return;
		}
		pushdown(x, L, R);
		if (l <= mid) modify(ls(x), L, mid, l, r, v);
		if (r > mid) modify(rs(x), mid + 1, R, l, r, v);
		pushup(x);
	}

	bitset <MAXC> query(int x, int L, int R, int l, int r) {
		if (l <= L && R <= r) return sum[x];
		bitset <MAXC> res;
		pushdown(x, L, R);
		if (l <= mid) res |= query(ls(x), L, mid, l, r);
		if (r > mid) res |= query(rs(x), mid + 1, R, l, r);
		return res;
	}
}

signed main() {
	n = read(), m = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs0(1, 0);
	dfs1(1, 1);
	seg::build(1, 1, n);
	rep (i, 1, m) {
		int op = read();
		if (op == 1) {
			int v = read(), c = read();
			int l = dfn[v], r = dfn[v] + siz[v] - 1;
			seg::modify(1, 1, n, l, r, c);
		}
		else {
			int v = read();
			int l = dfn[v], r = dfn[v] + siz[v] - 1;
			bitset <MAXC> res = seg::query(1, 1, n, l, r);
			print(res.count()), puts("");
		}
	}
	return 0;
}
