#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Maxn=4e5+7,Mod=1e9+7;
ll n,k,ans,d[Maxn],g[Maxn],s[Maxn],in[Maxn],ps;
vector<ll>e[Maxn];
inline ll ksm(ll a,ll b,ll mod){
	ll z=1;
	a%=mod;
	while(b){
		if(b&1) z=z*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return z;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1,u,v;i<n;i++){
		scanf("%lld%lld",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
		if(u<v) d[v]++;
		else d[u]++;
		in[u]++;
		in[v]++;
		if(in[ps]<in[u]) ps=u;
		if(in[ps]<in[v]) ps=v;
	}
	if(n<=5000){
		for(ll i=1;i<=n;i++){
			ll res=0;
			for(ll j=i;j<=n;j++){
				int du=0,pp=0;
				for(auto v:e[j]){
					if(v<i) pp++;
				}
				res++;
				res-=d[j];
				res+=pp;
				if(k==1) ans=(ans+res);
				else if(k==2) ans=(ans+res*res);
				ans%=Mod;
			}
		}
		printf("%lld",ans);
		return 0;
	}
	if(in[ps]==n-1){
		ll q1=ps*(n-ps+1),q2=0,q3=0;
		for(ll i=1;i<=ps-1;i++) q2=(q2+i*i%Mod*(ps-i))%Mod;
		for(ll i=ps+1;i<=n;i++) q3=(q3+(i-ps)*(i-ps)%Mod*(n+1-i))%Mod;
		printf("%lld",(q1+q2+q3)%Mod);
	}
	return 0;
}
/*
4 2
1 2
2 3
2 4

6 1
1 4
4 6
4 2
2 3 
2 5
*/
