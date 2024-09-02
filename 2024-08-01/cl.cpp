#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <bits/extc++.h>

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define ec first
#define fb second
#define de(x) cerr << #x << " = " << (x) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, w = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + (ch ^ 48);
		ch = getchar();
	}
	return x * w;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

const int MAXN = 505;
const int MOD = 1e9 + 7;
int dp[MAXN][MAXN], n;
int ans[MAXN][MAXN];
vector <int> G[MAXN];

void dfs0(int u, int fa) {
	dp[u][1] = 1;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs0(v, u);
		int tmp[MAXN] = {0};
		rep (i, 1, n) {
			rep (j, 1, n - i) {
				tmp[i + j] += 1ll * dp[u][i] * dp[v][j] % MOD;
				tmp[i + j] %= MOD;
			}
		}
		rep (i, 1, n) dp[u][i] = (dp[u][i] + tmp[i]) % MOD;
	}
}

void change0(int u, int fa) {
	rep (i, 1, n) dp[u][i] = 0;
	dp[u][1] = 1;
	for (auto v : G[u]) {
		if (v == fa) continue;
		int tmp[MAXN] = {0};
		rep (i, 1, n) {
			rep (j, 1, n - i) {
				tmp[i + j] += 1ll * dp[u][i] * dp[v][j] % MOD;
				tmp[i + j] %= MOD;
			}
		}
		rep (i, 1, n) dp[u][i] = (dp[u][i] + tmp[i]) % MOD;
	}
}

inline void change1(int u, int v) {
	int tmp[MAXN] = {0};
	rep (i, 1, n) {
		rep (j, 1, n - i) {
			tmp[i + j] += 1ll * dp[u][i] * dp[v][j] % MOD;
			tmp[i + j] %= MOD;
		}
	}
	rep (i, 1, n) dp[u][i] = (dp[u][i] + tmp[i]) % MOD;
}

int fans[MAXN][MAXN][MAXN];

inline void update(int u, int v) {
	rep (i, 1, n / 2) {
		fans[u][v][i] = (fans[u][v][i] + 1ll * dp[u][i] * dp[v][i] % MOD) % MOD;
	}
}

void dfs1(int root, int fa) {
	rep (i, 1, n) ans[root][i] = dp[root][i];
	for (auto v : G[root]) {
		if (v == fa) continue;
		int backup_u[MAXN], backup_v[MAXN];
		rep (i, 1, n) backup_u[i] = dp[root][i];
		rep (i, 1, n) backup_v[i] = dp[v][i];
		change0(root, v);
		update(root, v);
		change1(v, root);
		dfs1(v, root);
		rep (i, 1, n) dp[root][i] = backup_u[i];
		rep (i, 1, n) dp[v][i] = backup_v[i];
	}
}

vector <pii> edges;

int nwans[MAXN];

signed main() {
#ifndef LOCAL
	ignore = freopen("cl.in", "r", stdin);
	ignore = freopen("cl.out", "w", stdout);
#endif
	n = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
		edges.push_back(dl(u, v));
	}
	dfs0(1, 0);
	dfs1(1, 0);
	for (auto [u, v] : edges) {
		rep (i, 1, n) nwans[i] = (nwans[i] + fans[u][v][i]) % MOD;
	}
	rep (i, 1, n / 2) print(nwans[i]), putchar(32);
	puts("");
	return 0;
}
