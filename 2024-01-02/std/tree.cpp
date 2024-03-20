#include<bits/stdc++.h>
#define rp(i,a,b) for(int i=a,_=b;i<=_;++i)
#define pr(i,a,b) for(int i=a,_=b;i>=_;--i)
#define pb push_back
using namespace std;
const int N=1e4+10;
int T,n,sz[N],mx[N];
char s[N];
vector<int> g[N],c;
void dfs(int u,int fa){
	sz[u]=1,mx[u]=0;
	for(int v:g[u])if(v!=fa){
		dfs(v,u);
		sz[u]+=sz[v];
		mx[u]=max(mx[u],sz[v]);
	}
	mx[u]=max(mx[u],n-sz[u]);
	if(mx[u]<=n/2)c.pb(u);
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		c.clear();
		rp(i,1,n)g[i].clear();
		rp(i,1,n-1){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].pb(v),g[v].pb(u);
		}
		dfs(1,0);
		int x;
		if(c.size()==1u){
			int u=c[0];
			if((s[u]=='R')==(n&1)){
				x=n&1;
			}else{
				int sum[2]={};
				for(int v:g[u])sum[s[v]=='R']+=n-mx[v];
				x=sum[0]<sum[1];
			}
		}else{
			x=1;
			for(int u:c)x&=s[u]=='R';
		}
		puts(x?"Royale":"Clash");
	}
	return 0;
}