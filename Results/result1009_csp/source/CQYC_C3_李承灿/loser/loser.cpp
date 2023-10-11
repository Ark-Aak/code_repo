#include<bits/stdc++.h>
#define int long long
#define N 100003
using namespace std;
int n,q;
int tot,head[N],to[N<<1],nxt[N<<1];
int a[N];
int fa[N],dep[N];
void add(int u,int v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
void dfs(int x,int u){
	fa[x]=u;
	dep[x]=dep[u]+1;
	for(int i=head[x];i;i=nxt[i]){
		if(to[i]==u) continue;
		dfs(to[i],x);
	}
}
void f(int x,int y){
	a[x]^=1;
	a[y]^=1;
	while(fa[x]!=y&&fa[y]!=x){
		if(dep[x]<dep[y]) swap(x,y);
		x=fa[x];
		a[x]^=1;
	}
}
int w(int x,int y){
	if(x==y) return 0;
	int a0=0,b1=0,res=0;
	if(!a[x]) a0++;
	if(a[y]) b1++;
	while(fa[x]!=y&&fa[y]!=x){
		if(dep[x]>dep[y]){
			x=fa[x];
			if(!a[x]) a0++;
			else if(a0) a0--,res++;
		}
		else{
			y=fa[y];
			if(a[y]) b1++;
			else if(b1) b1--,res++;
		}
	}
	return (res+min(a0,b1))*2;
}
signed main(){
	freopen("loser.in","r",stdin);
	freopen("loser.out","w",stdout);
	scanf("%lld %lld",&n,&q);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%lld %lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	dfs(1,0);
	while(q--){
		int op,x,y;
		scanf("%lld %lld %lld",&op,&x,&y);
		if(op==1) f(x,y);
		else printf("%lld\n",w(x,y));
	}
	return 0;
}


