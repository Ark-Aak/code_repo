#include<bits/stdc++.h>
#define N 100005
#define ls p<<1
#define rs p<<1|1
#define mid (l+r>>1)
using namespace std;
int n,m,fa[20][N],L[N],R[N],de[N],cnt,t[N*4],la[N*4],ans,val[N];
struct z{
	int l,r,w;
};
vector<int>b[N];
vector<z>qr[N];
void dfs(int x,int p){
	L[x]=++cnt,fa[0][x]=p,de[x]=de[p]+1;
	for(int i=0;i<b[x].size();i++){
		int y=b[x][i];
		if(y==p)continue;
		dfs(y,x);
	}R[x]=cnt;
}
void down(int p){
	if(!la[p])return;
	t[ls]+=la[p],la[ls]+=la[p];
	t[rs]+=la[p],la[rs]+=la[p];
	la[p]=0;
}
void update(int p,int l,int r,int L,int R,int w){
	if(l==L&&r==R){
		t[p]+=w,la[p]+=w;
		return;
	}down(p);
	if(R<=mid)update(ls,l,mid,L,R,w);
	else if(L>mid)update(rs,mid+1,r,L,R,w);
	else update(ls,l,mid,L,mid,w),update(rs,mid+1,r,mid+1,R,w);
	t[p]=max(t[ls],t[rs]);
}
bool in(int x,int y){
	return L[x]>=L[y]&&L[x]<=R[y];
}
void qur(int x,int p){
	for(int i=0;i<qr[x].size();++i)update(1,1,n,qr[x][i].l,qr[x][i].r,qr[x][i].w);
	if(val[x])update(1,1,n,L[x],R[x],-val[x]),update(1,1,n,1,n,val[x]);
	ans=max(ans,t[1]);
	for(int i=0;i<b[x].size();++i){
		int v=b[x][i];
		if(v==p)continue;
		if(val[x])update(1,1,n,L[v],R[v],-val[x]);
		qur(v,x);
		if(val[x])update(1,1,n,L[v],R[v],val[x]);
	}
	if(val[x])update(1,1,n,L[x],R[x],val[x]),update(1,1,n,1,n,-val[x]);
	for(int i=0;i<qr[x].size();++i)update(1,1,n,qr[x][i].l,qr[x][i].r,-qr[x][i].w);
}
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>n>>m;
	for(int x,y,i=1;i<n;i++)scanf("%d%d",&x,&y),b[x].push_back(y),b[y].push_back(x);
	dfs(1,0);
	for(int i=1;i<20;++i)for(int j=1;j<=n;++j)fa[i][j]=fa[i-1][fa[i-1][j]];
	for(int i=1,x,y,w;i<=m;++i){
		scanf("%d%d%d",&x,&y,&w);
		if(x==y)update(1,1,n,L[x],R[x],w),val[x]+=w;
		else if(in(y,x)){
			update(1,1,n,L[y],R[y],w);
			int tp=y;
			for(int j=19;j>=0;--j)if(de[fa[j][tp]]>de[x])tp=fa[j][tp];
			qr[tp].push_back((z){L[y],R[y],-w});
		}else if(in(x,y)){
			int tp=x;
			for(int j=19;j>=0;--j)if(de[fa[j][tp]]>de[y])tp=fa[j][tp];
			qr[x].push_back((z){1,n,w});
			qr[x].push_back((z){L[tp],R[tp],-w});
		}else qr[x].push_back((z){L[y],R[y],w});
	}qur(1,0);
	cout<<ans;
}