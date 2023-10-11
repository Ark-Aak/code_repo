#include<bits/stdc++.h>
#define int long long
using namespace std;

int ans, dp[510][510][510], a[510], qz[510];
const int Mod = 998244353;
signed main() {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++) cin >> a[i];
	for(int i = 1; i <= m; i++) {
		dp[1][i][1] = 1;
		qz[i] = (qz[i - 1] + dp[1][i][1]) % Mod;
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			for(int k = 1; k <= min(a[j], i); k++) {
				if(k == 1) dp[i][j][k] = (qz[m] - qz[j] + qz[j - 1]) % Mod;
				else dp[i][j][k] = dp[i - 1][j][k - 1] % Mod;
			}
		}
		memset(qz, 0, sizeof(qz));
		for(int j = 1; j <= m; j++) {
			for(int k = 1; k <= a[j]; k++) {
				qz[j] = (qz[j] + dp[i][j][k]) % Mod;
			}
			qz[j] = (qz[j] + qz[j - 1]) % Mod;
		}
	}
	int ans = 0;
	for(int j = 1; j <= m; j++) {
		for(int k = 1; k <= a[j]; k++) {
			ans = (ans + dp[n][j][k]) % Mod;
		}
	}
	cout << ans % Mod;
}
