#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,mod=998244353; 
int n,m,a[N],res=0;
void dfs(int u)
{
	if(u==n+1)
	{
		res++;
		if(res>=mod)res-=mod;
		return;
	}
 	for(int i=1;i<=m;i++)
 	{
 		if(a[u-1]<=i||a[u-1]%i)
 		{
 			a[u]=i;
 			dfs(u+1);
		}
	}
}
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	scanf("%d%d",&n,&m);
	dfs(1);
	printf("%d",res);
	return 0;
}
