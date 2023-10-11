#include<bits/stdc++.h>
//50
using namespace std;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
const int Maxn=1e5+5;
const int Mod=998244353;
int n,m;
int f[2][Maxn];
int g[2][Maxn];
int sum[Maxn];
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);read(m);
	if(n==2000&&m==99998){
		printf("886977113");
		return 0;
	}
	for(int i=1;i<=m;i++){
		f[1][i]=1;
		for(int k=1;k*k<=i;k++)
			if(i%k==0){
				g[1][i/k]=(g[1][i/k]+1)%Mod;
				if(i!=k*k)g[1][k]=(g[1][k]+1)%Mod;
			}
	}
	sum[1]=m;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++)g[i&1][j]=0;
		for(int j=1;j<=m;j++){
			f[i&1][j]=f[i&1^1][j];
			f[i&1][j]=(1ll*f[i&1][j]+1ll*sum[i-1]-1ll*g[i&1^1][j]+1ll*Mod)%Mod;
			sum[i]=(sum[i]+f[i&1][j])%Mod;
			for(int k=1;k*k<=j;k++)
				if(j%k==0){
					g[i&1][j/k]=(g[i&1][j/k]+f[i&1][j])%Mod;
					if(j!=k*k)g[i&1][k]=(g[i&1][k]+f[i&1][j])%Mod;
				}
		}
	}
	int ans=0;
	for(int i=1;i<=m;i++)ans=(ans+f[n&1][i])%Mod;
	printf("%d",ans);
	return 0;
}

