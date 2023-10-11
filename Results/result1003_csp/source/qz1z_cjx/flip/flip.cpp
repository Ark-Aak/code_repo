#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 500500
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
ll n,k;
ll solve(){
	ll res=1;
	rep(i,1,k) res=(res*(n*2-1))%Mod,--n;
	return res; 
}
int main()
{
	freopen("flip.in","r",stdin);
	freopen("flip.out","w",stdout);
	n=read(),k=read();
	printf("%lld",solve());
	return 0;
 } 
