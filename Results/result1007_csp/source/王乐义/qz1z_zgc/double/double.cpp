#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long LL;
int n,m,st[N];
vector<pair<int,LL> >G[N<<1];
void add(int a,int b,LL c)
{
	G[a].push_back({b,c});
	G[b].push_back({a,c});
}
LL dfs(int u,int T,int father)
{
	if(u==T)return 0;
	LL res=1e18;
	for(int i=0;i<G[u].size();i++)
	{
		int j=G[u][i].first;
		LL w=G[u][i].second;
		return dfs(j,T,u)+w;
	}
}
int main()
{
	freopen("double.in","r",stdin);
	freopen("double.out","w",stdout);
	scanf("%d",&n); 
	for(int i=1;i<=n;i++)
	{
		LL w;
		scanf("%lld",&w);
		add(2*i-1,2*i,w);
	}
	for(int i=1;i<n;i++)
	{
		int a,b;
		LL c,d;
		scanf("%d%d%lld%lld",&a,&b,&c,&d);
		add(2*a-1,2*b-1,c);
		add(2*a,2*b,d);
	}
	scanf("%d",&m);
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%lld\n",dfs(a,b,-1));
	}
	return 0;
}
