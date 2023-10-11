#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=(x<<3)+(x<<1)+ch-48;ch=getchar();}
	return x*f;
}
int n,q,root=-1,sum=1e9;
vector<int>to[1000005];
int dep[1000005];
int f[1000005][21],fa[1000005][21];
void dfs(int x,int p){
	dep[x]=dep[p]+1;
	fa[x][0]=p;
	f[x][0]=min(x,p);
	for(auto y:to[x]){
		if(y==p)continue;
		dfs(y,x);
	}
	return;
}
char ops[6];
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)
		if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int w(int x,int y){
	int sum=1e9;
	int Lca=lca(x,y);
	for(int i=20;i>=0;i--){
		if(dep[fa[x][i]]>=dep[Lca]){
			sum=min(sum,f[x][i]);
			x=fa[x][i];
		}
		if(dep[fa[y][i]]>=dep[Lca]){
			sum=min(sum,f[y][i]);
			y=fa[y][i];
		}
	}
	return sum;
}
signed main(){
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	n=read();q=read();
	for(int i=1;i<n;i++){
		int u=read();
		int v=read();
		to[u].push_back(v);
		to[v].push_back(u); 
	}
	dfs(1,0);
	for(int i=0;i<20;i++)
		for(int j=1;j<=n;j++){
			fa[j][i+1]=fa[fa[j][i]][i];
			f[j][i+1]=min(f[j][i],f[fa[j][i]][i]);
		}
	while(q--){
		int x;
		scanf("%s %d",ops,&x);
		if(ops[0]=='J'){
			if(root==-1)root=x,sum=x;
			else{
				sum=min(sum,w(x,root));
				root=lca(x,root);
			}
		}else{
			printf("%d\n",min(w(x,root),sum));
		}
	}
}
