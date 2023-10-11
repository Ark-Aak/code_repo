#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int u,v,w;
}edge[500005];
bool cmp(node A,node B){return A.w>B.w;}
int vis[500005];
int f[500005][2];//0是Bob操作,1是Alice操作 
signed main(){
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d %d %d",&edge[i].u,&edge[i].v,&edge[i].w);
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(vis[edge[i].u]==0&&vis[edge[i].v]==0){
			f[edge[i].u][0]=1;
			f[edge[i].v][0]=1;
			f[edge[i].u][1]=1;
			f[edge[i].v][1]=1;
			vis[edge[i].u]=1;
			vis[edge[i].v]=1;
		}else if(vis[edge[i].u]==0&&vis[edge[i].v]==1){
			f[edge[i].u][0]=f[edge[i].v][1]+1;
			f[edge[i].u][1]=f[edge[i].v][0]+1;
			f[edge[i].v][0]=1;
			vis[edge[i].u]=1;
		}else if(vis[edge[i].u]==1&&vis[edge[i].v]==0){
			f[edge[i].v][0]=f[edge[i].u][1]+1;
			f[edge[i].v][1]=f[edge[i].u][0]+1;
			f[edge[i].u][0]=1;
			vis[edge[i].v]=1;
		}else{
			int tmp_1[2]={f[edge[i].u][0],f[edge[i].u][1]};
			int tmp_2[2]={f[edge[i].v][0],f[edge[i].v][1]};
			f[edge[i].u][0]=min(f[edge[i].u][0],tmp_2[1]+1);
			f[edge[i].u][1]=max(f[edge[i].u][1],tmp_2[0]+1);
			f[edge[i].v][0]=min(f[edge[i].v][0],tmp_1[1]+1);
			f[edge[i].v][1]=max(f[edge[i].v][1],tmp_1[0]+1);
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",f[i][1]);
	return 0;
}
