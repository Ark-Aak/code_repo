#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int Inf=1e18;
int n,m,c,ans;
int a[1005];
vector<int>to[1005];
int f[2][1005];
signed main(){
	freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		to[u].push_back(v);
	}
	for(int i=2;i<=n;i++)f[0][i]=-Inf;
	for(int i=1;i<=1000;i++){
		for(int j=1;j<=n;j++)f[i&1][j]=-Inf;
		for(int x=1;x<=n;x++)for(auto y:to[x])
			f[i&1][y]=max(f[i&1][y],f[1-(i&1)][x]+a[y]);
		ans=max(ans,f[i&1][1]-c*i*i);
	}
	cout<<ans;
	return 0;
} 
