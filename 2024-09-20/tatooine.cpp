#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define int ll

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

const int MAXN = 8e5 + 5;
int n;
vector <pii> G[MAXN];
int f[MAXN][22], g[MAXN][22], tot;

void dfs0(int u, int fa) {
	f[u][20] = 1;
	for (auto [v, w] : G[u]) {
		if (v == fa) continue;
		dfs0(v, u);
		rep (i, 1, 20) f[u][min(w, i)] += f[v][i];
	}
}

map <pair <int, int>, int> ans;

void dfs1(int u, int fa) {
	rep (i, 1, 20) g[u][i] = f[u][i], tot += f[u][i] * i;
	tot -= 20;
	for (auto [v, w] : G[u]) {
		if (v == fa) continue;
		rep (i, 1, 20) f[u][min(w, i)] -= f[v][i];
		rep (i, 1, 20) f[v][min(w, i)] += f[u][i];
		dfs1(v, u);
		rep (i, 1, 20) f[v][min(w, i)] -= f[u][i];
		rep (i, 1, 20) f[u][min(w, i)] += f[v][i];
	}
}

void dfs2(int u, int fa) {
	// cout << "u:" << u << ":";
	// rep (i, 1, 20) {
		// cout << f[u][i] << " ";
	// }
	// cout << endl;
	// cout << "fa:" << fa << ":";
	// rep (i, 1, 20) {
		// cout << f[fa][i] << " ";
	// }
	// cout << endl;
	if (fa != 0) {
		int pre[22] = { 0 };
		int res = 0, faw = 0;
		for (auto [v, w] : G[u]) {
			if (v == fa) {
				faw = w;
				break;
			}
		}
		int sum[22] = { 0 };
		rep (i, 1, 20) sum[i] = sum[i - 1] + i * f[u][i];
		int suf[22] = { 0 };
		_rep (i, 20, 1) suf[i] = suf[i + 1] + f[u][i];
		// rep (i, 1, 20) rep (j, 1, 20) res += min(faw, min(i, j)) * f[fa][i] * f[u][j];
		rep (i, 1, 20) {
			int bound = min(faw, i);
			// j <= bound
			res += f[fa][i] * sum[bound];
			// j > bound
			res += f[fa][i] * bound * suf[bound + 1];
		}
		ans[dl(u, fa)] = ans[dl(fa, u)] = tot - res;
		// cout << "res:" << res << endl;
		// cout << "edge:" << u << " " << fa << endl;
		// cout << tot - res << endl;
		rep (i, 1, 20) f[u][min(faw, i)] += f[fa][i];
	}
	for (auto [v, w] : G[u]) {
		if (v == fa) continue;
		// cout << "changing:";
		// rep (i, 1, 20) cout << f[v][i] << " ";
		// cout << endl;
		rep (i, 1, 20) f[u][min(w, i)] -= f[v][i];
		dfs2(v, u);
		rep (i, 1, 20) f[v][min(w, i)] -= f[u][i];
		rep (i, 1, 20) f[u][min(w, i)] += f[v][i];
	}
}

vector <pii> edges;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tatooine.in", "r", stdin);
	freopen("tatooine.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read(), w = read();
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
		edges.push_back(dl(u, v));
	}
	dfs0(1, 0);
	dfs1(1, 0);
	tot /= 2;
	// cout << tot << endl;
	dfs2(1, 0);
	for (auto item : edges) print(ans[item]), puts("");
	return 0;
}
