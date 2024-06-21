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

const int MAXN = 3e5 + 5;
int n, m;
int a[MAXN], b[MAXN];
vector <int> G[MAXN];

int d[MAXN], ch[50], ach[50];
int vis0[MAXN], vis1[MAXN];
int ans = 1e9;
int siz[MAXN], fa[MAXN], hs[MAXN];
int top[MAXN], dep[MAXN];

void dfs0(int u, int f) {
	fa[u] = f;
	siz[u] = 1;
	for (auto v : G[u]) {
		if (v == f) continue;
		dep[v] = dep[u] + 1;
		d[v] = d[u] + 1;
		dfs0(v, u);
		siz[u] += siz[v];
		if (siz[hs[u]] < siz[v]) hs[u] = v;
	}
}

void dfs1(int u, int tp) {
	top[u] = tp;
	if (!hs[u]) return;
	dfs1(hs[u], tp);
	for (auto v : G[u]) {
		if (v == fa[u] || v == hs[u]) continue;
		dfs1(v, v);
	}
}

int LCA(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[u] < dep[v]) swap(u, v);
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}

int dis(int u, int v) {
	return d[u] + d[v] - d[LCA(u, v)] * 2;
}

void calc(int step, int u, int sum) {
	if (sum >= ans) return;
	if (step > 2 * m) {
		if (u != 1) sum += dis(u, 1);
		if (sum >= ans) return;
		ans = min(ans, sum);
		rep (i, 1, 2 * m) ach[i] = ch[i];
		return;
	}
	rep (i, 1, m) {
		ch[step] = i;
		if (step & 1) {
			if (vis0[i]) continue;
			vis0[i] = 1;
			calc(step + 1, a[i], sum + dis(u, a[i]));
			vis0[i] = 0;
		}
		else {
			if (vis1[i]) continue;
			vis1[i] = 1;
			calc(step + 1, b[i], sum + dis(u, b[i]));
			vis1[i] = 0;
		}
	}
}

void solve() {
	dfs0(1, 0); dfs1(1, 1);
	calc(1, 1, 0);
	print(ans), puts("");
	rep (i, 1, 2 * m) print(ach[i]), putchar(32);
	puts("");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, m) a[i] = read();
	rep (i, 1, m) b[i] = read();
	rep (i, 1, n - 1) {
		int x = read(), y = read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	solve();
	return 0;
}
