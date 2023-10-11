#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=998244353;
int n,k,m,res,s[N];
struct node
{
	int l,r,s;
}q[N];
int cmp(node a,node b){return a.r<b.r;}
void dfs(int u,int v)
{
	if(u==n+1)
	{
		if(v==m+1)
		{
			res++;
			if(res>=mod)res-=mod;
		}
		return;
	}
	for(int x=0;x<(1<<k);x++)
	{
		s[u]=x;
		s[u]^=s[u-1];
		if(u==q[v].r)
		{
			if(s[q[v].r]^s[q[v].l-1]==q[v].s)dfs(u+1,v+1);
		}
		else dfs(u+1,v);
	}	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d%d",&n,&k,&m);
	if(!k)
	{
		int flag=1;
		for(int i=1;i<=m;i++)
		{
			int l,r,s;
			scanf("%d%d%d",&l,&r,&s);
			if(s)flag=0;
		}
		printf("%d",flag);
		return 0;
	}
	for(int i=1;i<=m;i++)scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].s);
	sort(q+1,q+m+1,cmp);
	dfs(1,1);
	printf("%d",res);
	return 0;
}
