#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,mod=1e9+7;
int deg[200005];
int t[2005];
signed main(){
	freopen("gen.in","r",stdin);
	freopen("gen.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
	}
	if(n<=2000){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=(ans+(deg[i]^deg[j])*(deg[i]&deg[j])%mod*(deg[i]|deg[j])%mod)%mod;
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++)t[deg[i]]++;
		int ans=0;
		for(int i=0;i<=2000;i++){
			for(int j=i+1;j<=2000;j++){
				ans=(ans+t[i]*t[j]%mod*(i^j)%mod*(i&j)%mod*(i|j)%mod)%mod;
			}
		}
		cout<<ans;
	}
	return 0;
}

