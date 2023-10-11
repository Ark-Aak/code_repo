#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Maxn=5005,Maxm=1e5+5,Mod=998244353;
int n,m;
int a[Maxm];
int f[Maxn][Maxn],g[Maxn][Maxn];
inline void solve50(){
	for(int i=1;i<=m;i++)
		f[0][i]=1,g[i][0]=1;
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=m;j++){
			for(int k=1;k<=min(a[j],i);k++)
				f[i][j]=(f[i][j]+g[j][i-k])%Mod;
			sum=(sum+f[i][j])%Mod;
		}
		for(int j=1;j<=m;j++)
			g[j][i]=(sum-f[i][j]+Mod)%Mod;
	}
	int ans=0;
	for(int i=1;i<=m;i++)ans=(ans+f[n][i])%Mod;
	printf("%lld\n",ans);
}
int dp[Maxn];
int sum[Maxn];
int gs[Maxn],g2[Maxn];
inline void solve100(){
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	dp[0]=1;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=a[i];j++)gs[j]++;
	for(int i=1;i<=n;i++){
		for(int k=1;k<=i;k++){
			f[i][k]=(dp[i-k]*gs[k]-g[i-k][k]+Mod)%Mod;
		}
		for(int k=1;k<=n;k++)
			g[i][k]=(g[i][k-1]+f[i][k])%Mod,dp[i]=(dp[i]+f[i][k])%Mod;
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans=(ans+f[n][i])%Mod;
	printf("%lld\n",ans);
}
signed main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%lld",&a[i]);
	if(n<=505&&m<=505)solve50();
	return 0;
}

