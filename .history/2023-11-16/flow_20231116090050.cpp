#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

const int MAXN = 5e4 + 5;
int n, k;
vector <int> G[MAXN];

#define mid ((L + R) >> 1)
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)

const int MAXN = 1e5 + 5;
int n, m, r, p;
int sum[MAXN << 2], lazy[MAXN << 2], w[MAXN], iw[MAXN];
int dfn[MAXN], wSon[MAXN], hSon[MAXN];
int cnt, fa[MAXN], dep[MAXN], top[MAXN];
vector <int> G[MAXN];

void pushup(int x) {
	sum[x] = sum[ls(x)] + sum[rs(x)] % p;
}

void pushdown(int x, int L, int R) {
	sum[ls(x)] += lazy[x] * (mid - L + 1) % p;
	sum[rs(x)] += lazy[x] * (R - mid) % p;
	sum[ls(x)] %= p, sum[rs(x)] %= p;
	lazy[ls(x)] += lazy[x] % p;
	lazy[rs(x)] += lazy[x] % p;
	lazy[ls(x)] %= p;
	lazy[rs(x)] %= p;
	lazy[x] = 0;
}

void build(int x, int L, int R) {
	if (L == R) return (void) (sum[x] = w[L]);
	build(ls(x), L, mid);
	build(rs(x), mid + 1, R);
	pushup(x);
}

int query(int x, int L, int R, int l, int r) {
	if (l <= L && R <= r) return sum[x];
	if (L != R && lazy[x]) pushdown(x, L, R);
	int res = 0;
	if (l <= mid) res += query(ls(x), L, mid, l, r);
	res %= p;
	if (r > mid) res += query(rs(x), mid + 1, R, l, r);
	pushup(x);
	return res % p;
}

void modify(int x, int L, int R, int l, int r, int val) {
	if (l <= L && R <= r) return (void) (sum[x] += (R - L + 1) * val, lazy[x] += val, sum[x] %= p, lazy[x] %= p);
	if (L != R && lazy[x]) pushdown(x, L, R);
	if (l <= mid) modify(ls(x), L, mid, l, r, val);
	if (r > mid) modify(rs(x), mid + 1, R, l, r, val);
	pushup(x);
}

void getSize(int step, int u, int f) {
	wSon[u] = 1; fa[u] = f; dep[u] = step;
	for (auto v : G[u]) {
		if (v == f) continue;
		getSize(step + 1, v, u);
		wSon[u] += wSon[v];
		if (wSon[v] > wSon[hSon[u]]) hSon[u] = v;
	}
}

void getDFN(int u, int header) {
	dfn[u] = ++cnt, w[cnt] = iw[u], top[u] = header;
	if (!hSon[u]) return;
	getDFN(hSon[u], header);
	for (auto v : G[u]) {
		if (v == fa[u] || v == hSon[u]) continue;
		getDFN(v, v);
	}
}

int LCA(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	return x;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("flow.in", "r", stdin);
	freopen("flow.out", "w", stdout);
#endif
#endif
	read(n), read(k);
	rep (i, 1, n - 1) {
		int u, v;
		read(u), read(v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	getSize(1, 1, 1);
	getDFN(1, 1);
	build(1, 1, n);
	rep (i, 1, k) {
		int s, t;
		read(s), read(t);
		modify(1, 1, n, dfn[s], dfn[s], 1);
		int lca = LCA(s, t);
		modify(1, 1, n, dfn[fa[lca]], dfn[fa[lca]], -1);
		modify(1, 1, n, dfn[t], dfn[t], -1);
	}
	return 0;
}