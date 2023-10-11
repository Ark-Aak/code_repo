#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int du[200005],v[2005],w[30][2],r[200005][25];
int ksm(int x,int y) {
	int ans=1;
	while(y) {
		if(y&1) ans=(ans*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return ans;
}
signed main() {
	freopen("gen.in","r",stdin);
	freopen("gen.out","w",stdout);
	int n,m,sum=0,maxn=0;
	scanf("%lld %lld",&n,&m);
	for(int i=1; i<=m; i++) {
		int x,y;
		scanf("%lld %lld",&x,&y);
		du[x]++;
		du[y]++;
		maxn=max(maxn,max(du[x],du[y]));
	}
	if(n<=2000) {
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				sum+=(du[i]^du[j])%mod*(du[i]&du[j])%mod*(du[i]|du[j])%mod;
				sum%=mod;
			}
		}
		printf("%lld",sum);
	} else if(maxn<=2000){
		for(int i=1;i<=n;i++) v[du[i]]++;
		for(int i=0; i<=2000; i++) {
			for(int j=i; j<=2000 ; j++) {
				if(i==j) sum+=(v[i])*(v[i]-1)/2*(i^j)%mod*(i|j)%mod*(i&j)%mod;
				else sum+=(v[i]*v[j])%mod*(i^j)%mod*(i|j)%mod*(i&j)%mod;
				sum%=mod;
			}
		}
		printf("%lld",sum);
	}
	return 0;
}
