#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int d[200005],u,v; 
int ans,mod=1000000007;
int h[200005],mx;
signed main(){
	freopen("gen.in","r",stdin);
	freopen("gen.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%lld %lld",&u,&v);
		d[u]++;mx=max(mx,d[u]);
		d[v]++;mx=max(mx,d[v]);
	}
	if(n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans+=(d[i]^d[j])*(d[i]|d[j])*(d[i]&d[j]);
				ans%=mod;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	if(mx<=2000){
		for(int i=1;i<=n;i++) h[d[i]]++;
		for(int i=1;i<=2000;i++){
			for(int j=i+1;j<=2000;j++){
				ans+=((i^j)*(i|j)*(i&j)%mod*h[i]%mod*h[j]%mod);
				ans%=mod;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	return 0;
}
