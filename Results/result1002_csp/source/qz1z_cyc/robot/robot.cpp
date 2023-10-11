#include<bits/stdc++.h>
using namespace std;
int T,n,m,uu,vv,ff[120005],dis[120005][501],fk,u[501],v[501];
vector<int> G[120005];
void build(int x,int fa)
{
	for(int i=0;i<G[x].size();i++)
	{
		if(G[x][i]!=fa)
		{
			ff[G[x][i]]=x;
			build(G[x][i],x);
		}
	}
	return;
}
int main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	cin>>T;
	while(T--)
	{
		fk=0;
		cin>>n;
		ff[n]=n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++) dis[i][j]=0;
			G[i].clear();
		}
		for(int i=1;i<=n-1;i++)
		{
			ff[i]=i;
			scanf("%d%d",&uu,&vv);
			G[uu].push_back(vv);G[vv].push_back(uu);
		}
		build(1,0);
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u[i],&v[i]);
			dis[u[i]][i]=1;
			uu=u[i],vv=v[i];
			while(uu!=1) {
				dis[ff[uu]][i]=1;
				uu=ff[uu];
			}
			int fgg=0;
			while(vv!=1) {
				if(dis[vv][i]==1)
				{
					if(fgg==0) fgg=1;
					else dis[vv][i]==0;
				}
				else{dis[vv][i]=1;}
				vv=ff[vv];
				if(vv==1&&fgg==1) dis[1][i]=0;
			}
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i!=j)
				{
					if(dis[u[i]][i]==1&&dis[u[i]][j]==1&&dis[v[i]][i]==1&&dis[v[i]][j]==1)
					{
						fk=1;
						break;
					}
				}
				if(fk==1) break;
			}
			if(fk==1) break;
		}
		if(fk==0) cout<<"Yes"<<endl;
		else cout<<"N0"<<endl;
	}
	return 0;
}
