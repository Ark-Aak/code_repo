#include<bits/stdc++.h>
using namespace std;
int m,k,p;
int x,y,z;
const int M=2e3+5;
struct line{
	int to,link,w;
}E[M<<1];
int head[M],tot;
void addE(int u,int v,int w){
	E[++tot].to=v;
	E[tot].link=head[u];
	E[tot].w=w;
	head[u]=tot;
	return;
}
long long dep[M],vdep[M],fa[M];
bool vis[M];
void dfs(int now,int f){
	vis[now]=1;
	fa[now]=f;
	for(int i=head[now];i;i=E[i].link){
		if(E[i].to^f){
			dep[E[i].to]=dep[now]+1;
			vdep[E[i].to]=vdep[now]+E[i].w;
			dfs(E[i].to,now);
		}
	}
	return;
}
int LCA(int u,int v){
	if(dep[u]>dep[v])swap(u,v);
	while(dep[u]<dep[v])v=fa[v];
	while(u!=v)u=fa[u],v=fa[v];
	return u;
}
int main(int argc,char **argv){
	if(argc!=4)return cerr<<"UKE\n",0;
#define in argv[1]
#define out argv[2]
#define ans argv[3]
	ifstream IN(in),OUT(out),ANS(ans);
	if(!(IN.good()&&ANS.good()&&OUT.good()))return cerr<<"UKE\n",0;
	IN>>m;OUT>>k;ANS>>p;
	if((k<=1||k>2000)&&k!=-1)return cerr<<"WA,type=3\n",0;
	if(k*p<0)return cerr<<"WA,type=1\n",0;
	if(k==-1)return cerr<<"OK\n",0;
	for(int i=1;i<=k-1;i++){
		OUT>>x>>y>>z;
		if(z>=m||z<=0||x<=0||x>k||y<=0||y>k)return cerr<<"WA,type=3\n",0;
		addE(x,y,z);
		addE(y,x,z);
	}
	dfs(1,0);
	for(int i=1;i<=k;i++)if(!vis[k])return cerr<<"WA,type=3\n",0;
	for(int i=1;i<k;i++){
		int lca=LCA(i,i+1);
		long long val=vdep[i]+vdep[i+1]-vdep[lca]*2;
		if(val%m)return cerr<<"WA,type=2 "<<i<<"\n",0;
	}
	cerr<<"OK\n";
	return 0;
}
