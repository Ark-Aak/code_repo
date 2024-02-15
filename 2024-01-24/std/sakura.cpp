#include <bits/stdc++.h>
void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for (int &x : a) {
		std::cin >> x;
		x--;
	}

	std::vector<std::vector<int>> G(n);
	for (int i = 0, u, v; i < m; i++) {
		std::cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	int dfs_clock = 0;
	std::vector<int> low(n), dfn(n, -1), stk;
	std::vector<std::vector<int>> H(n);
	auto Tarjan = [&](auto self, int u) -> void {
		low[u] = dfn[u] = dfs_clock++;
		stk.push_back(u);
		for (int v : G[u]) {
			if (dfn[v] == -1) {
				self(self, v);
				low[u] = std::min(low[u], low[v]);
				if (low[v] == dfn[u]) {
					int c = H.size();
					H.emplace_back();
					stk.push_back(u);
					while (true) {
						int x = stk.back();
						stk.pop_back();
						H[c].push_back(x);
						H[x].push_back(c);
						if (x == v) {
							break;
						}
					}
				}
			} else {
				low[u] = std::min(low[u], dfn[v]);
			}
		}
	};

	Tarjan(Tarjan, 0);

	std::vector<int> dep(H.size());
	std::vector<std::array<int, 20>> anc(H.size());
	auto dfs = [&](auto self, int u, int p) -> void {
		anc[u][0] = p;
		for (int i = 1; i < 20; i++) {
			anc[u][i] = anc[anc[u][i - 1]][i - 1];
		}
		for (int v : H[u]) {
			if (v != p) {
				dep[v] = dep[u] + 1;
				self(self, v, u);
			}
		}
	};

	dfs(dfs, 0, 0);

	auto lca = [&](int u, int v) {
		if (dep[u] < dep[v]) {
			std::swap(u, v);
		}
		for (int i = 20; i--; ) {
			if (dep[anc[u][i]] >= dep[v]) {
				u = anc[u][i];
			}
		}
		if (u == v) {
			return u;
		}
		for (int i = 20; i--; ) {
			if (anc[u][i] != anc[v][i]) {
				u = anc[u][i], v = anc[v][i];
			}
		}
		return anc[u][0];
	};

	auto dist = [&](int u, int v) {
		return dep[u] + dep[v] - 2 * dep[lca(u, v)];
	};

	auto on_path = [&](int u, int s, int t) {
		return u != s && u != t && dist(s, u) + dist(u, t) == dist(s, t);
	};

	std::queue<int> Q;
	std::vector<int> ans(n, -1);
	auto push = [&](int x, int v) {
		if (ans[x] == -1) {
			ans[x] = v;
			Q.push(x);
		}
	};

	for (int u = 0; u < n; u++) {
		if (a[u] == u) {
			push(u, 0);
		}
	}

	for (int u = 0; u < n; u++) {
		for (int v : G[u]) {
			if (a[u] == v || on_path(v, a[u], a[v])) {
				push(u, 1);
			}
		}
	}

	while (Q.size()) {
		int u = Q.front();
		Q.pop();
		for (int v : G[u]) {
			push(v, ans[u] + 1);
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << ans[i] << " \n"[i == n - 1];
	}
}

int main() {
	freopen("sakura.in", "r", stdin);
	freopen("sakura.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}
