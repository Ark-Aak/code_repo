#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=1e5+7;
int n; 
struct node{
	int x,y;
}a[Maxn];
int tot,head[Maxn],ans;
struct edge1{
	int u,v,Next;
}Edge[Maxn];
inline void add(int u,int v){
	Edge[++tot]=(edge1){u,v,head[u]},head[u]=tot;
}
bool vis[Maxn];
void dfs(int u){
	vis[u]=1;
	for(int i=head[u];i;i=Edge[i].Next){
		if(!vis[Edge[i].v]) dfs(Edge[i].v);
	}
}
int main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y);
	if(n<=3000){
			for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j){
					if((a[i].x>=a[j].x&&a[i].y>=a[j].y)||(a[i].x<=a[j].x&&a[i].y<=a[j].y)){
						add(i,j);add(j,i);
					}	
				}
			for(int i=1;i<=n;i++) if(!vis[i]) ++ans,dfs(i);
			cout<<ans;
			return 0;
	}
	
	cout<<1;
	return 0;
}
/*
6
1 5
2 4
3 3
4 2
5 1
5 3
*/
