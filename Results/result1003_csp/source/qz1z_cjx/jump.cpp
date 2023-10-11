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
ll n,a[Nx],last[Nx],f[Nx];
void solve(){
	ll l=1,r=0,s[Nx];
	rep(i,1,n){
		while(l<=r&&a[i]>=a[s[r]]) r--;
		if(l>r) last[i]=0;
		else last[i]=s[r];
		s[++r]=i;
	}
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	rep(i,1,n=read()) a[i]=read();
	solve();
	rep(i,1,n) f[i]=f[last[i]]+1;
	rep(i,1,n) printf("%lld ",f[i]);
	return 0;
 } 
