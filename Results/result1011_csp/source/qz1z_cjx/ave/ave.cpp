#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define db double
#define Nx 1000050
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
ll N,b[Nx];
db a[Nx];
db dfs(ll x,db ave,db now){
	if(x>N) return now?(ave?(ave+now)/2:now):ave;
	db ans1=dfs(x+1,ave?(ave+now)/2:now,a[x]);
	db ans2=dfs(x+1,ave,now?(now+a[x])/2:a[x]); 
	if(ans1>ans2) b[x]=1;
	return max(ans1,ans2);
}
db solve(){
	db ans=a[1];
	rep(i,2,N) ans=(ans+a[i])/2;
	return ans;
}
#define ONLINE_JUDGE//
#define DEBUG//
int main()
{
	#ifdef ONLINE_JUDGE
		freopen("ave.in","r",stdin);
		freopen("ave.out","w",stdout);
	#endif
	rep(i,1,N=read()) a[i]=read();
	sort(a+1,a+N+1);
	#ifdef ONLINE_JUDGE 
		printf("%.6lf",solve());
	#endif
	#ifndef ONLINE_JUDGE
	#ifdef DEBUG
		printf("%.6lf\n%.6lf",dfs(1,0,0),solve());
	#endif
	#endif
	return 0;
}
