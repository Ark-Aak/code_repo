#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5005;
int n,k;
vector<int>q[N];
int fa[N],dep[N],son[N],siz[N],gg[N];
void dfs1(int x,int f){
	fa[x]=f;
	dep[x]=dep[f]+1;
	siz[x]=1;
	for(auto v:q[x]){
		if(v==f) continue;
		dfs1(v,x);
		siz[x]+=siz[v];
		if(siz[v]>siz[son[x]]) son[x]=v;
	}
}
/*
void dfs2(int x,int f){
	gg[x]=f;
	if(son[x]){
		dfs2(son[x],f);
	}
	for(auto v:q[x])
		if(v!=fa[x]&&v!=son[x])
			dfs2(v,v);
}*/
/*
int lca(int u,int v){
	while(gg[u]!=gg[v]){
		if(dep[gg[u]]>dep[gg[v]]) swap(u,v);
		v=fa[gg[v]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	return u;
}*/
signed main() {
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	scanf("%lld",&n);
	bool flag=0;
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%lld%lld",&u,&v);
		q[u].push_back(v);
		q[v].push_back(u);
		if(u+1!=v) flag=1;
	}
	if(!flag){
		int sum1=0,sum2=0;
		for(int i=1;i<=(n-2);i++){
			sum1+=i*(n-i)*2;
		}
		for(int i=1;i<=n;i++){
			int ans=0;
			sum2+=(i-2)*(i-1)*2;
			ans+=i*(n-1)*2+(i-1)*(n-i)*2*i;
			ans+=sum1;
			ans+=sum2;
			sum1-=(i+1)*(n-i-1)*2;
			printf("%lld ",ans+n*(n+1)/2);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(fa,0,sizeof(fa));
		memset(siz,0,sizeof(siz));
	//	memset(gg,0,sizeof(gg));
		memset(son,0,sizeof(son));
		memset(dep,0,sizeof(dep));
		dfs1(i,0);
		//dfs2(i,i);
		int ans=0;
		for(int j=1;j<=n;j++){
			int sum=0;
			int sans=0;
			for(auto t:q[j]){
				if(fa[j]==t) continue;
				sans+=sum*siz[t]*j;
				sum+=siz[t];
			}
			ans+=sans*2;
			ans+=j*(siz[j]-1)*2;
		}
		printf("%lld ",ans+n*(n+1)/2);
	}
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
