#include<bits/stdc++.h>
#define int long long
#define N 500002
using namespace std;
void read(int &x){
	x=0;
	int f=1;char s=getchar();
	while(s<'0'||s>'9') if(s=='-')f=-1,s=getchar();
	while(s>='0'&&s<='9'){x=x*10+s-48;s=getchar();}
	x=x*f;
}
int n;
int tot,nxt[N<<1],to[N<<1],head[N<<1];
int siz[N],ans[N],sum[N],w[N];
inline void add(int u,int v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
inline void dfs(int x,int f){
	siz[x]=1;
	for(int i=head[x];i;i=nxt[i]){
		if(to[i]==f) continue;
		dfs(to[i],x);
		siz[x]+=siz[to[i]];
	}
}
inline void dfs2(int x,int f){
	ans[x]+=x*n*2-x;
	for(int i=head[x];i;i=nxt[i]){
		if(to[i]==f) continue;
		ans[x]+=siz[to[i]]*(n-siz[to[i]]-1)*x;
		dfs2(to[i],x);
	}
	ans[x]+=(siz[x]-1)*(n-siz[x])*x;
}
inline int dfs3(int x,int f){
	for(int i=head[x];i;i=nxt[i]){
		if(to[i]==f) continue;
		w[x]+=dfs3(to[i],x);
	}
	w[x]=ans[x]-(siz[x]-1)*(n-siz[x])*x*2-x*(n-siz[x])*2+w[x];
	return w[x];
}
inline void dfs4(int x,int f,int s){
	sum[x]+=s;
	for(int i=head[x];i;i=nxt[i]){
		if(to[i]==f) continue;
		dfs4(to[i],x,s+w[x]-w[to[i]]-siz[to[i]]*(n-siz[to[i]])*x*2+siz[to[i]]*(n-siz[to[i]])*to[i]*2);
	}
}
signed main(){
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	read(n);
	for(int i=1;i<n;i++){
		int u,v;
		read(u);read(v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	dfs2(1,0);
	int U=dfs3(1,0);
	dfs4(1,0,0);
	for(int i=1;i<=n;i++) printf("%lld ",w[i]+sum[i]);
	return 0;
}


