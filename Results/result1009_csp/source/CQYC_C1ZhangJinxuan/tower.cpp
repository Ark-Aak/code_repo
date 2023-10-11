#include <bits/stdc++.h>
using namespace std;

int n, k, a[50001];
char s[52][52];
long long d[50001];
vector<int> edgec[51], colors[51];
struct Info {
	long long l;
	int to;
	bool operator < (const Info &i) const {
		if (l != i.l) return l < i.l;
		else return to < i.to;
	}
};
set<Info> q;

int main() {
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), colors[a[i]].push_back(i);
	for (int i = 1; i <= k; ++i) {
		scanf("%s", s[i] + 1);
		for (int j = 1; j <= k; ++j) {
			if (s[i][j] == '1') edgec[i].push_back(j);
		}
	}
	memset(d, 125, sizeof(d));
	d[1] = 0;
	for (int i = 1; i <= n; ++i) q.insert({d[i], i});
	while (!q.empty()) {
		Info fx = *(q.begin()); q.erase(fx);
		for (auto i : edgec[a[fx.to]]) {
			for (auto j : colors[i]) {
				int dis = abs(fx.to - j);
				if (d[fx.to] + dis < d[j]) {
					q.erase({d[j], j});
					d[j] = d[fx.to] + dis;
					q.insert({d[j], j});
				}
			}
		}
	}
	if (d[n] == d[0]) puts("-1");
	else printf("%lld\n", d[n]);
	return 0;
}
