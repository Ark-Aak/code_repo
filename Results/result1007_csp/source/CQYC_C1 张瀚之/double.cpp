#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll n, q;
vector<pair<long long, long long> > edge[5005];
long long dis[5005][5005];

int main() {
	freopen("double.in", "r", stdin);
	freopen("double.out", "w", stdout);
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		long long x;
		scanf("%lld", &x);
		edge[i * 2 - 1].push_back(make_pair(i * 2, x));
		edge[i * 2].push_back(make_pair(i * 2 - 1, x));
	}
	for (ll i = 1; i < n; i++) {
		ll u, v;
		ll w1, w2;
		scanf("%lld%lld%lld%lld", &u, &v, &w1, &w2);
		edge[u * 2 - 1].push_back(make_pair(v * 2 - 1, w1));
		edge[v * 2 - 1].push_back(make_pair(u * 2 - 1, w1));
		edge[u * 2].push_back(make_pair(v * 2, w2));
		edge[v * 2].push_back(make_pair(u * 2, w2));
	}
	for (ll i = 1; i <= n; i++) {
		bool vis[5005];
		memset(vis, 0, sizeof(vis));
		memset(dis[i], 0x3f, sizeof dis[i]);
		priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > q;
		while (!q.empty()) q.pop();
		dis[i][i] = 0;
		q.push(make_pair(dis[i][i], i));
		while (!q.empty()) {
			ll u = q.top().second;
			q.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			for (auto it: edge[u])
				if (dis[i][it.first] > dis[i][u] + it.second) {
					dis[i][it.first] = dis[i][u] + it.second;
					q.push(make_pair(dis[i][it.first], it.first));
				}
		}
	}
	scanf("%lld", &q);
	while (q--) {
		ll u, v;
		scanf("%lld%lld", &u, &v);
		printf("%lld\n", dis[u][v]);
	}
	return 0;
}
