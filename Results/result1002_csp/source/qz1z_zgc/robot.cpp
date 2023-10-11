#include<bits/stdc++.h>
using namespace std;
const int N=120005,M=250005;
int n,m,d[N],fa[N][30];
int h[N],e[M],ne[M],idx;
void add(int a,int b)
{
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
void dfs(int u,int father)
{
	fa[u][0]=father;
	d[u]=d[father]+1;
	for(int j=1;j<=25;j++)fa[u][j]=fa[fa[u][j-1]][j-1];
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		if(j==father)continue;
		dfs(j,u);
	}
}
int LCA(int a,int b)
{
	if(d[a]<d[b])swap(a,b);
	for(int i=25;~i;i--)
	{
		if(d[fa[a][i]]>=d[b])a=fa[a][i];
	}
	if(a==b)return a;
	for(int i=25;~i;i--)
	{
		if(fa[a][i]!=fa[b][i])
		{
			a=fa[a][i];
			b=fa[b][i];
		}
	}
	return fa[a][0];
}
void work()
{
	map<pair<int,int>,int>cnt,st;
	vector<pair<int,int> >edge;
	memset(h,-1,sizeof h);
	idx=0;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
		edge.push_back({a,b});
	}
	dfs(1,0);
	scanf("%d",&m);
	while(m--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int lca=LCA(a,b);
		while(a!=lca)
		{
			cnt[{a,fa[a][0]}]++;
			st[{a,fa[a][0]}]++;
			a=fa[a][0];
		}
		while(b!=lca)
		{
			cnt[{b,fa[b][0]}]--;
			st[{b,fa[b][0]}]++;
			b=fa[b][0];
		}
	}
	for(int i=0;i<edge.size();i++)
	{
		int a=edge[i].first,b=edge[i].second;
		if(st[{a,b}]||st[{b,a}])
		{
			if(!(cnt[{a,b}]+cnt[{b,a}])&&(st[{a,b}]>1||st[{b,a}]>1))
			{
				puts("No");
				return;
			}
		}
	}
	puts("Yes");
}
int main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
} 
