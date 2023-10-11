#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c;
int a[1005];
int vis[1005];
int tot,head[4005],to[4005],nxt[4005];
void add(int u,int v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
void dfs(int x,int t,int s){
	s+=a[x];
	if(s-t*t*c>vis[x]) vis[x]=s-t*t*c;
	else return;
	for(int i=head[x];i;i=nxt[i]) dfs(to[i],t+1,s);
}
signed main(){
	freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&c);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),vis[i]=-1e9;
	for(int i=1,u,b,v;i<=m;i++){
		scanf("%lld %lld",&u,&v);
		add(u,v);
	}
	dfs(1,0,0);
	printf("%lld",vis[1]);
	return 0;
}

