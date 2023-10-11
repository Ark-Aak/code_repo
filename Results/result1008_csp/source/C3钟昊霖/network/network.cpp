#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=a;i<=b;i++)

const int N=2e6+5;


inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
int Q,n,head[N],nxt[N],to[N],tot;

int f[N],siz[N],top[N],son[N],dep[N],idx,in[N],dfn[N];

struct SegTree {
	int Min[N<<1];
	inline void Merge(int u) {
		Min[u]=min(Min[u<<1],Min[u<<1|1]);
	}
	inline void Build(int num,int l,int r) {
		if(l==r) {
			Min[num]=in[l];
			return;
		}
		int mid =(l+r) >> 1;
		Build(num<<1,l,mid),Build(num<<1|1,mid+1,r);
		Merge(num);
	}
	inline int Query(int num,int l,int r, int L,int R) {
		if(l>R||r<L) return INT_MAX;
		if(L<=l&&r<=R) return Min[num];
		int mid = (l+r) >>1;
		return min(Query(num<<1,l,mid,L,R),Query(num<<1|1,mid+1,r,L,R));
	}

} Tree;


inline void AddEdge(int u,int v) {
	to[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}

inline void dfs(int u,int v) {
	f[u]=v;
	siz[u]=1;
	dep[u]=dep[v]+1;
	for(int i=head[u]; i; i=nxt[i]) {
		if(to[i]==v) continue;
		dfs(to[i],u);
		siz[u]+=siz[to[i]];
		if(!son[u]||siz[son[u]]<siz[to[i]]) son[u]=to[i];
	}
}

inline void dfs1(int u,int v) {
	top[u]=v;
	dfn[u]=++idx;
	in[idx]=u;
	if(son[u]) dfs1(son[u],v);
	else return;
	for(int i=head[u]; i; i=nxt[i]) {
		if(to[i]==son[u]||to[i]==f[u]) continue;
		dfs1(to[i],to[i]);
	}
}

inline int LCA(int u,int v) {
	int ans = INT_MAX;
//	cout<<u<<" "<<v<<endl; 
	while(top[u]!=top[v]) {		
		if(dep[f[top[u]]]<dep[f[top[v]]]) swap(u,v);
		ans=min(ans,Tree.Query(1,1,n,dfn[top[u]],dfn[u]));
		u=f[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
//	cout<<u<<" "<<v<<endl; 
	ans = min(ans,Tree.Query(1,1,n,dfn[u],dfn[v]));
	return ans;
}

char s[N];

int cnt,cnm;

int Ans[N];

signed main() {
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout); 
	n=read(),Q=read();
	F(i,1,n-1) {
		int u,v;
		u=read(),v=read();
		AddEdge(u,v),AddEdge(v,u);
	}
	dfs(1,0);
	dfs1(1,0);
	Tree.Build(1,1,n);
	int ggrt=0;
	int ans = INT_MAX;
	while(Q--) {
		scanf("%s",s+1);
		cnm=read();
		if(s[1]=='J') {
			if(ggrt==0) ggrt=cnm;
			else ggrt=LCA(ggrt,cnm);
		} else {
			printf("%d\n",LCA(ggrt,cnm));
		}
	}
	return 0;
}



