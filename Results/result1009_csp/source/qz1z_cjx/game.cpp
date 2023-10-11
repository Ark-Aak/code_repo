#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
const ll Mod=1e9+7;
ll tx[]={0,1,1,-1,-1},ty[]={0,-1,1,-1,1};
inline bool JudgeCorner(ll r,ll c,ll x,ll y){
	if(x==1&&y==1) return true;
	if(x==1&&y==c) return true;
	if(x==r&&y==1) return true;
	if(x==r&&y==c) return true;
	return false;
}
inline ll ChangeDirection(ll r,ll c,ll x,ll y,ll &d){
	if(x==1) {
		if(d==3) d=1;
		if(d==4) d=2;
		return 1;
	}
	if(x==r) {
		if(d==1) d=3;
		if(d==2) d=4;
		return 1;
	}
	if(y==1) {
		if(d==1) d=2;
		if(d==3) d=4;
		return 1;
	}
	if(y==c) {
		if(d==2) d=1;
		if(d==4) d=3;
		return 1;
	}
	return 0;
}
inline ll f(ll r,ll c,ll x,ll y,ll d){
	if(JudgeCorner(r,c,x,y)) return 0;
	return (ChangeDirection(r,c,x,y,d)+f(r,c,x+tx[d],y+ty[d],d))%Mod;
}
const ll N=10;
ll g[100][100];
//#define tools
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	rep(i,1,N) rep(j1,N) g[i][j]=(f(i+1,j+1,2,2,2)+g[i-1][j]+g[i][j-1]-g[i-1][j-1]+Mod)%Mod;
	#ifdef tools
		rep(i,1,N){
			rep(j,1,N) cout<<setw(N-2)<<g[i][j];
			putchar(10);
		}
	#endif
	rep(i,1,read()) printf("%lld\n",g[read()][read()]);
	return 0;
}
/*
2
5 4
4 4
*/

