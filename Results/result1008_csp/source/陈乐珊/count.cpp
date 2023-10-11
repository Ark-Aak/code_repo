#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const ll mod=998244353,N=5005;
ll n,m,a[100005];
ll dp[N][N],sum[N],sum2[N][N];
ll ans;
int main() {
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++) scanf("%lld",a+i);
	for(int i=1;i<=m;i++) dp[1][i]=1,sum2[1][i]=1;
	sum[1]=m%mod;
	for(int i=2;i<=n;i++) {
		for(int j=1;j<=m;j++) {
//			for(int k=max(i-a[j],1ll);k<i;k++) {
//				dp[i][j]=((dp[i][j]+sum[k])%mod-dp[k][j]+mod)%mod;
//			}
			dp[i][j]=(dp[i][j]+(sum[i-1]+mod-sum[max(i-a[j],1ll)-1])%mod)%mod;
			dp[i][j]=(dp[i][j]-(sum2[i-1][j]-sum2[max(i-a[j],1ll)-1][j]+mod)%mod+mod)%mod;
			if(i<=a[j]) dp[i][j]=(dp[i][j]+1)%mod;
			sum[i]=(sum[i]+dp[i][j])%mod;
			sum2[i][j]=(sum2[i-1][j]+dp[i][j])%mod;
		} 
		sum[i]=(sum[i]+sum[i-1])%mod;
	}
//	for(int i=1;i<=n;i++) {
//		for(int j=1;j<=m;j++) {
//			cout<<dp[i][j]<<" ";
//		} cout<<"\n";
//	}
	for(int i=1;i<=m;i++) ans=(ans+dp[n][i])%mod;
	cout<<ans;
	return 0;
}
/*
dp[i][j]:第i个位置上为值为j的段落末尾 
*/
