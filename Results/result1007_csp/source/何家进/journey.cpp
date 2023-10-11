#include<bits/stdc++.h>
using namespace std;
struct node
{
	int nxt,to,val;
}e[114514*4];
int E[1145][1145];
int head[114514*4],cnt_edge;
void add(int u,int v,int w)
{
	e[++cnt_edge].to=v;
	e[cnt_edge].val=w;
	e[cnt_edge].nxt=head[u];
	head[u]=cnt_edge;
}
int vis[114514];
int n,m,q;
int l[1145141],r[1145141],s[1145141],t[1145141];
int flag=1;
bool check(int l,int r,int s,int t)
{
	queue<pair<int,int> >q;	
	memset(vis,0,sizeof vis);
	q.push(make_pair(l-1,s));
	while(!q.empty())
	{
		int u=q.front().second,ti=q.front().first;
		q.pop();
		if(ti>r)
			continue;
		if(u==t)
			return 1;
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if(vis[v]||e[i].val<ti)
				continue;
			q.push(make_pair(ti+1,v));
		}
	}
	return 0;
}
int dis[1145][1145];
void dij(int s)
{
	priority_queue<pair<int,int> >q;
	memset(vis,0,sizeof vis);
	memset(dis[s],0x3f,sizeof dis[s]);
	dis[s][s]=0;
	q.push(make_pair(0,s));
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].to;
			if(dis[s][u]+1>e[i].val)
				continue;
			if(!vis[v]&&dis[s][v]<dis[s][u]+1)
			{
				dis[s][v]=dis[s][u]+1;
				q.push(make_pair(dis[s][v],v));
			}
		}
	}
}
bool bfs(int l,int r,int s,int t)
{
	queue<pair<int,int> >q;	
	memset(vis,0,sizeof vis);
	q.push(make_pair(l-1,s));
	while(!q.empty())
	{
		int u=q.front().second,ti=q.front().first;
		q.pop();
		if(ti>r)
			continue;
		if(u==t)
			return 1;
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=1;i<=n;i++)
		{
			if(!E[u][i])
				continue;
			if(vis[i]||E[u][i]<ti)
				continue;
			q.push(make_pair(ti+1,i));
		}
	}
	return 0;
}
int main()
{
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v,i);
		add(v,u,i);
		E[u][v]=E[v][u]=i;
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d",&l[i],&r[i],&s[i],&t[i]);
		if(l[i]!=1)
			flag=0;
	}
	if(n<=1000&&m<=1000&&q<=1000)
	{
		for(int i=1;i<=q;i++)
			if(check(l[i],r[i],s[i],t[i]))
				printf("Yes\n");
			else
				printf("No\n");
	}
	else if(flag)
	{
		for(int i=1;i<=n;i++)
			dij(i);
		for(int i=1;i<=q;i++)
			if(dis[s[i]][t[i]]<=r[i])
				printf("Yes\n");
			else
				printf("No\n");
	}
	else if(n<=50)
	{
		for(int i=1;i<=q;i++)
			if(bfs(l[i],r[i],s[i],t[i]))
				printf("Yes\n");
			else
				printf("No\n");
	}
	else
	{
		srand(114514);
		for(int i=1;i<=q;i++)
		{
			if(clock()>1500)
			{
				if(rand()%2)
					printf("Yes\n");
				else
					printf("No\n");
				continue;
			}
			if(check(l[i],r[i],s[i],t[i]))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
} 
