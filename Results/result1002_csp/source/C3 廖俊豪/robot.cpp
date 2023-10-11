#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>to[120005];
int dep[120005];
int fa[120005][25];
void dfs(int x,int p){
	dep[x]=dep[p]+1;
	fa[x][0]=p;
	for(auto y:to[x]){
		if(y==p)continue;
		dfs(y,x);
	}
}
void Init(){
	for(int j=0;j<=19;j++)
		for(int i=1;i<=n;i++)
			fa[i][j+1]=fa[fa[i][j]][j];
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)
		if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int p[505],q[505];
bool check(int x,int y){
	int lca_x=lca(p[x],q[x]);
	int lca_y=lca(p[y],q[y]);
	int lca_px_qy=lca(p[x],q[y]);
	int lca_px_py=lca(p[x],p[y]);
	int lca_qx_py=lca(q[x],p[y]);
	int lca_qx_qy=lca(q[x],q[y]);
//	printf("lca_x: %d\n",lca_x);
//	printf("lca_y: %d\n",lca_y);
//	printf("lca_px_qy: %d\n",lca_px_qy);
//	printf("lca_px_py: %d\n",lca_px_py);
//	printf("lca_qx_py: %d\n",lca_qx_py);
//	printf("lca_qx_qy: %d\n",lca_qx_qy);
	if((lca_x==p[x]||lca_x==q[x])&&lca_px_py==p[x]&&lca_qx_py==q[x]&&dep[lca_y]<=max(dep[p[x]],dep[q[x]]))return 1;//和半条路径重合了 
	if((lca_x==p[x]||lca_x==q[x])&&lca_px_qy==p[x]&&lca_qx_qy==q[x]&&dep[lca_y]<=max(dep[p[x]],dep[q[x]]))return 1;
//	cout<<"路径完成"<<endl; 
	if(lca_x!=lca_y)return 0;
	if(lca_px_py==p[x]&&lca_qx_qy==q[x])return 1;
	if(lca_px_py==p[y]&&lca_qx_qy==q[y])return 1;
	if(lca_px_qy==p[x]&&lca_qx_py==q[x])return 1;
	if(lca_px_qy==p[y]&&lca_qx_py==q[y])return 1;
	if(lca_px_qy==q[y]&&lca_qx_py==q[x])return 1;
	return 0;
}
signed main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)to[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d %d",&u,&v);
			to[u].push_back(v);
			to[v].push_back(u);
		}
		int ops=1;
		dfs(1,0);
		Init();
		scanf("%d",&m);
		for(int i=1;i<=m;i++)scanf("%d %d",&p[i],&q[i]);
		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				if(check(i,j)){
					ops=0;
					printf("No\n");
					i=m+1;
					break;
				}
			}
		}
		if(ops)printf("Yes\n");
	}
	return 0;
} 
