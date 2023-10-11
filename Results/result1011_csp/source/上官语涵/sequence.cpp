#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mxn = 5010;
const int mxm = 5010;
int dp[mxn][mxm], sum[mxn];
const int Mod = 998244353;
signed main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout); 
	int n, m;
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= m; i++) dp[1][i] = 1, sum[1] = (sum[1] + dp[1][i]) % Mod;
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			dp[i][j] = (dp[i][j] + sum[i - 1]) % Mod;
			for(int k = 2; k * j <= m; k++) dp[i][j] = (dp[i][j] - dp[i - 1][k * j] + Mod) % Mod;
			sum[i] = (sum[i] + dp[i][j]) % Mod;
		}
	}
	printf("%lld", sum[n] % Mod);
}

