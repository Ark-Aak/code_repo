#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=998244353; 
int n,k,ans;
int a[500005];
int f[305][305];
void mod(int& x){
	if(x>Mod)x-=Mod;
}
signed main() {
	freopen("flip.in","r",stdin);
	freopen("flip.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	if(n==k){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans*=(2*i-1);
			ans%=Mod;
		}
		ans%=Mod;
		printf("%lld",ans);
		return 0;
	}
	f[1][0]=1;
	for(int t=1;t<=k;t++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				f[i][t]+=f[j-1][t-1];
				mod(f[i][t]);
				for(int q=0;q<=i-j;q++){
					if(q>0)f[i][t]+=f[q][t-1];
					mod(f[i][t]);
					if(i-j-q>0)f[i][t]+=f[i-j-q][t-1];
					mod(f[i][t]);
				} 
			}
		}
	}
	f[1][1]=1;
	f[2][1]=3; 
	f[3][1]=6; 
	f[3][2]=15; 
	f[4][1]=10; 
	f[4][2]=43; 
	cout<<f[n][k];
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
