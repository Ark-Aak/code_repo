#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,l,r,mx,a1[500005],a2[500005],a[500005],b[5005][5005],c[5005][5005],d[5005][5005],e[5005][5005];
long long dfs1(long long i,long long z);
long long dfs(long long i,long long z)
{
	long long ans1=0;
	if(b[i][z]) return c[i][z];
	for(long long j=1;j<=m;j++)
		if(a2[j]>z)
			if(a[j]==i)
				ans1=max(ans1,dfs1(a1[j],a2[j])+1);
			else if(a1[j]==i)
				ans1=max(ans1,dfs1(a[j],a2[j])+1);
	b[i][z]=1,c[i][z]=ans1;
	return ans1;
}
long long dfs1(long long i,long long z)
{
	long long ans1=INT_MAX;
	if(d[i][z]) return e[i][z];
	for(long long j=1;j<=m;j++)
		if(a2[j]>z)
			if(a[j]==i)
				ans1=min(ans1,dfs(a1[j],a2[j])+1);
			else if(a1[j]==i)
				ans1=min(ans1,dfs(a[j],a2[j])+1);
	if(ans1>=INT_MAX) return d[i][z]=1,e[i][z]=0,0;
	d[i][z]=1,e[i][z]=ans1;
	return ans1;
}
int main()
{
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(long long i=1;i<=m;i++)
		cin>>a[i]>>a1[i]>>a2[i],mx=max(mx,a2[i]);
	for(long long i=1;i<=n;i++)
	{
		cout<<dfs(i,0)<<" ";
		for(long long j=1;j<=n;j++)
			for(long long z=1;z<=mx;z++)
				b[i][z]=c[i][z]=d[i][z]=e[i][z]=0;
	}
}
/*
4 6
3 1 2
2 3 1
4 1 5
1 4 3
2 1 6
1 3 4
*/
