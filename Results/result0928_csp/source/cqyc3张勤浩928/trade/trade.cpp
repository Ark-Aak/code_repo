#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Maxn=1020;
int n,m,C,w[Maxn],cnt;
int tot,head[Maxn],f[5010],ans;
bool vis[Maxn<<2];
struct edge1{
	int u,v,Next,now;
}Edge[Maxn<<2];
inline void add(int u,int v){
	Edge[++tot]=(edge1){u,v,head[u],tot},head[u]=tot;
}
struct pag{
	int t,s;
}g[Maxn*100];
void DFS(int u,int t,int s,int tt){
	vis[tt]=1;
	if(t!=0&&u==1) g[++cnt]=(pag){t,s};
	for(int i=head[u];i;i=Edge[i].Next){
		if(!vis[i])
		DFS(Edge[i].v,t+1,s+w[Edge[i].v],i);
	}
	vis[tt]=0;
}
signed main(){
	freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&C);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1,u,v;i<=m;i++)
		scanf("%lld%lld",&u,&v),add(u,v);
	DFS(1,0,0,0);
	for(int i=1;i<=n;i++)
		for(int t=g[i].t;t<=5000;t++)
			f[t]=max(f[t],f[t-g[i].t]+g[i].s-C*(t*t-(t-g[i].t)*(t-g[i].t)));
	for(int i=1;i<=5000;i++) ans=max(ans,f[i]);
	printf("%lld",ans);
	return 0;
}
/*
3 3 1
0 10 20
1 2
2 3
3 1
*/
