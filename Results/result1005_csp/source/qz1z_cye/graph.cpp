#include<bits/stdc++.h>
using namespace std;
long long n,m,q,u,v,vis[100005],ls,ans,sum;
vector<int>L[100005],G[100005];
int work(int x,int hx)
{
	if(x==hx) 
	{
		vis[x]=2;
		return 2;
	}
	vis[x]=1;
	for(int i=0;i<G[x].size();i++)
	{
		if(G[x][i]==hx)
		{
			vis[x]=2;
			continue;
		}
		if(vis[G[x][i]]==0)
		{
			ls=work(G[x][i],hx);
			vis[x]=max(vis[x],ls);
		}
	}
	return vis[x];
}
void dfs(int x)
{
	sum++;
	vis[x]=1;
	for(int i=0;i<G[x].size();i++)
	{
		if(vis[G[x][i]]==0)
		{
			dfs(G[x][i]);
		}
	}
	return ;
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		ans=0;
		scanf("%lld%lld",&u,&v);
		for(int i=1;i<=n;i++) 
		{
			vis[i]=0;
		}
		work(u,v);
		vis[v]=2;
		for(int i=1;i<=n;i++) 
		{
			if(vis[i]==1) vis[i]=0;
//			if(vis[i]==2) cout<<i<<" ";
		}
	//	cout<<endl;
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				sum=0;
				dfs(i);
				ans=ans^sum;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 

