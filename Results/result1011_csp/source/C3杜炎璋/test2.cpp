#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int f[100005],sum[100005],cnt[100005],prime[100005],vis[100005];
void solve(int x) {
	int tot=0;
	memset(vis,0,sizeof vis);
	memset(cnt,0,sizeof cnt);
	for(int i=2;i<=x;i++) {
		if(!vis[i]) prime[++tot]=i,cnt[i]=(f[i]);
		for(int j=1;j<=tot && prime[j]*i<=x;j++) {
			vis[prime[j]*i]++;
			cnt[prime[j]*i]=(cnt[prime[j]*i]+cnt[prime[j]]+cnt[i]);
		}
	}
}
signed main(){
	int n,m,sum=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++) f[i]=1;
	for(int i=1;i<=n;i++) {
		for(int k=1;k<=m;k++) {
			f[k]=(f[k]+((((long long)sum-cnt[k]+2*mod))%mod+2*mod)%mod)%mod;
		}
		sum=0;
		for(int j=1;j<=m;j++) sum=(sum+f[j])%mod;
		solve(m);
		if(i<n) for(int j=1;j<=m;j++) f[j]=0;
	} 
	int ans=0;
	for(int i=1;i<=m;i++) ans=(ans+f[i])%mod;
	printf("%d",ans);
	return 0;
}


