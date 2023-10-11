#include<bits/stdc++.h>
using namespace std;
struct node
{
	int nxt,to,val;
}e[2000005];
int head[50005],cnt;
void add(int u,int v,int w)
{
	e[++cnt].to=v;
	e[cnt].val=w;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int n,k;
int a[50005];
int vis[55][55];
vector<int>col[55];
int vis1[50005];
int dis[50005];
char c;
void dij()
{
	priority_queue<pair<int,int> >q;
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis1[u])
			continue;
		vis1[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
//			cout<<u<<" "<<v<<endl;
			if(dis[v]>dis[u]+e[i].val&&!vis1[v])
				dis[v]=dis[u]+e[i].val,q.push(make_pair(-dis[v],v));
		}
	}
}
int main()
{
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),col[a[i]].push_back(i);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
		{
			cin>>c;
			if(c=='1')
				vis[i][j]=1;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			if(vis[a[i]][j])
				for(int l=0;l<col[j].size();l++)
					add(i,col[j][l],abs(i-col[j][l]));
	dij();
	if(dis[n]==dis[0])
		cout<<-1;
	else
		cout<<dis[n];
	return 0;
}
/*
5 4
1 4 2 3 4
1010
0001
0110
0100
*/
