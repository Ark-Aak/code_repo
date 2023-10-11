#include<bits/stdc++.h>
#define int long long
#define N 500
using namespace std;
int n, K, ans = 1e15;
int a[N], f[N][N], sum[N];
signed main() {
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
	cin >> n >> K;
	K++;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= K; j++)
			f[i][j] = 1e15;
	
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for(int k = 1; k <= K; k++) {
		for(int i = 1; i <= n; i++) {
		    int maxn = 0;
			for(int j = i; j >= 1; j--) { // [j,i]划分成一段
				maxn = max(maxn, a[j]);
				f[i][k] = min(f[i][k], f[j - 1][k - 1] + maxn * (i - j + 1) - (sum[i] - sum[j - 1]));
				
			}
			//printf("f[%lld][%lld]=%lld\n",i,k,f[i][k]);
		}
	}
	for(int i = 1; i <= K; i++) ans = min(ans, f[n][i]);
	cout << ans << endl;
	return 0;
}
/*
  6 2
  7 9 8 2 3 2

 */
