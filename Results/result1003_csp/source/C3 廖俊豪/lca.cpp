#include<bits/stdc++.h>
#define int long long 
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}
	return x*f;
}
int n;
vector<int>to[500005];
int sum=0;
int siz[500005];
int f[500005];
void Init(int x,int fa){
	siz[x]=1;
	for(auto y:to[x]){
		if(y==fa)continue;
		Init(y,x);
		sum-=x*siz[y]*siz[y];
		siz[x]+=siz[y];
	}
	sum+=x*siz[x]*siz[x];
}
void modify(int x,int y){//由x向它的儿子y移动所产生的变化 
	int A=siz[x]-siz[y];
	int B=siz[y];
	siz[x]-=B;
	sum+=y*2*A*siz[y];
	sum-=x*2*B*siz[x];
	siz[y]+=A;
}
void dfs(int x,int fa){
	f[x]=sum;
	for(auto y:to[x]){
		if(y==fa)continue;
		modify(x,y);
		dfs(y,x);
		modify(y,x);
	}
}
signed main(){
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	n=read();
	for(int i=1;i<n;i++){
		int u,v;
		u=read();
		v=read();
		to[u].push_back(v);
		to[v].push_back(u);
	}
	Init(1,0);
	dfs(1,0);
	for(int i=1;i<=n;i++)printf("%lld ",f[i]);
	return 0;
} 
