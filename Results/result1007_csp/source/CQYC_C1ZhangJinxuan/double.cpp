#include <bits/stdc++.h>
using namespace std;

int n, x, y;
long long w[100001], a, b;
struct Edge {
	long long l;
	int to;
	bool operator < (const Edge &e) const {
		if (l != e.l) return l < e.l;
		else return to < e.to;
	}
};
vector<Edge> edges[100001];
long long dist[2001][2001];
set<Edge> q;
long long dij(int st, int en) {
	if (dist[st][en] != dist[0][0]) return dist[st][en];
	dist[st][st] = 0;
	q.clear();
	for (int i = 1; i <= 2 * n; ++i) {
		q.insert({dist[st][i], i});
	}
	while (!q.empty()) {
		Edge fx = *(q.begin()); q.erase(fx);
		for (auto i : edges[fx.to]) {
			if (dist[st][fx.to] != dist[0][0] && dist[st][fx.to] + i.l < dist[st][i.to]) {
				q.erase({dist[st][i.to], i.to});
				dist[st][i.to] = dist[st][fx.to] + i.l;
				q.insert({dist[st][i.to], i.to});
			}
		}
	}
	return dist[st][en];
}
int main() {
	freopen("double.in", "r", stdin);
	freopen("double.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &w[i]);
		edges[2 * i - 1].push_back({w[i], 2 * i});
		edges[2 * i].push_back({w[i], 2 * i - 1});
	}
	for (int i = 1; i < n ;++i) {
		scanf("%d%d%lld%lld", &x, &y, &a, &b);
		edges[x * 2 - 1].push_back({a, y * 2 - 1});
		edges[y * 2 - 1].push_back({a, x * 2 - 1});
		edges[x * 2].push_back({b, y * 2});
		edges[y * 2].push_back({b, x * 2});
	}
	memset(dist, 125, sizeof(dist));
	int q; scanf("%d", &q);
	while (q--)
		scanf("%d%d", &x, &y),
		printf("%lld\n", dij(x, y));
	return 0;
}
/*
5 3 6 15 4 8 1 2 5 4 2 3 5 7 1 4 1 5 1 5 2 1 3 1 2 5 6 1 10
 */
