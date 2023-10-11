#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod=998244353;
int n,k;
int f[1000003],h[1000003];
signed main(){
	freopen("flip.in","r",stdin);
	freopen("flip.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	f[0]=1;
	for(int i=1;i<=n;i++) f[i]=(f[i-1]*i)%mod;
	for(int i=1;i<=n;i++){
		h[i]+=f[i];
		for(int j=1;j<i;j++) h[i]+=h[j]*h[i-j];
	}
	printf("%lld",h[n]);
	return 0;
}


