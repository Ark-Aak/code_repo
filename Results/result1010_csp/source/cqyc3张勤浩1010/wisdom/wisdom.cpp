#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Maxn=1e5+7,Mod=1e9+7,inv2=5e8+4;
ll n,m,k; 
struct node{
	ll x,y;
	char opt;
}a[Maxn];
ll ans;

map<ll,ll>Sx,Sy;

inline ll up(ll x){
	return (x%Mod+Mod)%Mod;
}
inline ll calc(ll x,ll y){
	return up((x-1)*m%Mod+y);
}
inline ll calcLen(ll x){
	return up(m*(m+1)%Mod*inv2%Mod+m*(x-1)%Mod*m%Mod);
}
inline ll calcFen(ll x){
	return up(n+m*(n-1)%Mod*n%Mod*inv2%Mod+(x-1)*n%Mod);
}
inline fes(ll x){
	if(x==-1) return 0;
	return x;
}
int main(){
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=k;i++){
		cin>>a[i].opt;
		scanf("%lld%lld",&a[i].x,&a[i].y);
		if(a[i].y==1) continue;
		if(a[i].y==0) a[i].y=-1;
		if(a[i].y==-1){
			if(a[i].opt=='R') Sx[a[i].x]=-1;
			if(a[i].opt=='S') Sy[a[i].x]=-1;
		}
		if(a[i].opt=='R'&&Sx[a[i].x]==-1) continue;
		if(a[i].opt=='S'&&Sy[a[i].x]==-1) continue;
		if(a[i].opt=='R'&&!Sx[a[i].x]) Sx[a[i].x]=a[i].y;
		else if(a[i].opt=='R'&&Sx[a[i].x]!=-1) Sx[a[i].x]=Sx[a[i].x]*a[i].y%Mod;
		if(a[i].opt=='S'&&!Sy[a[i].x]) Sy[a[i].x]=a[i].y;
		else if(a[i].opt=='S'&&Sy[a[i].x]!=-1) Sy[a[i].x]=Sy[a[i].x]*a[i].y%Mod;
	}
	ans=(n*m)%Mod*(n*m%Mod+1)%Mod*inv2%Mod;
	for(auto i:Sx)
		for(auto j:Sy)
			ans=up(ans-calc(i.first,j.first)+calc(i.first,j.first)*fes(j.second)%Mod*fes(i.second)%Mod);
	for(auto i:Sx){
		ans=up(ans+calcLen(i.first)*fes(i.second)%Mod-calcLen(i.first));
		for(auto j:Sy) ans=up(ans-calc(i.first,j.first)*up(fes(i.second)-1)%Mod);
	}
	for(auto i:Sy){
		ans=up(ans+calcFen(i.first)*fes(i.second)%Mod-calcFen(i.first));
		for(auto j:Sx) ans=up(ans-calc(j.first,i.first)*up(fes(i.second)-1)%Mod);
	}
	printf("%lld",ans);
	return 0;
}
/*
3 4 4
R 2 4
S 4 1
R 3 2
R 2 0

3 1 1
S 1 4 

2 4 4
S 2 0
S 2 3
R 1 5
S 1 3
*/

