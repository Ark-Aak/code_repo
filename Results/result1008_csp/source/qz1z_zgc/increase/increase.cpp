#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
vector<pair<int,int> >edge[N];
int dfs(int u,int cur,int last)
{
	if(!cur)
	{
		pair<int,int>go={0,1e9};
		for(int i=0;i<edge[u].size();i++)
		{
			if(edge[u][i].second>last&&go.second>edge[u][i].second)go=edge[u][i];
		}
		if(!go.first)return 0;
		else return dfs(go.first,cur^1,go.second)+1;
	}
	else
	{
		pair<int,int>go={0,-1e9};
		for(int i=0;i<edge[u].size();i++)
		{
			if(go.second<edge[u][i].second)go=edge[u][i];
		}
		if(!go.first||last>=go.second)return 0;
		else return dfs(go.first,cur^1,go.second)+1;
	}
}
int main()
{
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		edge[a].push_back({b,c});
		edge[b].push_back({a,c});
	}
	for(int i=1;i<=n;i++)printf("%d ",dfs(i,0,0));
	return 0;
}
