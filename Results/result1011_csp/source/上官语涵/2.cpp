#include<bits/stdc++.h>
#include<ctime>
#define int long long
using namespace std;

const int mxn = 2010;
const int mxm = 2010;
int dp[mxn][mxm], sum[mxn], a[mxn][mxm];
const int Mod = 998244353;
signed main() {
//	freopen("sequence.in", "r", stdin);
//	freopen("sequence.out", "w", stdout); 
	int n, m;
	scanf("%lld%lld", &n, &m);
	float time_st = clock() / float(CLOCKS_PER_SEC);
	for(int i = 1; i <= m; i++) {
		dp[1][i] = 1;
		sum[1] = (sum[1] + dp[1][i]) % Mod;
		for(int k = 1; k * k <= i; k++) {
			if(i % k == 0) {
				a[1][k] = (a[1][k] + dp[1][i]) % Mod;
				if(i / k != k) a[1][i / k] = (a[1][i / k] + dp[1][i]) % Mod;
			}
		}
	}
	for(int i = 2; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			dp[i][j] = (dp[i][j] + sum[i - 1]) % Mod;
			dp[i][j] = ((dp[i][j] - a[i - 1][j] + Mod) % Mod + dp[i - 1][j]) % Mod;
			for(int k = 1; k * k <= j; k++) {
				if(j % k == 0) {
					a[i][k] = (a[i][k] + dp[i][j]) % Mod;
					if(j / k != k) a[i][j / k] = (a[i][j / k] + dp[i][j]) % Mod; 
				}
			}
			sum[i] = (sum[i] + dp[i][j]) % Mod;
		}
	}
	float time_en = clock() / float(CLOCKS_PER_SEC);
	cout << time_en - time_st << endl;
	printf("%lld", sum[n] % Mod);
}
