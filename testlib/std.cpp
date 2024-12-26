#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
inline int Mod(int x){return x>=mod?x-mod:x;}
inline int poww(int x,int y){
	int sum=1;
	while(y){
		if(y&1)sum=1ll*sum*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return sum;
}
int n,m,s,ans;
int a[55];
int fac[2005],inv[2005],p[2005][2005];
int f[55][55][2005];
void Init(int x){
	int is=poww(s,mod-2);
	fac[0]=1;for(int i=1;i<=x;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[x]=poww(fac[x],mod-2);for(int i=x;i>=1;i--)inv[i-1]=1ll*i*inv[i]%mod;
	for(int i=1;i<=x;i++)
		for(int j=p[i][0]=1;j<=x;j++)
			p[i][j]=1ll*i*is%mod*p[i][j-1]%mod;
}
signed main(){
	f[0][0][0]=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)s+=a[i];
	Init(2e3);
	int maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i;j++)
			for(int k=0;k<=maxn;k++)
				for(int l=0;l*m<=a[i];l++){
					f[i][j][k+l]=Mod(f[i][j][k+l]+1ll*f[i-1][j][k]*p[a[i]-m*l][l]%mod*inv[l]%mod);
					if(l)f[i][j+1][k+l]=Mod(f[i][j+1][k+l]+1ll*f[i-1][j][k]*p[a[i]-m*l][l-1]%mod*inv[l-1]%mod);
				}
		maxn+=a[i]/m;
	}
	for(int i=0;i<=n;i++)for(int j=i;j<=maxn;j++)if(i+j){
		if(j&1)ans=Mod(ans+1ll*poww(p[m*j][j-i+1],mod-2)*fac[j-i]%mod*f[n][i][j]%mod);
		else ans=Mod(ans+mod-1ll*poww(p[m*j][j-i+1],mod-2)*fac[j-i]%mod*f[n][i][j]%mod);
	}
	cout<<ans;
	return 0;
}
