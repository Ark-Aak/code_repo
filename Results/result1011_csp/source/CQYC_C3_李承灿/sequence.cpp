#include<bits/stdc++.h>
using namespace std;
int n,m;
long long f[2002][2002],sum[2002];
long long g[2002][100002];
const long long mod=998244353;
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(n<=2000&&m<=2000){
		for(int i=1;i<=m;i++) f[1][i]=1;
		sum[1]=m;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=m;j++){
				f[i][j]=(f[i][j]+sum[i-1])%mod;
				for(int k=2;k*j<=m;k++){
					f[i][j]=(f[i][j]-f[i-1][j*k]+mod)%mod;
				}
				sum[i]=(sum[i]+f[i][j])%mod;
			}
		}
		printf("%lld",sum[n]);
		return 0;
	}
	int r,w;
	for(int l=1;l<=m;l=r+1){
		r=m/(m/l);
		g[1][m/l]=1;
	}
	sum[1]=m;
	for(int i=2;i<=n;++i){
		g[i][m]=1;
		sum[i]=sum[i]+1;
		if(sum[i]==m) sum[i]=0;
		for(int l=2;l<=m;l=r+1){
			r=m/(m/l);
			g[i][m/l]=sum[i-1];
			for(int k=2;k<=m/l;k=w+1){
				w=(m/l)/((m/l)/k);
				g[i][m/l]=(g[i][m/l]-(w-k+1)*g[i-1][m/(l*k)]%mod+mod)%mod;
			}
			sum[i]=(sum[i]+g[i][m/l]*(r-l+1)%mod)%mod;
		}
	}
	printf("%lld",sum[n]);
	return 0;
}


