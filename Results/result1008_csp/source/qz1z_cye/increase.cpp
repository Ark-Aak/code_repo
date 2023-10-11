#include<bits/stdc++.h>
using namespace std;
long long n,m,f[200005],g[200005],ls1,ls2;
struct sd
{
	long long u,v,w;
}b[500005];
int cmp(sd A,sd B)
{
	return A.w<B.w;
}
int main()
{
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&b[i].u,&b[i].v,&b[i].w);
	}
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=n;i++)
	{
		f[i]=1;
		g[i]=1145141919;
	 } 
	for(int i=m;i>=1;i--)
	{
		
		ls1=f[b[i].u];
		ls2=f[b[i].v];
		///////////////////
		if(g[b[i].v]!=1145141919) f[b[i].u]=max(f[b[i].u],g[b[i].v]+1);
		else f[b[i].u]=max(f[b[i].u],(long long)2);
		if(g[b[i].u]!=1145141919) f[b[i].v]=max(f[b[i].v],g[b[i].u]+1);
		else f[b[i].v]=max(f[b[i].v],(long long)2);
		/////////////////
		
		g[b[i].u]=min(g[b[i].u],ls2+1);
		g[b[i].v]=min(g[b[i].v],ls1+1);
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=n) printf("%lld ",f[i]-1);
		else printf("%lld",f[i]-1);
	}
	return 0;
}
