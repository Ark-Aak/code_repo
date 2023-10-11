#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int Maxn=5e5+5;
int n,f[Maxn];
int si[Maxn];
int head[Maxn],to[Maxn<<1],nxt[Maxn<<1],cnt1;
int son[Maxn];
inline void add(int u,int v){
	to[++cnt1]=v;
	nxt[cnt1]=head[u];
	head[u]=cnt1;
}
void dfs1(int u,int v){
	si[u]=1;f[1]+=u;
	for(int i=head[u];i;i=nxt[i]){
		int y=to[i];
		if(y==v)continue;
		son[u]++;
		dfs1(y,u);
		si[u]+=si[y];
	}
	for(int i=head[u];i;i=nxt[i]){
		int y=to[i];
		if(y==v)continue;
		f[1]+=1ll*u*si[y]*(si[u]-si[y]+1);
	}
}
void dfs(int u,int v){
	for(int i=head[u];i;i=nxt[i]){
		int y=to[i];
		if(y==v)continue;
		f[y]=f[u]+(y-u)*si[y]*(n-si[y]-1)*2+si[y]*(y-u)*2;
		dfs(y,u);
	}
}
signed main(){
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	n=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs1(1,0);
	dfs(1,0);
	for(int i=1;i<=n;i++)printf("%lld ",f[i]);
	return 0;
}

