#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=500005;
int n,m;
struct XXX{
	int u,v,w;
}z[N];
bool cmp(XXX x,XXX y){
	return x.w>y.w;
}
int ans[N][2];
int anss[N];
vector<pair<int,int> >q[N],qq[N];
int f[N][2];
bool vis[N];
/*
void dfs(int x,int val,int sh){
bool flag=0;
	for(int i=0;i<q[x].size();i++){
		int y=q[x][i].first,id=q[x][i].second;
		if(z[id].w>=z[val].w) continue;
		flag=1;
		vis[id]=1;
		f[id][1]=max(f[id][1],sh+1);
		dfs(y,id,f[id][1]);
	}
	for(int i=0;i<qq[x].size();i++){
		int y=qq[x][i].first,id=qq[x][i].second;
		if(z[id].w>=z[val].w) continue;
		flag=1;
		vis[id]=1;
		f[id][0]=max(f[id][0],sh+1);
		dfs(y,id,f[id][0]);
	}
}*/
int dfs2(int x,int val,int aorb){
	int Max=0,Min=1e16;
	for(int i=0;i<q[x].size();i++){
		int y=q[x][i].first,id=q[x][i].second;
		if(z[id].w<=val) continue;
		ans[y][1-aorb]=dfs2(y,z[id].w,1-aorb);
		Max=max(Max,ans[y][1-aorb]+1);
		Min=min(Min,ans[y][1-aorb]+1);
	}
	for(int i=0;i<qq[x].size();i++){
		int y=qq[x][i].first,id=qq[x][i].second;
		if(z[id].w<=val) continue;
		ans[y][1-aorb]=dfs2(y,z[id].w,1-aorb);
		Max=max(Max,ans[y][1-aorb]+1);
		Min=min(Min,ans[y][1-aorb]+1);
	}
	//cout<<val<<" "<<x<<' '<<aorb<<" "<<Max<<" "<<Min<<endl;
	if(aorb==0){
		return Max;
	}
	else if(Min==1e16){
		return 0;
	}
	else return Min;
}
signed main() {
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&z[i].u,&z[i].v,&z[i].w);
	}
	sort(z+1,z+m+1,cmp);
	for(int i=1;i<=m;i++){
		q[z[i].u].push_back(make_pair(z[i].v,i));
		qq[z[i].v].push_back(make_pair(z[i].u,i));
	}
	/*for(int i=1;i<=m;i++)
		f[i][0]=f[i][1]=0;
	for(int i=1;i<=m;i++){
		if(!vis[i]){
			vis[i]=1;
			f[i][0]=f[i][1]=0;
			dfs(z[i].u,i,0);
			dfs(z[i].v,i,0);
		}
	}*/
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<=n;i++){
		anss[i]=max(anss[i],dfs2(i,0,0));
		//	cout<<endl; 
	}
	for(int i=1;i<=n;i++){
		printf("%lld ",anss[i]);
	}
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 

