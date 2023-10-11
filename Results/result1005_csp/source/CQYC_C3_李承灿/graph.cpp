#include<bits/stdc++.h>
#define int long long
#define N 300002
using namespace std;
int n,m,q;
int tot,head[N<<1],nxt[N<<1],to[N<<1];
int cnt,siz[N],dfn[N],low[N];
int o,p[N],vis[N];
int s;
vector<pair<int,int> > e[N];
void add(int u,int v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
void dfs(int x,int f){
	dfn[x]=low[x]=++cnt;
	p[++o]=x;
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		if(to[i]==f) continue;
		if(!vis[to[i]]){
			dfs(to[i],x);
			low[x]=min(low[x],low[to[i]]);
			if(dfn[x]==low[to[i]]){
				++s;
				int u=o,si=0;
				while(true){
					si++;
					o--;
					if(p[o+1]==to[i]) break;
				}
				for(int j=o+1;j<=u;j++) siz[p[j]]+=si,e[p[j]].push_back(make_pair(s,si));
				siz[x]+=si;
				e[x].push_back(make_pair(s,si));
			}
		}
		else low[x]=min(low[x],dfn[to[i]]);
	}
	if(dfn[x]==low[x]) o--;
}
signed main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%lld %lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	scanf("%lld",&q);
	while(q--){
		int x,y;
		scanf("%lld %lld",&x,&y);
		printf("%lld\n",n-siz[x]-siz[y]-2);
	}
	return 0;
}


