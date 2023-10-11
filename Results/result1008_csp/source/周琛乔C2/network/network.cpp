#include<bits/stdc++.h>
using namespace std;
const int N=4005;
inline void read(int &x){
	x=0;int f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) x=(x<<1)+(x<<3)+c-48,c=getchar();
	x*=f;
}
int head[N],to[N<<1],nxt[N<<1],tot;
inline void add(int x,int y){
	to[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int n,m,x;
char s[5];
int f[N],dep[N],up[N],J[N],cnt,xl[N],cnt2,lca[N][N];
int Up(int x){return up[x]==x?x:up[x]=Up(up[x]);}
bool jc[N];
void dfs(int p,int fa){
	f[p]=fa;dep[p]=dep[fa]+1;
	xl[++cnt2]=p;int dfn=cnt2;
	lca[p][p]=p;
	for(int o=head[p];o;o=nxt[o])
		if(to[o]^fa){
			int pre=cnt2;
			dfs(to[o],p);
			for(int i=dfn;i<=pre;i++)
			for(int j=pre+1;j<=cnt2;j++)
				lca[xl[i]][xl[j]]=lca[xl[j]][xl[i]]=p;
		}
}
int ans;
inline void solve(int x,int y){
	int Lca=lca[x][y];
	x=up[x],y=up[y];
	while(dep[x]>=dep[Lca]) ans=min(ans,x),up[x]=Up(f[x]),x=up[x];
	while(dep[y]>=dep[Lca]) ans=min(ans,y),up[y]=Up(f[x]),y=up[y];
}
int main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	read(n),read(m);
	for(int i=1,u,v;i<n;i++){
		read(u),read(v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	while(m--){
		scanf("%s",s);
		read(x);
		if(s[0]=='J'){
			if(!jc[x]) jc[x]=1,J[++cnt]=x;
		}else{
			for(int i=1;i<=n;i++) up[i]=i;
			ans=N;
			for(int i=1;i<=cnt;i++) solve(x,J[i]);
			printf("%d\n",ans);
		}
	}
	return 0;
}

