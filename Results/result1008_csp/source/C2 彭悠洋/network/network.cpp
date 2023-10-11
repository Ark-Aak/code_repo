#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int n,q,cnt,fir,f[N][21],mn[N][21],dep[N],ans = 2e9;
bool vis[N];
vector<int> g[N];
void dfs(int u,int fa)
{
	f[u][0] = fa,mn[u][0] = min(u,fa),dep[u] = dep[fa]+1;
	if(fa==0) mn[u][0] = u;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
	}
}
int get_mn(int x,int y)
{
	int res = min(x,y);
	if(dep[x]<dep[y]) swap(x,y);
	for(int j = 20;~j;j--)
		if(dep[f[x][j]]>=dep[y])
			res = min(res,mn[x][j]),x = f[x][j];
	if(x==y) return res;
	for(int j = 20;~j;j--)
		if(f[x][j]!=f[y][j])
			res = min({res,mn[x][j],mn[y][j]}),x = f[x][j],y = f[y][j];
	res = min(res,mn[x][0]);
	return res;
}
signed main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	memset(mn,0x3f,sizeof mn);
	for(int i = 1,u,v;i<n;i++)
		cin>>u>>v,g[u].push_back(v),g[v].push_back(u);
	dfs(1,0);
	for(int j = 1;j<=20;j++)
		for(int i = 1;i<=n;i++)
			f[i][j] = f[f[i][j-1]][j-1],mn[i][j] = min(mn[i][j-1],mn[f[i][j-1]][j-1]);
	while(q--)
	{
		string op;int x;
		cin>>op>>x;
		if(op[0]=='J')
		{
			if(!fir) fir = x;
			else ans = min(ans,get_mn(x,fir));
		}
		else cout<<min(ans,get_mn(x,fir))<<'\n';
	}
	return 0;
}

