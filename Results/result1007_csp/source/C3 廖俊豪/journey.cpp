#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int u,v;
}edge[200005];
struct Node{
	int l,r,s,t,ops,id;
}query[1000005];
bool cmp(Node A,Node B){
	return A.l<B.l;
}
bool CMP(Node A,Node B){
	return A.id<B.id;
}
int dis[1005][1005];
signed main(){
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	memset(dis,0x7f,sizeof dis);
	int q;
	scanf("%d %d %d",&n,&m,&q);
//	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=m;i++)scanf("%d %d",&edge[i].u,&edge[i].v);
	for(int i=1;i<=q;i++){scanf("%d %d %d %d",&query[i].l,&query[i].r,&query[i].s,&query[i].t);query[i].id=i;}
	sort(query+1,query+q+1,cmp);
	int now=q;
	for(int i=m;i>=1;i--){
		dis[edge[i].u][edge[i].v]=i;
		dis[edge[i].v][edge[i].u]=i;
		for(int j=1;j<=n;j++){
			dis[edge[i].u][j]=min(dis[edge[i].u][j],dis[edge[i].v][j]);
			dis[edge[i].v][j]=min(dis[edge[i].v][j],dis[edge[i].u][j]);
		}
		while(query[now].l==i&&now>0){
//			cout<<dis[query[now].s][query[now].t]<<endl;
			if(dis[query[now].s][query[now].t]>query[now].r&&query[now].s!=query[now].t){
				query[now].ops=0;
			}else{
				query[now].ops=1;
			}
			now--;
		}
	}
	sort(query+1,query+q+1,CMP);
	for(int i=1;i<=q;i++){
		if(query[i].ops)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
} 
