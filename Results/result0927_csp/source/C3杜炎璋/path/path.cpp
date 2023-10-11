#include<bits/stdc++.h>
#define int long long
using namespace std;                                                                                                  ;
int a[405];
int sum[405],dp[405][305];
signed main() {
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	int n,K;
	scanf("%lld %lld",&n,&K);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	for(int i=1; i<=n; i++) sum[i]=(sum[i-1]+a[i]);
	for(int i=0; i<=n+1; i++) {
		for(int j=0; j<=K+1; j++) {
			dp[i][j]=1e12;
		}
	}
	dp[0][0]=0;
	for(int i=1; i<=n; i++) {
		int maxn=0;
		for(int j=i; j<=n; j++) {
			maxn=max(maxn,a[j]);
			for(int w=1; w<=K+1; w++) {
				dp[j][w]=min(dp[j][w],dp[i-1][w-1]+maxn*(j-i+1)-(sum[j]-sum[i-1]));
			}
		}
	}
	printf("%lld",dp[n][K+1]);
	return 0;
}

