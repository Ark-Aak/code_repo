#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 2050
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
const ll Mod=998244353;
ll n,m;
namespace solve1{
	ll f[250][250];
	void main1(){
		rep(i,1,m) f[1][i]=1;
		rep(i,2,n) rep(j,1,m) rep(k,1,m)
			if(k>=j||j%k>0) f[i][k]=(f[i][k]+f[i-1][j])%Mod;
		ll ans=0;
		rep(i,1,m) ans=(ans+f[n][i])%Mod;
		printf("%lld",ans);  
	}
} //namespace solve1
#define ONLINE_JUDGE//
#define DEBUG//
int main()
{
	#ifdef ONLINE_JUDGE
		freopen("sequence.in","r",stdin);
		freopen("sequence.out","w",stdout);
	#endif
	n=read(),m=read();
	if(n<=200&&m<=200) solve1::main1();
	return 0;
}
