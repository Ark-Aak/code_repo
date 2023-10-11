#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
typedef pair<int,int>PII;
int n,res,a[N][N];
char d[N][N];
vector<pair<pair<PII,PII>,int> >match;
map<PII,int>mp;
void dfs(int u,int ans)
{
	if(u==match.size())
	{
		res=(res+ans)%mod;
		return;
	}
	dfs(u+1,ans);
	if(!mp[{match[u].first.first}]&&!mp[{match[u].first.second}])
	{
		mp[{match[u].first.first}]=1;
		mp[{match[u].first.second}]=1;
		dfs(u+1,ans+match[u].second);
		mp[{match[u].first.first}]=0;
		mp[{match[u].first.second}]=0;
	}
}
int main()
{
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",d[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(d[i][j]=='R'&&d[i][k]=='L')match.push_back({{{i,j},{i,k}},a[i][j]+a[i][k]});
				if(d[j][i]=='D'&&d[k][i]=='U')match.push_back({{{j,i},{k,i}},a[j][i]+a[k][i]});
			}
		}
	}
	dfs(0,0);
	printf("%d",res);
	return 0;
}
