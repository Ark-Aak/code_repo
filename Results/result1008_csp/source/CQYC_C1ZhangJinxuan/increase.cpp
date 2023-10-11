#include <bits/stdc++.h>
using namespace std;

int n, m, u, v, w;
struct Edge {
	int to, l;
	bool operator < (const Edge &e) const {
		return l < e.l;
	}
};
vector<Edge> edges[200001];

int f[5001][5001][2];

int dfs(int i, int w, bool who) {
	if (f[i][w][who] != -1) return f[i][w][who];
	int ans = -1, ans1 = 1ll << 30, have = 0;
	for (auto j : edges[i]) {
		if (j.l > w) {
			if (who == 1) {
				ans = max(ans, dfs(j.to, j.l, 0));
			} else {
				ans1 = min(ans1, dfs(j.to, j.l, 1));
			}
			have = 1;
		}
	}
	if (have == 0) {
		return 0;
	} else {
		if (who == 1) return f[i][w][who] = ans + 1;
		else return f[i][w][who] = ans1 + 1;
	}
}

int main() {
	freopen("increase.in", "r", stdin);
	freopen("increase.out", "w",stdout);
	memset(f, 255, sizeof(f));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		edges[u].push_back({v, w});
		edges[v].push_back({u, w});
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d " ,dfs(i, 0, 1));
	}
	return 0;
}
