#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,q,st[N]; 
int h[N],e[N<<1],ne[N<<1],idx;
int d[N],fa[N][25];
void add(int a,int b){e[idx]=b,ne[idx]=h[a],h[a]=idx++;}
void dfs(int u,int father)
{
	d[u]=d[father]+1;
	fa[u][0]=father;
	for(int j=1;j<=20;j++)fa[u][j]=fa[fa[u][j-1]][j-1];
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
	for(int i=20;~i;i--)
	{
		if(d[fa[a][i]]>=d[b])a=fa[a][i];
	}
	if(a==b)return a;
	for(int i=20;~i;i--)
	{
		if(fa[a][i]!=fa[b][i])
		{
			a=fa[a][i];
			b=fa[b][i];
		}
	}
	return fa[a][0];
}
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	memset(h,-1,sizeof h);
	scanf("%d%d",&n,&q);
	for(int i=1;i<n;i++)
	{
	 	int a,b;
	 	scanf("%d%d",&a,&b);
	 	add(a,b);
	 	add(b,a);
	}
	dfs(1,0); 
	vector<int>JC;
	while(q--)
	{
		char op[10];
		int x;
		scanf("%s%d",op,&x);
		if(*op=='J')
		{
			st[x]=1;
			JC.push_back(x);
		}
		else if(*op=='Q')
		{
			int res=1e9;
			for(int i=0;i<JC.size();i++)
			{
				int lca=LCA(x,JC[i]);
				for(int j=x;j!=lca;j=fa[j][0])res=min(res,j);
				for(int j=JC[i];j!=lca;j=fa[j][0])res=min(res,j);
				res=min(res,lca);
			}
			printf("%d\n",res);
		}
	}
	return 0;
} 
