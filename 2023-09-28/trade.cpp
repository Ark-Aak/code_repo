#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

const int MAXN = 1e3 + 5;
int n, m, w[MAXN], maxw, ans, c;
vector <int> G[MAXN], G2[MAXN];
int f[MAXN][MAXN], e[MAXN][MAXN];
int dis[MAXN];
// 2x + 1

void dfs(int step, int x, int sumv, int sumw) {
	if (sumw < sumv) return;
	if (x == 1) ans = max(ans, sumw - sumv);
	for (auto v : G[x]) {
		dfs(step + 1, v, c * ((step + 1) * (step + 1)), sumw + w[v]);
	}
}

void bfs() {
	queue <int> q;
	q.push(1);
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (auto v : G[t]) if (dis[v] == 0 && v != 1) dis[v] = dis[t] + 1, q.push(v);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("trade.in", "r", stdin);
	freopen("trade.out", "w", stdout);
#endif
#endif
	cin >> n >> m >> c;
	rep (i, 1, n) cin >> w[i], maxw = max(maxw, w[i]);
	rep (i, 1, m) {
		int u, v;
		cin >> u >> v;
		e[u][v] = 1;
		G[u].emplace_back(v);
		G2[v].emplace_back(u);
	}
	if (n <= 200) {
		dfs(0, 1, 0, 0);
		cout << ans;
		return 0;
	}
	bfs();
	rep (t, 1, MAXN - 4) {
		rep (j, 1, n) {
			if (dis[j] > t) continue;
			for (auto v : G2[j]) {
				f[t][j] = max(f[t][j], f[t - 1][v] + w[j]);
			}
			f[t][j] -= 2 * t - 1;
		}
	}
	rep (i, 1, MAXN - 4) ans = max(ans, f[i][1]);
	cout << ans;
	return 0; 
}
