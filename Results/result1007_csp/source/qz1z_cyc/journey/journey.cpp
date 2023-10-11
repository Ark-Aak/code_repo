#include<bits/stdc++.h>
using namespace std;
long long n,m,q,u[200005],v[200005],vis[2005][2005],kl[1000005];
struct sb
{
	long long l,r,s,t,id;
}ans[1000005];
bool cmp(sb x,sb y)
{
	return x.l<y.l;
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
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld%lld%lld",&ans[i].l,&ans[i].r,&ans[i].s,&ans[i].t);
		ans[i].id=i;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j) vis[i][j]=9999999999;
		}
	}
	sort(ans+1,ans+1+q,cmp);
	int top=q;
	for(int i=m;i>=1;i--)
	{
		vis[u[i]][v[i]]=min(vis[u[i]][v[i]],(long long)i);
		vis[v[i]][u[i]]=min(vis[v[i]][u[i]],(long long)i);
		for(int j=1;j<=n;j++)
		{
			if(v[i]!=j&&u[i]!=j) vis[u[i]][j]=min(vis[u[i]][j],vis[v[i]][j]);
		}
		for(int j=1;j<=n;j++)
		{
			if(v[i]!=j&&u[i]!=j) vis[v[i]][j]=min(vis[u[i]][j],vis[v[i]][j]);
		}
		while(ans[top].l==i&&top>=1)
		{
			if(vis[ans[top].s][ans[top].t]<=ans[top].r||ans[top].s==ans[top].t)
			{
				kl[ans[top].id]=1;
				top--;
			}
			else top--;
		}
	}
	for(int i=1;i<=q;i++)
	{
		if(kl[i]==1) printf("Yes\n");
		else printf("No\n");
	}
}
