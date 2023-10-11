#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,q,w[N],d[N],fa[N][25];
int h[N],e[N<<1],ne[N<<1],idx; 
void add(int a,int b){e[idx]=b,ne[idx]=h[a],h[a]=idx++;}
void dfs(int u,int father)
{
	d[u]=d[father]+1;
	fa[u][0]=father;
	for(int i=1;i<=20;i++)fa[u][i]=fa[fa[u][i-1]][i-1];
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
	freopen("loser.in","r",stdin);
	freopen("loser.out","w",stdout);
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
	for(int i=1;i<=n;i++)scanf("%d",&w[i]);
	while(q--)
	{
		int op,a,b;
		scanf("%d%d%d",&op,&a,&b);
		int lca=LCA(a,b);
		if(op==1)
		{
			for(;a!=lca;a=fa[a][0])w[a]=!w[a];
			for(;b!=lca;b=fa[b][0])w[b]=!w[b];
			w[lca]=!w[lca];
		}
		else
		{
			string ans1="",ans2="",res;
			for(;a!=lca;a=fa[a][0])ans1=ans1+(char)(w[a]+'0');
			ans1+=(char)(w[lca]+'0');
			for(;b!=lca;b=fa[b][0])ans2=(char)(w[b]+'0')+ans2;
			res=ans1+ans2;
			stack<int>S;
			int t=0;
			for(int i=0;i<res.size();i++)
			{
				if(res[i]=='0')S.push(i);
				else
				{
					if(S.size())
					{
						S.pop();
						t++; 
					}
				}
			}
			printf("%d\n",(t<<1));
		}
	}	
	return 0;
} 
