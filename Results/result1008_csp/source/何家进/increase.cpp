#include<bits/stdc++.h>
using namespace std;
struct node
{
	int nxt,to,val;
}e[2000005];
int head[1000005],cnt_edge;
inline void add(int u,int v,int w)
{
	e[++cnt_edge].to=v;
	e[cnt_edge].val=w;
	e[cnt_edge].nxt=head[u];
	head[u]=cnt_edge;
}
struct node1
{
	int u,step,tag,last;
};
int bfs(int s)
{
	queue<node1>q;
	q.push(node1{s,0,0,0});
	int res=0;
	while(q.size())
	{
		int u=q.front().u;
		int step=q.front().step;
		int tag=q.front().tag;
		int v=q.front().last;
		q.pop();
		res=max(res,step);
		if(!tag)
		{
			int minn=1e9,p=0;
			for(int i=head[u];i;i=e[i].nxt)
				if(e[i].val<minn&&e[i].val>v)
					p=e[i].to,minn=e[i].val;
			if(p)
				q.push(node1{p,step+1,tag^1,minn});
		}
		else
		{
			int maxn=0,p=0;
			for(int i=head[u];i;i=e[i].nxt)
				if(e[i].val>maxn&&e[i].val>v)
					p=e[i].to,maxn=e[i].val;
			if(p)
				q.push(node1{p,step+1,tag^1,maxn});
		}
	}
	return res;
}
int vis[114514];
int n,m;
int main()
{
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",bfs(i));
	return 0;
}
