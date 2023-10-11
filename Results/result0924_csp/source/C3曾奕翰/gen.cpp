#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=1e9+7;
int n,q;
int a[200005];
int g[2000005];
int u[200005],v[200005];
int ans,maxx;
struct XXX{
	int u,v;
}za[200005];
bool cmp(XXX xx,XXX yy){
	if(xx.u==yy.u) return xx.v<yy.v;
	return xx.u<yy.u;
}
signed main(){
	freopen("gen.in","r",stdin);
	freopen("gen.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=q;i++){
		cin>>u[i]>>v[i];
		if(u[i]>v[i]) swap(u[i],v[i]);
		za[i].u=u[i];
		za[i].v=v[i];
	}
	sort(za+1,za+q+1,cmp);
	for(int i=1;i<=q;i++){
		///if(u[i]==u[i-1]&&v[i]==v[i-1])continue;
		a[u[i]]++;
		a[v[i]]++;
		maxx=max(maxx,a[u[i]]);
		maxx=max(maxx,a[v[i]]);
	}
	for(int i=1;i<=n;i++){
		g[a[i]]++;
	}
	if(n<=2000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans+=(a[i]^a[j])%Mod*(a[i]|a[j])%Mod*(a[i]&a[j])%Mod;
				
				ans%=Mod;
			}
		}
		cout<<ans%Mod;
		return 0;
	}
	for(int i=1;i<=maxx;i++){
		for(int j=i+1;j<=maxx;j++){
			ans+=(i^j)%Mod*(i|j)%Mod*(i&j)%Mod*g[i]%Mod*g[j]%Mod;
			ans%=Mod;
		}
	}
	cout<<ans;
	return 0;
}

