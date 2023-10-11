#include<bits/stdc++.h>
using namespace std;
const int N=5005,mod=1e9+7;
typedef long long LL;
int n,m,res,b[N],st[N];
void dfs(int u)
{
	if(u==-1)
	{
		LL ans=1;
		for(int i=1;i<=n;i++)
		{
			if(!st[i])
			{
				if(b[i]<=m-1)ans=1LL*ans*(b[i]+1)%mod;
				else ans=1LL*ans*(b[i])%mod;
			}
		}
		res=(res+ans)%mod;
		return;
	}
	for(int i=n;i;i--)
	{
		if(u>b[i])break;
		if(!st[i])
		{
			st[i]=1;
			dfs(u-1);
			st[i]=0;
		}
	}
}
int main()
{
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	sort(b+1,b+n+1); 
	for(m=1;m<=n;m++)dfs(m-1);
	printf("%lld",res);
	return 0;
}
