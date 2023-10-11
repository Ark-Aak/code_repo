#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int f[100005],sum[100005],cnt[100005];
signed main(){
	freopen("sequence1.in","r",stdin);
	freopen("sequence1.out","w",stdout);
	int n,m,sum=0;
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=m;i++) f[i]=1;
	for(int i=1;i<=n;i++) {
		for(int k=1;k<=m;k++) f[k]=((f[k]+sum%mod-cnt[k]%mod)%mod+2*mod)%mod;
		sum=0;
		for(int j=1;j<=m;j++) sum+=f[j];
		for(int j=1;j<=m;j++) {
			for(int k=1;k*k<=j;k++) {
				if(j%k==0) {
					if(k!=1) cnt[k]=(cnt[k]+f[j])%mod;
					if(j/k!=k) cnt[(j/k)]=(cnt[(j/k)]+f[j])%mod;
				}
			}
		}
		if(i<n)for(int j=1;j<=m;j++) f[j]=0;
	} 
	int ans=0;
	for(int i=1;i<=m;i++) ans=(ans+f[i])%mod;
	printf("%lld",ans);
	return 0;
}


