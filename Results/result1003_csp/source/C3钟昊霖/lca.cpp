#include <bits/stdc++.h>
using namespace std;

#define int long long 

#define F(i,a,b) for(int i=a;i<=b;i++)

inline int read();

const int N=1e6+5,M=7e5+5;

int head[N],nxt[N],to[N],tot,f[M],siz[M];

inline void AddEdge(int u,int v){
	to[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}

int n,ans;

void dfs(int u,int v){
	siz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		if(to[i]==v) continue;
		dfs(to[i],u);
		ans+=siz[u]*siz[to[i]]*u*2;
		siz[u]+=siz[to[i]];
	} 
	return;
}

inline void Solve(int x){
	F(i,1,n) siz[i]=0;
	dfs(x,x); 
	cout<<ans+(n+1)*n/2<<" ";	ans=0;
}


signed main(){
  	freopen("lca.in","r",stdin);
  	freopen("lca.out","w",stdout);
	n=read();
	for(int i=1,u,v;i<n;i++){
		u=read(),v=read();
		AddEdge(u,v),AddEdge(v,u);
	}
	F(i,1,n) Solve(i);	
	return 0;
}

inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}

