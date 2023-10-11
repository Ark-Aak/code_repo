#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,K,inv[15],cnt=0,w[15],sum=0,a[205];
int f[505][505],g[505][505];
signed main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%lld %lld",&n,&K);
	for(int i=1; i<=K; i++) scanf("%lld",&a[i]);
	a[0]=1e9;
	for(int i=0; i<=K; i++) f[0][i]=1;
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			for(int x=0; x<=K; x++) {
				if(j-i+1>=a[x]) continue;
				for(int y=0; y<=K; y++) {
					if(x==y) continue;
					if(f[i-1][y]>0) f[j][x]=(f[j][x]+f[i-1][y])%mod;
				}
				if(i==1) f[j][x]=1;
			}
		}
	}
	for(int i=0; i<=K; i++) {
		sum=(sum+f[n][i])%mod;
	}
	printf("%lld",sum);
	return 0;
}

