#include<bits/stdc++.h>
using namespace std;
const int N=4e3+5,mod=998244353;
int n,res;
char G0[N][N];
vector<pair<int,int> >dot;
map<pair<int,int>,int>G;
void dfs(int u)
{
	if(u==dot.size())
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					if(G[{i,j}]&&G[{j,k}]&&G[{k,i}])res++;
					if(res>=mod)res-=mod;
				}
			}
		}
		return;
	}
	G[{dot[u].first,dot[u].second}]=1;
	dfs(u+1);
	G[{dot[u].first,dot[u].second}]=0;
	G[{dot[u].second,dot[u].first}]=1;
	dfs(u+1);
	G[{dot[u].second,dot[u].first}]=0;
}
int main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",G0[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(G0[i][j]=='0'&&G0[j][i]=='0')dot.push_back({i,j});
			else if(G0[i][j]=='1')G[{i,j}]=1;
			else if(G0[j][i]=='1')G[{j,i}]=1;
		}
	}
	dfs(0);
	printf("%d",res);
	return 0;
}
