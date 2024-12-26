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

const int MAXN = 3e5 + 5;
int n, k;
vector <int> G[MAXN][4];

namespace subtask1 {

	const int MAXS = 3005;
	int ans[MAXS][MAXS][4];
	int vis[MAXS], ptr = 0;

	void solve_tree(int u, int fa, int o, int id) {
		vis[u] = 1;
		int tp = ptr;
		while (vis[ptr]) ptr++;
		ans[o][u][id] = ans[u][o][id] = ptr;
		for (auto v : G[u][id]) {
			if (v == fa) continue;
			solve_tree(v, u, o, id);
		}
		vis[u] = 0;
		ptr = tp;
	}

	void solve() {
		rep (i, 1, k) rep (j, 0, n - 1) solve_tree(j, -1, j, i);
		ll an = 0;
		rep (i, 0, n - 1) {
			rep (j, 0, n - 1) {
				int res = 0;
				rep (d, 1, k) res = max(res, ans[i][j][d]);
				an += res;
			}
		}
		print(an), puts("");
	}

} // namespace subtask1

namespace subtask2 {

	vector <int> G[MAXN];
	int siz[MAXN], dep[MAXN], top[MAXN];
	int son[MAXN], fa[MAXN], dfn[MAXN], cnt, flg[MAXN];

	void dfs0(int u, int f) {
		siz[u] = 1;
		dep[u] = dep[f] + 1;
		fa[u] = f;
		son[u] = -1;
		flg[u] = u == 1;
		for (auto v : G[u]) {
			if (v == f) continue;
			dfs0(v, u);
			flg[u] |= flg[v];
			if (siz[v] > siz[son[u]]) son[u] = v;
		}
	}

	void dfs1(int u, int h) {
		dfn[u] = ++cnt;
		top[u] = h;
		if (son[u] == -1) return;
		dfs1(son[u], h);
		for (auto v : G[u]) {
			if (v == son[u] || v == fa[u]) continue;
			dfs1(v, v);
		}
	}

	int LCA(int u, int v) {
		while (top[u] != top[v]) {
			if (dep[u] < dep[v]) swap(u, v);
			u = fa[top[u]];
		}
		if (dep[u] > dep[v]) return v;
		else return u;
	}

	bool isAncestor(int anc, int x) {
		return LCA(anc, x) == anc;
	}

	void solve() {
		rep (i, 1, n) G[i].swap(::G[i][1]);
		dfs0(0, -1);
		dfs1(0, 0);
		int ldep = 0, rdep = 0, lca = 0;
		ll ans = 0;

		rep (i, 1, n - 1) {
			int ban = i + 1;
		}
	}

} // namespace subtask2

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("cute.in", "r", stdin);
	freopen("cute.out", "w", stdout);
#endif
#endif
	n = read(), k = read();
	rep (i, 1, k) {
		rep (j, 1, n - 1) {
			int u = read(), v = read();
			G[u][i].push_back(v);
			G[v][i].push_back(u);
		}
	}
	if (n <= 3000) return subtask1::solve(), 0;
	else if (k == 1) return subtask2::solve(), 0;
	return 0;
}
