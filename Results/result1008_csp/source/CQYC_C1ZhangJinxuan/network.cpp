#include <bits/stdc++.h>
using namespace std;

int n, q, x, y, f[21][1000001], f2[21][1000001], d[1000001], lca = -1, tmp = 1ll << 30;
vector<int> edges[1000001];
char opt[12];

pair<int, int> glca(int x, int y) {
	if (x == y) return make_pair(x, f2[0][x]);
	if (d[x] < d[y]) swap(x, y);
	int step = d[x] - d[y], ans = 1 << 30;
	ans = min(f2[0][x], f2[0][y]);
	for (int l = 0; step; ++l, step >>= 1) {
		if (step & 1) {
			ans = min(ans, f2[l][x]);
			x = f[l][x];
		}
	}
	//printf("tmp: %d\n", x);
	ans = min(ans, f2[0][x]);
	if (x == y) {
		return make_pair(x, ans);
	}
	for (int l = 20; l != -1; --l) {
		if (f[l][x] != f[l][y] && f[l][x] != 0) {
			ans = min(ans, f2[l][x]);
			ans = min(ans, f2[l][y]);
			x = f[l][x];
			y = f[l][y];
		}
	}
	ans = min(ans, f2[0][x]);
	ans = min(ans, f2[0][y]);
	x = f[0][x];
	y = f[0][y];
	ans = min(ans, f2[0][x]);
	ans = min(ans, f2[0][y]);
	return make_pair(x, ans);
}


void dfs(int i) {
	for (auto j : edges[i]) {
		if (!d[j]) {
			d[j] = d[i] + 1;
			f[0][j] = i;
			dfs(j);
		}
	}
}

int main() {
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	memset(f2, 125, sizeof(f2));
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; ++i) {
		scanf("%d%d", &x, &y);
		f2[0][x] = x;
		f2[0][y] = y;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	d[1] = 1;
	dfs(1);
	for (int j = 1; j <= 20; ++j) {
		for (int i = 1; i <= n; ++i) {
			f[j][i] = f[j - 1][f[j - 1][i]];
			f2[j][i] = min(f2[j - 1][i], f2[j - 1][f[j - 1][i]]);
		}
	}
	while (q--) {
		scanf("%s%d", opt + 1, &x);
		if (opt[1] == 'Q') {
			printf("%d\n", min(tmp, glca(x, lca).second));
		} else {
			if (lca == -1) lca = x;
			lca = glca(lca, x).first;
			tmp = min(glca(lca, x).second, tmp);
		}
	}
	return 0;
}
