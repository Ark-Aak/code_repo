#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5,K=55;
typedef long long LL;
typedef pair<LL,int> PLI;
int n,m,color[N],st[N];
char s[K][K];
LL dist[N]; 
vector<int>V[K];
int dijkstra()
{
	priority_queue<PLI,vector<PLI>,greater<PLI> >q;
	q.push({dist[1]=0,1}); 
	while(q.size())
	{
		PLI u=q.top();
		q.pop();
		int ver=u.second;
		LL dis=u.first;
		if(st[ver])continue;
		st[ver]=1;
		for(int c=1;c<=m;c++)
		{
			if(s[color[ver]][c]=='0')continue;
			for(auto j:V[c])
			{
				if(dist[j]>dis+abs(j-ver))
				{
					dist[j]=dis+abs(j-ver);
					if(!st[j])q.push({dist[j],j});
				}
			}
		}
	}
	return (dist[n]==1e18?-1:dist[n]);
} 
int main()
{
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&color[i]);
		V[color[i]].push_back(i);
		dist[i]=1e18;
	}
	for(int i=1;i<=m;i++)scanf("%s",s[i]+1);
	printf("%lld",dijkstra());
	return 0;
} 
