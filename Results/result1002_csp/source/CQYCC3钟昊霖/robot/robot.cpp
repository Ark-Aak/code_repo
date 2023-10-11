#include<bits/stdc++.h>
using namespace std;
#define int long long

#define F(i,a,b) for(int i=a;i<=b;i++)

const int N=2e5+5;

inline int read();

int head[N],nxt[N],to[N],tot;

int siz[N],son[N],dfn[N],top[N],f[N],idx,id[N],dep[N];

inline void dfs(int u,int v) {
//	cout<<u<<endl;
	f[u]=v;
	siz[u]=1;
	dep[u]=dep[v]+1;
	for(int i=head[u]; i; i=nxt[i]) {
		if(to[i]==v) continue;
		dfs(to[i],u);
		siz[u]+=siz[to[i]];
		if(!son[u]||siz[son[u]]<siz[to[i]])son[u]=to[i];
	}
}
inline void dfs1(int u,int v) {	
	top[u]=v;
	if(son[u]) dfs1(son[u],v);
	else return;
	for(int i=head[u]; i; i=nxt[i]) {
		if(to[i]==son[u]||to[i]==v) continue;
		dfs1(to[i],to[i]);
	}
}
inline int LCA(int x,int y) {
	while(top[x]!=top[y]) {
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=f[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}

struct node {
	int l,r;
} a[N];

int n,m,T;

inline void AddEdge(int u,int v) {
	to[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}

bool cmp(node a,node b) {
	return a.l<b.l;
} 
inline void SubtaskL() {
	m=read();
	F(i,1,m)
	a[i].l=read(),a[i].r=read();
	sort(a+1,a+n+1,cmp);
	F(i,1,m) {
		if(a[i].r<a[i+1].l||a[i].r<a[i+1].r) continue;
		else {
			cout<<"No"<<endl;
			return ;
		}
	}
	cout<<"Yes"<<endl;
}

inline void Subtask1() {
	m=read();
	F(i,1,m)
	a[i].l=read(),a[i].r=read();
	for(int i=1; i<=m; i++) {
		for(int j=i+1; j<=m; j++) {
			bool xx=false,yy=false;
			xx=(LCA(a[i].r,a[j].l)!=a[j].l),yy=(LCA(a[i].l,a[j].r)!=a[i].l);
			if(xx||yy) continue;
			else {
				cout<<"No"<<endl;
			}
		}
	}
	cout<<"Yes"<<endl;
	return;
}

signed main() {
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	T=read();
	while(T--) {
		memset(son,0,sizeof son);
		tot=0;
		memset(head,0,sizeof head),memset(nxt,0,sizeof nxt),memset(to,0,sizeof to);
		n=read();
		int falg=0;
		for(int i=1,u,v; i<n; i++) {
			u=read(),v=read();
			AddEdge(u,v),AddEdge(v,u);
			if(v==u+1) falg++;
		}
		if(falg==n-1) {
			SubtaskL();
			continue;
		}
		dfs(1,1),dfs1(1,1);
		Subtask1();

	}
	return 0;
}

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
