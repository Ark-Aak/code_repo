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

#define int ll

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

const int MAXN = 2e5 + 5;
const int MOD = (1ll << 32) - 1;
int n, q;
vector <pii> G[MAXN];

namespace Subtask124 {

	int dis[MAXN], dep[MAXN], fa[MAXN], top[MAXN], son[MAXN], siz[MAXN];
	int dfn[MAXN], cnt = 0;

	void dfs0(int u, int f) {
		fa[u] = f;
		dep[u] = dep[f] + 1;
		siz[u] = 1;
		for (auto [v, w] : G[u]) {
			if (v == f) continue;
			dis[v] = dis[u] + w;
			dfs0(v, u);
			siz[u] += siz[v];
			if (siz[v] > siz[son[u]]) son[u] = v;
		}
	}

	void dfs1(int u, int h) {
		top[u] = h;
		dfn[u] = ++cnt;
		if (!son[u]) return;
		dfs1(son[u], h);
		for (auto [v, w] : G[u]) {
			if (v == son[u] || v == fa[u]) continue;
			dfs1(v, v);
		}
	}

	int LCA(int u, int v) {
		while (top[u] != top[v]) {
			if (dep[top[u]] < dep[top[v]]) swap(u, v);
			u = fa[top[u]];
		}
		return dep[u] < dep[v] ? u : v;
	}

	vector <int> T;
	vector <pii> VG[MAXN];

	int calc(int u, int v) {
		return (dis[u] + dis[v] - 2 * dis[LCA(u, v)]) & MOD;
	}

	int ans = 0, nsiz[MAXN], L, R;

	void dfs2(int u, int fa) {
		nsiz[u] = (L <= u) && (u <= R);
		for (auto [v, w] : VG[u]) {
			if (v == fa) continue;
			dfs2(v, u);
			nsiz[u] += nsiz[v];
		}
	}

	void dfs3(int u, int fa) {
		for (auto [v, w] : VG[u]) {
			if (v == fa) continue;
			int ts = ((((R - L + 1) - nsiz[v]) * nsiz[v]) & MOD) * w;
			ts &= MOD;
			ans = (ans + ts) & MOD;
			dfs3(v, u);
		}
	}

	void solve() {
		dfs0(1, 0);
		dfs1(1, 1);
		while (q --> 0) {
			int l = read(), r = read();
			L = l, R = r;
			for (auto v : T) VG[v].clear();
			T.clear();
			vector <int> val;
			rep (i, l, r) val.push_back(i);
			sort(val.begin(), val.end(), [](int a, int b) { return dfn[a] < dfn[b]; });
			auto add = [&](int a, int b) {
				if (a == b) return;
				VG[a].emplace_back(b, calc(a, b));
				VG[b].emplace_back(a, calc(a, b));
			};
			for (auto v : val) T.push_back(v);
			rep (i, 0, ((int) val.size()) - 2) T.push_back(LCA(val[i], val[i + 1]));
			sort(T.begin(), T.end());
			T.erase(unique(T.begin(), T.end()), T.end());
			sort(T.begin(), T.end(), [](int a, int b) { return dfn[a] < dfn[b]; });
			rep (i, 0, ((int) T.size()) - 2) {
				const int lca = LCA(T[i], T[i + 1]);
				add(T[i + 1], lca);
			}
			dfs2(T[0], 0);
			ans = 0;
			dfs3(T[0], 0);
			print(ans), puts("");
		}
	}

} // namespace Subtask124

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("memory.in", "r", stdin);
	freopen("memory.out", "w", stdout);
#endif
#endif
	n = read(), q = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read(), w = read();
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
	Subtask124::solve();
	return 0;
}
