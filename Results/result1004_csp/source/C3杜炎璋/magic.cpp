#include<bits/stdc++.h>
using namespace std;
int c[100005],a[100005][5],vis[200005],tot,v[200005],minn=1e9;
vector<int> Q[200005];
vector<pair<int,int> > W[200005];
map<pair<int,int> ,int> ma;
void dfs(int x,int g) {
	vis[x]=g;
	for(int i=0;i<Q[x].size();i++) {
		int to=Q[x][i];
		if(vis[to]) continue;
		dfs(to,g);
	}
}
void dfs1(int x,int ans,int len) {
	if(len==tot) minn=min(minn,ans);
	if(ans>minn) return ;
	for(int i=0;i<W[x].size();i++) {
		int to=W[x][i].first;
		if(ma[{min(to,x),max(to,x)}]) continue;
		ma[{min(to,x),max(to,x)}]=1;
		dfs1(x,ans+W[x][i].second,len+1);
		ma[{min(to,x),max(to,x)}]=0;
	}
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int n,flag=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&c[i]);
		if(c[i]>1) flag=1;
		for(int j=1;j<=4;j++) scanf("%d",&a[i][j]);
		Q[a[i][1]].push_back(a[i][2]);
		Q[a[i][2]].push_back(a[i][1]);
		Q[a[i][3]].push_back(a[i][4]);
		Q[a[i][4]].push_back(a[i][3]);
	}
	for(int i=1;i<=2*n;i++) {
		if(!vis[i]) dfs(i,++tot);
	}
	if(!flag) {
		printf("%d\n",tot-1);
		return 0;
	}
	for(int i=1;i<=n;i++) {
		W[vis[a[i][1]]].push_back({vis[a[i][3]],c[i]});
		W[vis[a[i][3]]].push_back({vis[a[i][1]],c[i]});
	}
	dfs1(1,0,1); 
	printf("%d",minn);
	return 0;
}

