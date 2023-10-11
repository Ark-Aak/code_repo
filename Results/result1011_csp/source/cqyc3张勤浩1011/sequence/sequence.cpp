#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Mod=998244353,Maxn=1e5+7;
ll f[Maxn],n,m,ans,dp[Maxn],G[320][320];
ll pos[Maxn],cnt;
ll Sf=1,Sk,NeSf=1;
inline ll up(ll x){
	return (x%Mod+Mod)%Mod;
}
// 维护一段 
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll l=1,r;l<=m;l=r+1){
		r=m/(m/l);
		++cnt;
		for(ll i=l;i<=r;i++) pos[i]=cnt;
	}
	for(ll i=1;i<=n;i++){
		// Sk 可以预处理 
		for(ll l=1,r;l<=m;l=r+1){
			r=m/(m/l);
			for(ll k=r;k<=m;k+=r) Sk=(Sk+dp[pos[k]])%Mod;
			dp[pos[l]]=max(dp[pos[l]]-1,0ll)+up(Sf-Sk),NeSf=(NeSf+dp[pos[l]]*(r-l+1))%Mod; 
			//cout<<i<<" "<<l<<" "<<r<<" "<<Sk<<" "<<Sf<<endl; 
			Sk=0;
		}
		swap(NeSf,Sf);NeSf=1;
		
	}
	for(ll l=1,r;l<=m;l=r+1){
		r=m/(m/l);
		ans=(ans+dp[pos[l]]*(r-l+1))%Mod;
	}
	printf("%lld",ans);
	return 0;
}
/*
2 2 

5 3 

200 195

100 3

100 5

2000 100000

*/

