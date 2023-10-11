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
ll n,a[Nx],b[Nx];
inline ll specially_solve(){
	if(n<3) return 0;
	ll res=1;
	rep(i,1,n) res*=i;
	rep(i,1,3) res/=i;
	rep(i,1,n-3) res/=i;
	return res;
}
int main()
{
	freopen("explorer.in","r",stdin);
	freopen("explorer.out","w",stdout);
	rep(i,1,n=read()) a[i]=read(),b[i]=read();
	printf("%lld",specially_solve()); 
	return 0;
 } 
