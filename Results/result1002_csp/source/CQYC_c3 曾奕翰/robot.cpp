#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch-'0');ch=getchar();}
	return x*f;
}
int n,m;
int p[120005],qq[120005];
int dep[120005],siz[120005];
int fa[120005],gg[120005],son[120005];
vector<int>q[120005];
bool vis[1205],flag;
bool bk[1205][1205];
void dfs1(int u,int fath){
	fa[u]=fath;
	dep[u]=dep[fath]+1;
	siz[u]=1;
	for(auto v:q[u]){
		if(v==fath) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int fath){
	gg[u]=fath;
	if(son[u])
		dfs2(son[u],fath);
	for(auto v:q[u])
		if(v!=son[u]&&v!=fa[u])
			dfs2(v,v);
}
int lca(int u,int v){
	while(gg[u]!=gg[v]){
		if(dep[gg[u]]>dep[gg[v]])swap(u,v);
		v=fa[gg[v]];
	}
	if(dep[u]>dep[v])swap(u,v);
	return u;
}
int st[120005];
void find(int x,int y){
	int u=p[x],v=qq[x];
	int ggg=lca(p[x],qq[x]);
	vis[u]=1;
	while(u!=ggg){
		u=fa[u];
		vis[u]=1;
	}
	while(v!=ggg){
		v=fa[v];
		vis[v]=1;
	}
	u=p[y],v=qq[y];
	ggg=lca(p[y],qq[y]);
	bool flag1=0;
	int gg=0,kk=0;
	bool gggg=0;
	if(u!=ggg){
		if(vis[u]==1) flag1=1,gg++;
		if(u==qq[x]) gggg=1;
	}
	kk++;
	while(u!=ggg){
		u=fa[u];
		kk++;
		if(vis[u]==0&&flag1) return;
		if(vis[u]==1) flag1=1,gg++;
		if(u==qq[x]) gggg=1;
	}
	int tot=0;
	if(v==qq[x]) gggg=1;
	while(v!=ggg){
		st[++tot]=v;
		v=fa[v];
		if(v==qq[x]) gggg=1;
	}
	for(int i=tot;i>=1;i--){
		kk++;
		if(vis[st[i]]==0&&flag1) return;
		if(vis[st[i]]==1) flag1=1,gg++;
	}
	if(flag1==0) return;
	if(gg==kk){
		
		flag=1;
		return;
		}
	if(gggg==0) return;
	flag=1;
	return;
}
void clean();
signed main() {
	freopen("robot.in","r",stdin);
	freopen("robot.out.","w",stdout); 
	int T=read();
	while(T--){
		clean();
		n=read();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			q[u].push_back(v);
			q[v].push_back(u);
		}
		dfs1(1,0);
		dfs2(1,1);
		m=read();
		for(int i=1;i<=m;i++){
			p[i]=read(),qq[i]=read();
		}
		flag=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i==j) continue;
				memset(vis,0,sizeof(vis));
				find(i,j);
				if(flag) break;
			}
			if(flag) break;
		}
		if(flag) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
void clean(){
	for(int i=1;i<=n;i++){
		q[i].clear();
	}
	n=0,m=0;
	memset(p,0,sizeof(p));
	memset(qq,0,sizeof(qq));
	memset(dep,0,sizeof(dep));
	memset(siz,0,sizeof(siz));
	memset(fa,0,sizeof(fa));
	memset(gg,0,sizeof(gg));
	memset(son,0,sizeof(son));
}
