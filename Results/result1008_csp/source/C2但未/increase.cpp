#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
const int Maxn=2e5+5;
int n,m;
int head[Maxn],to[Maxn*5],nxt[Maxn*5],val[Maxn*5],cnt1;
inline void add(int u,int v,int w){
	to[++cnt1]=v;
	nxt[cnt1]=head[u];
	val[cnt1]=w;
	head[u]=cnt1;
}
map<pair<int,int>,int>f[2];
int dfs(int u,int w,int p){
	if(f[p][{u,w}]!=-1)return f[p][{u,w}];
	f[p][{u,w}]=0;
	if(!p)f[p][{u,w}]=1e9;
	
	for(int i=head[u];i;i=nxt[i]){
		int y=to[i];
		if(p==1){
			if(val[i]>w)f[p][{u,w}]=max(f[p][{u,w}],dfs(y,val[i],p^1)+1);
		}
		else if(val[i]>w)f[p][{u,w}]=min(f[p][{u,w}],dfs(y,val[i],p^1)+1);
	}
	if(f[p][{u,w}]>=9.9e8)f[p][{u,w}]=0;
	return f[p][{u,w}];
}
int main(){
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);add(v,u,w);
		f[0][{u,0}]=f[1][{u,0}]=-1;
		f[0][{v,0}]=f[1][{v,0}]=-1;
		f[0][{u,w}]=f[1][{v,w}]=-1;
		f[1][{u,w}]=f[0][{v,w}]=-1;
	}
	for(int i=1;i<=n;i++)
		printf("%d ",dfs(i,0,1));
	return 0;
}

