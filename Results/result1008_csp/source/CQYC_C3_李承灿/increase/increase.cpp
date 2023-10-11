#include<bits/stdc++.h>
#define int long long
#define N 200003
#define M 500003
using namespace std;
int n,m;
int tot,head[N],nxt[M<<1],to[M<<1],val[M<<1];
map<int,map<int,int> > f[2],vis[2];
void add(int u,int v,int w){
	nxt[++tot]=head[u];
	to[tot]=v;
	val[tot]=w;
	head[u]=tot;
}
int dfs(int x,int k,int o){
	if(vis[o][x][k]==1) return f[o][x][k];
	int mx=0,mn=1e12;
	for(int i=head[x];i;i=nxt[i]){
		if(val[i]<=k) continue;
		int t=dfs(to[i],val[i],o^1)+1;
		mx=max(mx,t);
		mn=min(mn,t);
	}
	if(mn==1e12){
		vis[o][x][k]=1;
		f[o][x][k]=0;
		return f[o][x][k];
	}
	if(o==1) f[o][x][k]=mx;
	else f[o][x][k]=mn;
	vis[o][x][k]=1;
	return f[o][x][k];
}
signed main(){
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%lld %lld %lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=n;i++) printf("%lld ",dfs(i,0,1));
	return 0;
}


