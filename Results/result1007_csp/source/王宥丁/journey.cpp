#include<bits/stdc++.h>
using namespace std;
#define int long long
struct abc{
	int v,val;
};
vector<abc>e[1010];
bool vis[1010];
int dfs(int x,int y,int u,int v)
{
	if(vis[u])
	{
		return 0;
	}
	vis[u]=1;
	if(x>y)
	{
		return 0;
	}
	if(u==v)
	{
		return 1;
	}
	int flag=0;
	for ( int i = 0 ; i < e[u].size() ; i++ )
	{
		int k=e[u][i].v,val=e[u][i].val;
		if(val<x)
		{
			continue;
		}
		flag=dfs(val,y,k,v);
		if(flag)
		{
			return 1;
		}
	}
}
signed main()
{
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	int n,m,q;
	cin >> n >> m >> q;
	for ( int i = 1 ; i <= m ; i++ )
	{
		int u,v,val;
		cin >> u >> v ;
		abc p;
		p.v=v;
		p.val=i;
		e[u].push_back(p);
		p.v=u;
		e[v].push_back(p); 
	}
	while(q--)
	{
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		memset(vis,0,sizeof(vis));
		int k=dfs(a,b,c,d);
		if(k==1)
		{
			cout << "Yes"<<endl;
		}else{
			cout << "No" << endl;
		}
	}
	return 0;
}
/*
5 4 6
1 2
2 3
3 4
3 5
1 3 1 4
1 3 2 4
1 4 4 5
1 4 4 1
2 3 1 4
2 2 2 3
*/
