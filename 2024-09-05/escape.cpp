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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 5e4 + 5;
int B, n, m, a[MAXN];
vector <int> G[MAXN];
int bel[MAXN], vis[MAXN], ans;
int siz[MAXN], son[MAXN], dep[MAXN], fa[MAXN];
int top[MAXN], dfn[MAXN], _dfn;

struct comp {

	bool operator()(const int a, const int b) const {
		return dfn[::a[a]] < dfn[::a[b]];
	}
};

set <int, comp> s;

void dfs0(int u, int f) {
	siz[u] = 1;
	fa[u] = f;
	dep[u] = dep[f] + 1;
	dfn[u] = ++_dfn;
	for (auto v : G[u]) {
		if (v == f) continue;
		dfs0(v, u);
		if (siz[son[u]] < siz[v]) son[u] = v;
	}
}

void dfs1(int u, int tp) {
	top[u] = tp;
	if (!son[u]) return;
	dfs1(son[u], tp);
	for (auto v : G[u]) {
		if (v == fa[u] || v == son[u]) continue;
		dfs1(v, v);
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

struct Query {
	int l, r, id;
} q[MAXN];

int ql = 1, qr = 0;

void update(int pos, int val) {
	vis[pos] += val;
	if (val == 1 && vis[pos] == 1) ans++;
	if (val == -1 && vis[pos] == 0) ans--;
}

int fans[MAXN];

void rebuild(int l, int r) {
	ans = 0;

}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("escape.in", "r", stdin);
	freopen("escape.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	B = sqrt(n);
	rep (i, 1, n) bel[i] = (i - 1) / B + 1;
	rep (i, 2, n) {
		int fa = read();
		G[fa].push_back(i);
		G[i].push_back(fa);
	}
	rep (i, 1, n) a[i] = read();
	rep (i, 1, m) {
		q[i].l = read(), q[i].r = read();
		q[i].id = i;
	}
	dfs0(1, 0);
	dfs1(1, 1);
	sort(q + 1, q + 1 + m, [](Query a, Query b) {
		return bel[a.l] != bel[b.l] ? bel[a.l] < bel[b.l] : a.r > b.r;
	});
	int lst = 0;
	rep (i, 1, m) {
		Query x = q[i];
		if (bel[q[i].l] != lst) {
			lst = bel[q[i].l];
			rebuild(B * (bel[q[i].l] - 1) + 1, n);
		}
		fans[x.id] = ans;
	}
	rep (i, 1, m) print(fans[i]), puts("");
	return 0;
}
