#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int Maxn=1e5+5;
int n,m,q;
int head[Maxn],to[Maxn<<2],nxt[Maxn<<2],cnt1;
inline void add(int u,int v){
	to[++cnt1]=v;
	nxt[cnt1]=head[u];
	head[u]=cnt1;
}
int vis[Maxn];
int a[Maxn];
queue<int>h;
int cnt=0;
void dfs(int u,int k){
	for(int i=head[u];i;i=nxt[i]){
		int y=to[i];
		if(a[y]==k||vis[y]==k)continue;
		a[y]=k;++cnt;
		dfs(y,k);
	}
}
int pd[Maxn];
bool dfs1(int u,int v,int k){
	if(u==v){
		vis[u]=k;
		return 1;
	}
	if(pd[u])return 0;
	pd[u]=1;
	int p1=0;
	for(int i=head[u];i;i=nxt[i]){
		int y=to[i];
		bool p=dfs1(y,v,k);
		if(p)vis[u]=k,p1=p;
	}
	pd[u]=0;
	return p1;
}
inline void solve1_4(){
	for(int k=1;k<=q;k++){
		int u=read(),v=read();
		int f=dfs1(u,v,k);
		int ans=0;
		for(int i=1;i<=n;i++)
			if(vis[i]!=k&&a[i]!=k){
				cnt=1;a[i]=k;dfs(i,k);
				ans^=cnt;
			}
		printf("%d\n",ans);
	}
}
int f[Maxn][22],dep[Maxn],si[Maxn];
void dfs2(int u,int v){
	f[u][0]=v;dep[u]=dep[v]+1;
	si[u]=1;
	for(int i=1;i<22;i++)f[u][i]=f[f[u][i-1]][i-1];
	for(int i=head[u];i;i=nxt[i]){
		int y=to[i];
		if(y==v)continue;
		dfs2(y,u);
		si[u]+=si[y];
	}
}
inline int Lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	for(int i=21;~i;i--)
		if(f[u][i]&&dep[f[u][i]]>=dep[v])u=f[u][i];
	if(u==v)return u;
	//printf("%d %d %d %d\n",f[u][0],f[v][0],dep[u],dep[v]);
	for(int i=21;~i;i--)
		if(f[u][i]&&f[v][i]&&f[u][i]!=f[v][i]){
			u=f[u][i];
			v=f[v][i];
		}
	return f[u][0];
}
inline void solve5_8(){
	dfs2(1,0);
	while(q--){
		int u=read(),v=read();
		if(dep[u]>dep[v])swap(u,v);
		int lca=Lca(u,v);
		if(lca==u){
			printf("%d\n",(si[v]-1)^(n-si[u]));
		}
		else{
			printf("%d\n",(si[u]-1)^(si[v]-1)^(n-si[lca]));
		}
	}
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	q=read();
	if(n<=5000)solve1_4();
	else solve5_8();
	return 0;
}

