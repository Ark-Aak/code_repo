#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> q[500005];
int sz[5000050],f[500005],ans[500005],dep[500005];
void dfs1(int x,int fa) {
	dep[x]=dep[fa]+1;
	f[x]=fa;
	for(int i=0;i<q[x].size();i++) {
		int to=q[x][i];
		if(to==fa) continue;
		dfs1(to,x);
	}
} 
int lca(int x,int y) {
	while(x!=y) {
		if(dep[x]>dep[y]) x=f[x];
		else if(dep[x]<dep[y]) y=f[y];
		else if(dep[x]==dep[y] && x!=y) x=f[x],y=f[y];
		
		if(x==y) return x;
	}
	return 0;
}
signed main(){
	freopen("ex_lca.out","r",stdin);
	//freopen("lca.out","w",stdout);
	/*int n;
	scanf("%lld",&n);
	for(int i=1;i<n;i++) {
		int x,y;
		scanf("%lld %lld",&x,&y);
		q[x].push_back(y);
		q[y].push_back(x);
	}
	for(int i=1;i<=n;i++) {
		dfs1(i,0);
		int ans=0;
		for(int j=1;j<=n;j++) {
			for(int k=1;k<=n;k++) {
				ans+=lca(j,k);
			}
		}
		printf("%d\n",ans/2);
	}*/
	int n=499982;
	for(int i=1;i<=n*2;i++) {
		scanf("%lld",&sz[i]);
	}
	for(int i=1;i<=n;i++) {
		if(sz[i]!=sz[i+n]) {
			printf("%d SB",i);
			return 0;
		}
	}
	printf("6");
	return 0;
}
