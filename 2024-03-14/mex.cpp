#include <bits/stdc++.h>

#define int ll

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

const int MAXN = 7005;
int mex[MAXN][MAXN], w[MAXN], dis[MAXN][MAXN];
vector <int> G[MAXN];
int n, f[MAXN];

int vis[MAXN], mx;

void add(int x) {
	vis[x]++;
	while (vis[mx]) mx++;
}

void del(int x) {
	vis[x]--;
	if (!vis[x]) mx = min(x, mx);
}

int ans[MAXN], lca[MAXN][MAXN];
int dep[MAXN];

void dfs1(int u, int fa, int o) {
	add(w[u]);
	mex[o][u] = mx;
	dis[o][u] = dis[o][fa] + 1;
	if (u == o) lca[u][o] = o;
	else {
		if (dep[lca[fa][o]] > dep[u]) lca[u][o] = u;
		else lca[u][o] = lca[fa][o];
	}
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs1(v, u, o);
	}
	del(w[u]);
}

void getdep(int u, int fa) {
	dep[u] = dep[fa] + 1;
	for (auto v : G[u]) {
		if (v == fa) continue;
		getdep(v, u);
	}
}

void toup(int u, int fa) {
	for (auto v : G[u]) {
		if (v == fa) continue;
		toup(v, u);
		ans[u] = max(ans[u], ans[v]);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("mex.in", "r", stdin);
	freopen("mex.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) w[i] = read();
	rep (i, 2, n) {
		int fa = read();
		f[i] = fa;
		G[fa].push_back(i);
		G[i].push_back(fa);
	}
	f[1] = 1;
	getdep(1, 0);
	rep (i, 1, n) dfs1(i, 0, i);
	rep (i, 1, n) {
		rep (j, 1, n) {
			int lca = ::lca[i][j];
			ans[lca] = max(ans[lca], dis[i][j] - mex[i][j]);
		}
	}
	toup(1, 0);
	rep (i, 1, n) print(ans[i]), putchar(32);
	return 0;
}
