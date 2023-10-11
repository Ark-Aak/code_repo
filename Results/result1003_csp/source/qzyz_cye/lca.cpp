#include<bits/stdc++.h>
using namespace std;
long long n,u[500005],v[500005],dp[500005],sum[500005],ans,ls;
vector<long long>G[500005];
unordered_map<long long,long long> mp[500005];
void dfs(int x,int fa)
{
//cout<<x<<endl;
	for(int i=0;i<G[x].size();i++)
	{
		if(G[x][i]!=fa) 
		{
			dfs(G[x][i],x);
			sum[x]+=sum[G[x][i]]+1;
			mp[x][G[x][i]]=sum[G[x][i]]+1;
		}
	}
	return ;
} 
//void rdfs(int x,int fa,long long ss)
//{
//	for(int i=0;i<G[x].size();i++)
//	{
//		if(G[x][i]!=fa) rdfs(G[x][i],x,ss+sum[x]-mp[x][G[x][i]]+1);
//	}
//	sum[x]+=ss;
//	mp[x][fa]=ss;
//} 
void work(int x,int fa)
{
//cout<<x<<" "<<sum[x]<<endl;
	ls=0;
	for(int i=0;i<G[x].size();i++)
	{
		if(G[x][i]!=fa) 
		{
			ls+=(sum[x]-mp[x][G[x][i]])*mp[x][G[x][i]];
			mp[x][G[x][i]]=0;
		}
		
	}
	//if(kk==1) cout<<x<<" "<<sum[x]<<endl;
	ls+=sum[x]*2+1;
	sum[x]=0;
	
	ans+=ls*x;
	for(int i=0;i<G[x].size();i++)
	{
		if(G[x][i]!=fa) work(G[x][i],x);
	}
} 
void answer(int x)
{
	ls=0;
}
int main()
{
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&u[i],&v[i]);
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]); 
	}
	for(int i=1;i<=n;i++)
	{
		ans=0;
		dfs(i,0);
	//rdfs(1,0,0);
		work(i,0);
		printf("%lld\n",ans);
	}
//	
//	
//	for(int i=1;i<=n;i++)
//	{
//		answer(i);
//	}
	return 0;
} 
//14+3+12+4+5+2+1
