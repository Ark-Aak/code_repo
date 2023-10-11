#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m;
int f[1005][1005];
const int mod=1000000007;
signed main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld",&t);
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			int o=__gcd(i,j);
			f[i][j]=(i/o+j/o-2+mod)%mod;
		}
	}
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=1000;j++){
			f[i][j]+=(f[i-1][j]+f[i][j-1]-f[i-1][j-1]+mod)%mod;
			f[i][j]%=mod;
		}
	}
	while(t--){
		scanf("%lld %lld",&n,&m);
		printf("%lld\n",f[n][m]);
	}
	return 0;
}


