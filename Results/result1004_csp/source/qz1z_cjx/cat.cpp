#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define ll long long
#define Nx 505
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
char Map[Nx][Nx];
ll a[Nx][Nx],ans,n;
bool vis[Nx][Nx];
inline void dfs(ll x,ll y,ll sum){
	if(y>n) return x<n?(void)dfs(x+1,1,sum):(void)(ans=(ans+sum)%Mod);
	if(Map[x][y]=='L')
		rep(j,1,y) if(Map[x][j]=='R'&&!vis[x][j]&&(vis[x][j]=1))
			dfs(x,y+1,(sum+a[x][y]+a[x][j])%Mod),vis[x][j]=0; 
	if(Map[x][y]=='U')
		rep(i,1,x) if(Map[i][y]=='D'&&!vis[i][y]&&(vis[i][y]=1))
			dfs(x,y+1,(sum+a[x][y]+a[i][y])%Mod),vis[i][y]=0;
	dfs(x,y+1,sum);
}
int main()
{
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	rep(i,1,n=read()) scanf("%s",Map[i]+1);
	rep(i,1,n) rep(j,1,n) a[i][j]=read();
	dfs(1,1,0);
	printf("%lld",ans);
	return 0;
}
