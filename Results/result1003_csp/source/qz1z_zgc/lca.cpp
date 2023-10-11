#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long LL;
int n,d[N],fa[N][25];
int h[N],e[N<<1],ne[N<<1],idx;
void add(int a,int b){e[idx]=b,ne[idx]=h[a],h[a]=idx++;}
void init(int u,int father)
{
	fa[u][0]=father;
	d[u]=d[father]+1;
	for(int i=1;i<=20;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
	for(int i=h[u];~i;i=ne[i])
	{
		int j=e[i];
		if(j==father)continue;
		init(j,u);
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
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	memset(h,-1,sizeof h); 
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(int root=1;root<=n;root++)
	{
		memset(d,0,sizeof d);
		memset(fa,0,sizeof fa);
		init(root,0);
		LL res=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)res+=(LL)LCA(i,j);
		}
		res*=2LL;
		res+=1LL*n*(n+1)/2LL;
		printf("%lld ",res);
	}
	return 0;
}
