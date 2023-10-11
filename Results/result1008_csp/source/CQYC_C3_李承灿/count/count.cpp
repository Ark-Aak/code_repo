#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[100005];
int dp[5003][5003];
int sum;
int ans;
const int mod=998244353;
signed main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=1;j<=m;j++){
			sum+=dp[i-1][j];
			sum%=mod;
		}
		if(i==1) sum=1;
		for(int j=1;j<=m;j++){
			for(int k=0;k<a[j];k++){
				if(i+k>n) continue;
				dp[i+k][j]+=sum;
				dp[i+k][j]%=mod;
				dp[i+k][j]=(dp[i+k][j]+mod-dp[i-1][j])%mod;
			}	
		}
	}
	for(int i=1;i<=m;i++) ans+=dp[n][i],ans%=mod;
	printf("%lld",ans);
	return 0;
}


