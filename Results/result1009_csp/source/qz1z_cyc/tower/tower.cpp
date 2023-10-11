#include<bits/stdc++.h>
using namespace std;
long long n,k,b[50004],a[52][52],dp[50004],g[52][50005],dis[50005],vis[50005],u[5000005],v[5000005],w[5000005],head[50005],net[5000005];
long long tot[52],tt;
char c;
priority_queue<pair<int,int>> q;
int main()
{
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		dis[i]=99999999;
		head[i]=-1;
		net[i]=-1;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		g[b[i]][0]++;
		g[b[i]][g[b[i]][0]]=i;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cin>>c;
			a[i][j]=c-'0';
		}
		tot[i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(a[b[i]][j]==1)
			{
				while(g[j][tot[j]]<=i&&tot[j]<=g[j][0]) tot[j]++;
				if(tot[j]>g[j][0]) continue;
				tt++;
				u[tt]=i;
				v[tt]=g[j][tot[j]];
				w[tt]=abs(g[j][tot[j]]-i);
				net[tt]=head[u[tt]];
				head[u[tt]]=tt;
			}
		}
	}
	for(int i=1;i<=k;i++) tot[i]=g[i][0];
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=k;j++)
		{
			if(a[b[i]][j]==1)
			{
				while(g[j][tot[j]]>=i&&tot[j]>=1)
				{
					tot[j]--;
				}
				if(tot[j]<=0) continue;
				tt++;
				u[tt]=i;v[tt]=g[j][tot[j]];w[tt]=abs(g[j][tot[j]]-i);
				net[tt]=head[u[tt]];
				head[u[tt]]=tt;
			}
		}
	}
	dis[1]=0;
	q.push(make_pair(-dis[1],1));
	while(!q.empty())
	{
		int uu=q.top().second;
		q.pop();
		if(vis[uu]==1) continue;
		vis[uu]=1;
		for(int i=head[uu];i!=-1;i=net[i])
		{
			if(dis[v[i]]>dis[uu]+w[i])
			{
				dis[v[i]]=dis[uu]+w[i];
				q.push(make_pair(-dis[v[i]],v[i]));
			}
		}
	}
	cout<<dis[n];
	return 0;
}
