#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=6e5+5;
int n,m,q,S,T,st[N],vis[N];
int h[N],e[M],ne[M],idx;
vector<int>path;
void add(int a,int b){e[idx]=b,ne[idx]=h[a],h[a]=idx++;}
void dfs1(int u)
{
	if(u==T)
	{
		for(int i=0;i<path.size();i++)st[path[i]]=1;
		return;
	}
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		if(vis[j])continue;
		path.push_back(j);
		vis[j]=1;
		dfs1(j);
		vis[j]=0;
		path.pop_back();
	}
}
int dfs2(int u)
{
	st[u]=1;
	int res=1;
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		if(!st[j])res+=dfs2(j);
	}
	return res;
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	memset(h,-1,sizeof h);
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	scanf("%d",&q);
	while(q--)
	{
		memset(st,0,sizeof st);
		scanf("%d%d",&S,&T);
		path.push_back(S);
		vis[S]=1;
		dfs1(S);
		vis[S]=0;
		path.pop_back();
		int res=0;
		for(int i=1;i<=n;i++)
		{
			if(!st[i])res^=dfs2(i);
		}
		printf("%d\n",res);
	}
	return 0;
}
