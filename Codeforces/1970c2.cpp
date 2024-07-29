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
int n, t;
vector <int> G[MAXN];

int dfn[MAXN], siz[MAXN], son[MAXN];
int cnt, fa[MAXN], dep[MAXN], top[MAXN];

void dfs1(int step, int u, int f) {
	siz[u] = 1; fa[u] = f; dep[u] = step;
	for (auto v : G[u]) {
		if (v == f) continue;
		dfs1(step + 1, v, u);
		siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs2(int u, int h) {
	dfn[u] = ++cnt, top[u] = h;
	if (!son[u]) return;
	dfs2(son[u], h);
	for (auto v : G[u]) {
		if (v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
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

int d[MAXN];

void dfs3(int u, int fa) {
	for (auto v : G[u]) {
		if (v == fa) continue;
		d[v] = d[u] + 1;
		dfs3(v, u);
	}
}

int dis(int u, int v) {
	return d[u] + d[v] - 2 * d[LCA(u, v)];
}

int stat[MAXN];
int st;

void dp(int u, int fa) {
	int ch = dis(st, u) % 2;
	if (siz[u] == 1) {
		stat[u] = !ch;
		return;
	}
	bool ok = 0;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dp(v, u);
		if (stat[v] == ch) ok = 1;
	}
	if (ok) stat[u] = ch;
	else stat[u] = !ch;
}

signed main() {
	n = read(), t = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	st = read();
	dfs1(1, 1, 1);
	dfs2(1, 1);
	dfs3(1, 1);
	dp(st, 0);
	if (stat[st]) puts("Hermione");
	else puts("Ron");
	return 0;
}
