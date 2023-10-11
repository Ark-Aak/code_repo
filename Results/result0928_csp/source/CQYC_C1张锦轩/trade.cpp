#include <bits/stdc++.h>
using namespace std;

int n, m, c, x, y;
vector<int> edges[1001];
vector<int> redge[1001];
long long f[3001][1001], w[1001];
// f[day][city];

int main() {
	freopen("trade.in", "r", stdin);
	freopen("trade.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &c);
	memset(f, 128, sizeof(f));
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &w[i]);
	}
	f[0][1] = 0;
	while (m--) {
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		redge[y].push_back(x);
	}
	for (int day = 1; day <= 3000; ++day) {
		for (int city = 1; city <= n; ++city) {
			for (auto j : redge[city]) {
				if (f[day - 1][j] != f[0][0])
					f[day][city] = max(f[day][city], f[day - 1][j] + w[j] - 1ll * (day + day - 1) * c);
			}
		}
	}
	long long ans = 0;
	for (int day = 0; day <= 3000; ++day) {
		ans = max(ans, f[day][1]);
	}
	printf("%lld\n", ans);
	return 0;
}
