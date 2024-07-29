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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 2e5 + 5;

vector <int> G[MAXN];
int dfn[MAXN], _dfn;
bool valid[MAXN];
int fa[MAXN][19], dep[MAXN], d[MAXN];

void dfs0(int step, int u, int fa) {
	dfn[u] = ++_dfn;
	::fa[u][0] = fa;
	for (auto v : G[u]) {
		if (v == fa) continue;
		d[v] = d[u] + 1;
		dfs0(step + 1, v, u);
	}
}

bool cmp(int x, int y) {
	return dfn[x] < dfn[y];
}

int h[MAXN], n, a[MAXN], len;

void init() {
	rep (j, 1, 18) {
		rep (i, 1, n) {
			fa[i][j] = fa[fa[i][j - 1]][j - 1];
		}
	}
}

int lca(int u, int v) {
	if (dep[u] > dep[v]) swap(u, v);
	int tmp = dep[v] - dep[u];
	for (int j = 0; tmp; tmp >>= 1, j++) {
		if (tmp & 1) v = fa[v][j];
	}
	if (u == v) return u;
	for (int j = 18; j && u != v; j--) {
		if (fa[u][j] != fa[v][j]) {
			u = fa[u][j];
			v = fa[v][j];
		}
	}
	return fa[u][0];
}

int dis(int u, int v) {
	return d[u] + d[v] - 2 * d[lca(u, v)];
}

void solve(int m) {
	sort(h + 1, h + m + 1, cmp);
	for (int i = 1; i < m; ++i) {
		a[++len] = h[i];
		a[++len] = lca(h[i], h[i + 1]);
	}
	a[++len] = h[m];
	sort(a + 1, a + len + 1, cmp);
	len = unique(a + 1, a + len + 1) - a - 1;
	vector <pii> T[MAXN];
	const function <void (int, int, int)> conn = [&]
		(int u, int v, int w) {
		T[u].push_back(dl(v, w));
		T[v].push_back(dl(u, w));
	};
	for (int i = 1, lc; i < len; ++i) {
		lc = lca(a[i], a[i + 1]);
		conn(lc, a[i + 1], dis(lc, a[i + 1]));
	}
}

void work() {
	dfs0(1, 1, 0);
	init();
}

int A[MAXN];

int main() {
	n = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep (i, 1, n) A[i] = read();
}
