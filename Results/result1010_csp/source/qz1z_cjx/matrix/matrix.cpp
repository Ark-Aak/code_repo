#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 20
#define Mx 5050
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
//---------------------------------//
const ll inf=LONG_LONG_MAX;
ll n,m,b[Nx],ans=inf;
char a[Nx][Nx];
void dfs(ll x){
	if(x>n){
		ll res=0;
		rep(i,1,m) res+=min(b[i],n-b[i]);
		ans=min(ans,res);
		return ;
	} 
	ll c[Nx];
	memcpy(c,b,sizeof b);
	rep(i,1,m) b[i]+=(a[x][i]=='1');
	dfs(x+1);
	memcpy(b,c,sizeof c);
	rep(i,1,m) b[i]+=(a[x][i]=='0');
	dfs(x+1);
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=read(),m=read();
	rep(i,1,n) scanf("%s",a[i]+1);
	dfs(1);	
	printf("%lld",ans);
	return 0;
}
