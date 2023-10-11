#include<bits/stdc++.h>
using namespace std;
const int Maxn=1.2e5+5;
int T;
int head[Maxn],to[Maxn<<1],nxt[Maxn<<1],cnt1;
inline void add(int u,int v){
	to[++cnt1]=v;
	nxt[cnt1]=head[u];
	head[u]=cnt1;
}
int n,m;
int p[Maxn],q[Maxn];
int f[Maxn],dep[Maxn],si[Maxn],son[Maxn];
int id[Maxn],dfn[Maxn],top[Maxn],cnt;
void dfs1(int u,int v){
	f[u]=v;
	dep[u]=dep[v]+1;
	si[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int y=to[i];
		if(y==v)continue;
		dfs1(y,u);
		si[u]+=si[y];
		if(si[y]>si[son[u]])son[u]=y;
	}
}
void dfs2(int u,int t){
	dfn[u]=++cnt;
	top[u]=t;
	if(!son[u])return;
	dfs2(son[u],t);
	for(int i=head[u];i;i=nxt[i]){
		int y=to[i];
		if(y==f[u]||y==son[u])continue;
		dfs2(y,y);
	}
}
int s[Maxn];
void dfs(int u,int v){
	for(int i=head[u];i;i=nxt[i]){
		int y=to[i];
		if(y==v)continue;
		dfs(y,u);
		s[u]+=s[y];
	}
}
inline int Lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		u=f[top[u]];
	}
	return dep[u]>dep[v]?v:u;
}
struct Tree{int ls,rs,data;}t[Maxn<<1];
int cnt2=0;
inline void update(int x){
	t[x].data=min(t[t[x].ls].data,t[t[x].rs].data);
}
int build(int l,int r){
	int x=++cnt2;
	t[x].data=1e9;
	if(l==r)return t[x].data=s[id[l]],x;
	int mid=l+r>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	update(x);
	return x;
}
int query(int x,int l,int r,int L,int R){
	if(L<=l&&r<=R)return t[x].data;
	int mid=l+r>>1;
	int res=1e9;
	if(L<=mid)res=query(t[x].ls,l,mid,L,R);
	if(mid<R)res=min(res,query(t[x].rs,mid+1,r,L,R));
	return res;
}
inline void init(){
	cnt=0;cnt1=0;cnt2=0;
	for(int i=1;i<=n;i++){
		head[i]=0;s[i]=0;
		dep[i]=0;f[i]=0;
		top[i]=0;dfn[i]=0;
		son[i]=0;si[i]=0;
		t[i]={0,0,0};
	}
}
inline int solve(int u,int v){
	int res=1e9;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])swap(u,v);
		res=min(res,query(1,1,n,dfn[v],dfn[u]));
		u=f[top[u]];
	}
	if(dep[u]<dep[v])swap(u,v);
	return min(res,query(1,1,n,dfn[v],dfn[u]));
}

struct node{
	int p,q;
}s1[Maxn];
bool cmp(node a,node b){
	return a.p<b.p;
}
inline void solve5(){
	sort(s1+1,s1+1+m,cmp);
	int pd=1;
	for(int i=1;i<m;i++)
		if(s1[i].q>s1[i+1].p)pd=0;
	if(pd)printf("Yes\n");
	else printf("No\n");
}
int main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		int pdd=1;
		scanf("%d",&n);
		for(int i=1;i<n;i++){
			int u,v;scanf("%d%d",&u,&v);
			add(u,v);add(v,u);
			if(u!=i||v!=i+1)pdd=0;
		}
		dfs1(1,0);dfs2(1,1);
		for(int i=1;i<=n;i++)id[dfn[i]]=i;
		scanf("%d",&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d",&p[i],&q[i]);
			s1[i]={p[i],q[i]};
			if(s1[i].p>s1[i].q)swap(s1[i].p,s1[i].q);
			int lca=Lca(p[i],q[i]);
			s[p[i]]++;s[f[lca]]--;
			s[q[i]]++;s[lca]--;
		}
		if(pdd){
			solve5();
			continue;
		}
		int root=build(1,n),pd=1;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++){
				int u=q[i],v=q[j];
				if(i==j)continue;
				if(dep[p[i]]>dep[q[i]]&&dep[p[j]]<dep[q[j]]&&dep[u]<dep[v]&&Lca(u,v)==v&&dep[p[j]]<dep[q[i]])pd=0;//,printf("%d %d\n",i,j);
				//if(dep[p[i]]<dep[q[i]]&&dep[p[j]]>dep[q[j]]&&dep[u]>dep[v]&&Lca(u,v)==u&&dep[p[j]]>dep[q[i]])pd=0;
				//if(dep[u]<dep[v]&&Lca(u,v)==u)pd=0,printf("%d,%d:%d\n",i,j,Lca(u,v));
			}
		for(int i=1;i<=m;i++){
			if(solve(p[i],q[i])>1)pd=0;
			//printf("%d\n",dfn[q[i]]);//query(1,1,n,dfn[q[i]],dfn[q[i]])
		}
		if(pd)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
//Õý½âµí·ÛÖÊ£¿ 

