#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int f[100005],sum[100005],cnt[100005];
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	int n,m,sum=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++) f[i]=1;
	for(int i=1;i<=n;i++) {
		for(int k=1;k<=m;k++) {
			f[k]=(f[k]+((((long long)sum-cnt[k]+2*mod))%mod+2*mod)%mod)%mod;
		}
		sum=0;
		for(int j=1;j<=m;j++) sum=(sum+f[j])%mod;
		for(int j=1;j<=m;j++) {
			for(int k=1;k*k<=j;k++) {
				if(j%k==0) {
					if(k!=1) cnt[k]=(cnt[k]+f[j])%mod;
					if(j/k!=k) cnt[(j/k)]=(cnt[(j/k)]+f[j])%mod;
				}
			}
		}
		if(i<n) for(int j=1;j<=m;j++) f[j]=0;
	} 
	int ans=0;
	for(int i=1;i<=m;i++) ans=(ans+f[i])%mod;
	printf("%d",ans);
	return 0;
}


