#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int n, m, ans;
int f[5010][5010], a[50100], g[5010]; //g[i] = f[i][l]
int sum[5010]; // sum[i] = g[1] + g[2] + ... g[i]
int sum2[5010][5010]; //sum2[i][j] = f[1][j] + f[2][j] + ... + f[i][j];
signed main() {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= m; i++) {
    	a[i] = 100000;
		f[1][i] = 1;
		sum2[1][i] = 1;
	} 
    g[1] = m;
    sum[1] = g[1];
    for(int i = 1; i <= m; i++) scanf("%lld", &a[i]);
    for(int i = 2; i <= n; i++) {
    	for(int j = 1; j <= m; j++) {
			int L = max(1ll, i - a[j] + 1), R = i;
			if(L == 1) {
				f[i][j] = (f[i][j] + 1) % mod;
				L++;
			}
			if(L > R) continue;
			f[i][j] = ((f[i][j] + sum[R - 1]) % mod - sum[L - 2] + mod) % mod;
			f[i][j] = (f[i][j] - (sum2[R - 1][j] - sum2[L - 2][j] + mod) % mod + mod) % mod;
			g[i] = (g[i] + f[i][j]) % mod;
			sum2[i][j] = (sum2[i - 1][j] + f[i][j]) % mod;
		}
		sum[i] = (sum[i - 1] + g[i]) % mod;
	}
	for(int i = 1; i <= m; i++) ans = (ans + f[n][i]) % mod;
	printf("%lld", ans);
	return 0;
}
