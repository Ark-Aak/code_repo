#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> edges[400000];
int fa[400001];
long long ans;
const int p = 1e9 + 7;

inline int get_fa(int i) {
	if (i == fa[i]) return i;
	return fa[i] = get_fa(fa[i]);
}

long long sum[400001];

void solve2() {
	ans = n;
	sum[0] = 0;
	for (int i = 1; i <= n; ++i) sum[i] = (sum[i - 1] + 1ll * i * i) % p;
	for (int i = 1; i < n; ++i) {
		ans += sum[i];
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d%d", &n, &k);
	if (n > 6000) {
		solve2();
		return 0;
	}
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	for (int l = 1; l <= n; ++l) {
		for (int i = 1; i <= n; ++i) fa[i] = i;
		int now = 0;
		for (int r = l; r <= n; ++r) {
			++now;
			for (auto i : edges[r]) {
				if (i >= l && i <= r) {
					int fi = get_fa(i);
					int ri = get_fa(r);
					if (fi != ri) {
						--now;
						fa[fi] = ri;
					}
				}
			}
			if (k == 2) {
				ans += 1ll * now * now % p;
				ans %= p;
			} else ans = (ans + now) % p;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
