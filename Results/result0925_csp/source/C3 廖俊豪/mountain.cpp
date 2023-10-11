#include<bits/stdc++.h>
using namespace std;
int n,tot;
int a[1000005];
int fa[1000005];
int siz[1000005];
int vis[1000005];
struct node{
	int w,s,ans,num;
}p[1000005];
bool cmp(node A,node B){
	return A.s<B.s;
}
bool CMP(node A,node B){
	return A.w<B.w;
}
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void meg(int x,int y){
	x=find(x);
	y=find(y);
	if(siz[x]<siz[y])swap(x,y);
	fa[y]=x;
	siz[x]+=siz[y];
}
void sol(int x){
	p[x].ans=p[x].num-1;
	if(vis[p[x].w-1]){p[x].ans+=siz[find(p[x].w-1)];meg(p[x].w,p[x].w-1);}
	if(vis[p[x].w+1]){p[x].ans+=siz[find(p[x].w+1)];meg(p[x].w,p[x].w+1);}
}
signed main(){
	freopen("mountain.in","r",stdin);
	freopen("mountain.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){tot++;p[tot]=node{tot,a[i],0,0};}
		p[tot].num++;
	}
	for(int i=1;i<=tot;i++){
		fa[i]=i;
		siz[i]=p[i].num;
	}
	sort(p+1,p+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		sol(i);
		vis[p[i].w]=1;
	}
	sort(p+1,p+tot+1,CMP);
	for(int i=1;i<=tot;i++)
		for(int j=1;j<=p[i].num;j++)
			printf("%d\n",p[i].ans);
	return 0;
} 
