#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Mod=1e9+7;
const ll Maxm=1e5+7,inv2=500000004ll;
bitset<Maxm>isp;
vector<int>p;
ll n,m,T;
short mu[Maxm];
ll Smu[Maxm],Sf[Maxm];
vector<int>sp[Maxm];
inline void init(int N){
	isp[0]=isp[1]=1;
	mu[1]=1;
	for(int i=2;i<=N;i++){
		if(!isp[i]) p.push_back(i),mu[i]=-1;
		for(int j:p){
			if(i*j>N) break;
			isp[i*j]=1;
			if(!(i%j)) break;
			mu[i*j]=-mu[i];
		}
	}
	for(int i=1;i<=N;i++)
		for(int j=i;j<=N;j+=i)
			Smu[j]+=mu[i],sp[j].push_back(i);
}
inline ll up(ll x){
	return (x%Mod+Mod)%Mod;
}
inline ll S(ll x){
	if(x%2) return up((x+1)/2*x%Mod);
	return up(x/2*(x+1)%Mod);
}
inline ll S1(ll x){
	ll z=(x+1)/2;
	return up(z*z%Mod);
}
inline ll T1(ll x){
	return (x+1)/2;
}
inline ll T2(ll x){
	return x-T1(x);
}
inline ll S2(ll x){
	ll z=S(x)-S1(x);
	return up(z);
}
inline ll F(ll x,ll y){
	if(y&1) return up(up(y*S2(x)%Mod+y*S1(x)%Mod-T1(x))%Mod*inv2%Mod);
	return up(y*S(x)%Mod*inv2%Mod);
}
inline ll F1(ll x,ll y){
	if(y&1) return up(up(y*S1(x)%Mod-T1(x)+y*S2(x)%Mod)*inv2%Mod-T2(x));
	return up(y*S(x)%Mod*inv2%Mod-x);
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%lld",&T);
	init(Maxm-7);
	while(T--){
		scanf("%lld%lld",&n,&m);
		ll ans=0;
		if(n>m) swap(n,m);
		for(ll T=1;T<=n;T++){
			for(ll d:sp[T]){
				ll res=0;
				res=(F(n/T,d)%Mod*(m/T)%Mod+F(m/T,d)%Mod*(n/T)%Mod)%Mod;
				res=(res+F1(n/T,d)%Mod*(m/T)%Mod+F1(m/T,d)*(n/T)%Mod)%Mod;
				ans+=res*mu[d]%Mod;
				ans=(ans%Mod+Mod)%Mod;
			}
		}
		cout<<ans%Mod<<endl;
	}
	return 0;
}
/*
3
5 4
4 4
1000 981

4
5 4
4 4
1000 981
5872502 5382176
*/

