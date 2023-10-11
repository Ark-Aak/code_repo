#include<bits/stdc++.h>
using namespace std;
long long top,n,m,q,head[2005],nex[400005],u[400005],v[400005],w[400005],fa[2005],vis[1005][1005],ans[1000005];
struct sd
{
	long long l,r,s,t,kk;
}qu[1000005];
int cmp(sd A,sd B)
{
	return A.l<B.l;
}
int main()
{
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&u[i],&v[i]);
		
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) if(i!=j) vis[i][j]=114514191;
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld%lld%lld",&qu[i].l,&qu[i].r,&qu[i].s,&qu[i].t);
		qu[i].kk=i;
	}
	sort(qu+1,qu+q+1,cmp);
	top=q;
	for(int i=m;i>=1;--i)
	{
		
		vis[u[i]][v[i]]=min(vis[u[i]][v[i]],(long long)i);
		vis[v[i]][u[i]]=min(vis[v[i]][u[i]],(long long)i);
		for(int j=1;j<=n;++j)
		{
			if(j!=u[i]&&j!=v[i]) vis[u[i]][j]=min(vis[u[i]][j],vis[v[i]][j]);
		}
		for(int j=1;j<=n;++j)
		{
			if(j!=u[i]&&j!=v[i]) vis[v[i]][j]=min(vis[v[i]][j],vis[u[i]][j]);
		}
		while(qu[top].l==i&&top>=1)
		{
			if(vis[qu[top].s][qu[top].t]<=qu[top].r||qu[top].s==qu[top].t) ans[qu[top].kk]=1;
			else ans[qu[top].kk]=0;
			top--;
		}
	}
	for(int i=1;i<=q;++i)
	{
		if(ans[i]==1) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
