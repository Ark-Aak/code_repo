#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while((c<'0'||c>'9')&&c^'-') c=getchar();
	if(c=='-') f=-1,c=getchar();
	while('0'<=c&&c<='9') x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int head_g[N],head_t[N<<1],to[N*11],nxt[N*11],tot;
inline void add(int x,int y,int *head){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
inline void add_t(int x,int y){
	add(x,y,head_t);
	add(y,x,head_t);
}
int n,m,q,u,v;
int dfn[N],idx,cntp,low[N];
stack<int> stk;
void dfs(int p){
	dfn[p]=low[p]=++idx;
	stk.push(p);
	for(int o=head_g[p],v;o;o=nxt[o]){
		v=to[o];
		if(!dfn[v]){
			dfs(v);
			low[p]=min(low[p],low[v]);
			if(low[v]==dfn[p]){
				int tp=0;
				add_t(++cntp,p);
				while(tp^v){
					tp=stk.top(),stk.pop();
					add_t(tp,cntp);
				}
			}
		}else low[p]=min(low[p],dfn[v]);
	}
}
int sz[N<<1],son[N<<1],top[N<<1],f[N<<1],dep[N<<1];
int sum[N<<1],cnt[N<<1],cnts[N<<1];
void dfs1(int p,int fa){
	f[p]=fa;sz[p]=1;
	dep[p]=dep[fa]+1;
	cnt[p]=(p<=n);
	for(int o=head_t[p],v;o;o=nxt[o]){
		v=to[o];
		if(v^fa){
			dfs1(v,p);
			sz[p]+=sz[v];
			if(sz[v]>sz[son[p]]) son[p]=v;
			cnt[p]+=cnt[v];
			if(p<=n) sum[p]^=cnt[v];
		}
	}
}
void dfs2(int p,int tp){
	top[p]=p;
	sum[p]^=sum[f[p]];
	cnts[p]=(p<=n?0:cnt[p])^cnts[f[p]];
	if(!son[p]) return;
	dfs2(son[p],tp);
	for(int o=head_t[p];o;o=nxt[o])
		if(to[o]!=f[p]&&to[o]!=son[p])
			dfs2(to[o],to[o]);
}
inline int Lca(int x,int y){
	while(top[x]^top[y]){
		if(dep[top[x]]>dep[top[y]]) x=f[top[x]];
		else y=f[top[y]];
	}return dep[x]<dep[y]?x:y;
}int lca,ans;
void print(int x){
	if(x>9) print(x/10);
	putchar(48+x%10);
}
inline int Sum(int x,int y){return sum[x]^sum[y]^(lca<=n?(sum[lca]^sum[f[lca]]):0);}
inline int Cnt(int x,int y){return cnts[x]^cnts[y];}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	read(n),read(m);
	while(m--){
		read(u),read(v);
		add(u,v,head_g);
		add(v,u,head_g);
	}cntp=n;
	dfs(1);//cout<<cntp<<'\n';
	dfs1(1,0);
	dfs2(1,1);
	read(q);
	while(q--){
		read(u),read(v);
		if(dep[u]>dep[v]) swap(u,v);
		lca=Lca(u,v);
	//	cout<<lca<<'\n';
		ans=Sum(u,v)^Cnt(u,v)^(n-cnt[lca]);
		print(ans);
		//cout<<(S^(sum[u]^sum[v]^(sum[lca]^sum[f[lca]])));
		putchar('\n');
	}
	return 0;
}

