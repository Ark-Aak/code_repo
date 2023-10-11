#include<bits/stdc++.h>
using namespace std;
long long n,k,b[50005],s[55][55],dis[50005],vis[50005],sum,pos,aa,bb,top[55],kk[55][50005],ls;
priority_queue<pair<int,int> >q;
char cc;
vector<long long> G[50005],kl[55];
int main()
{
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) dis[i]=11451419198; 
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
		top[b[i]]++;
		kl[b[i]].push_back(i);
	}
	for(int i=1;i<=k;i++)
	{
		ls=0;
		kk[i][0]=-1;
		for(int j=1;j<=n;j++)
		{
			if(j==kl[i][ls]) 
			{
				kk[i][j]=ls;
				ls++;
			}
			else
			{
				kk[i][j]=kk[i][j-1];
			}
		}
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=k;j++)
		{
			cin>>cc;
			s[i][j]=cc-'0';
			if(s[i][j]==1)
			{
				if(i!=j)
				{
					for(int h=0;h<kl[i].size();h++)
					{
						if(kk[j][kl[i][h]]>=0) G[kl[i][h]].push_back(kl[j][kk[j][kl[i][h]]]);
						if(kk[j][kl[i][h]]+1<kl[j].size()) G[kl[i][h]].push_back(kl[j][kk[j][kl[i][h]]+1]);
					}
				 } 
				else
				{
					for(int h=0;h<kl[i].size();h++)
					{
						if(kk[j][kl[i][h]]-1>=0) G[kl[i][h]].push_back(kl[j][kk[j][kl[i][h]]]-1);
						if(kk[j][kl[i][h]]+1<kl[j].size()) G[kl[i][h]].push_back(kl[j][kk[j][kl[i][h]]+1]);
					}
				}
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<i<<": ";
//		for(int j=0;j<G[i].size();j++)
//		{
//			cout<<G[i][j]<<" ";
//		}
//		cout<<endl;
//	 } 
	dis[1]=0;
	q.push(make_pair(-dis[1],1));
	while(!q.empty())
	{
		sum=-q.top().first;
		pos=q.top().second;
		q.pop();
		if(vis[pos]==1) continue;
		vis[pos]=1;
		for(int i=0;i<G[pos].size();i++)
		{
			if(dis[pos]+abs(G[pos][i]-i)<dis[G[pos][i]])
			{
				dis[G[pos][i]]=dis[pos]+abs(G[pos][i]-pos);
				q.push(make_pair(-dis[G[pos][i]],G[pos][i]));
			}
		}
	}
	if(dis[n]!=11451419198) cout<<dis[n];
	else cout<<"-1";
	return 0;
 } 
