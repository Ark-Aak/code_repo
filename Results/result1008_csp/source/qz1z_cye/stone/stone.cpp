#include<bits/stdc++.h>
using namespace std;
long long n,k,f[105],mod=1000000007,dp[105][105],g[105],ans,ww,qwq;
int main()
{
//	freopen("stone.in","r",stdin);
//	freopen("stone.out","w",stdout);
	cin>>n>>k;
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i]=(f[i-1]*(k+1))%mod;
	}
	g[0]=1;
	for(int i=1;i<=n;i++)
	{
		g[i]=(g[i-1]*i)%mod;
	}
//	if(n<=k) 
//	{
//		dp[n][1]=1;
//		dp[n][0]=k;
//	}
//	else
//	{
//		dp[n][1]=0;
//		dp[n][0]=k+1;
//	}
	dp[n+1][0]=1;
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<=n;j++)
		{
			for(int h=0;h<=k;h++)
			{
				if(h+j>=i&&h<=i)
				{
					dp[i][j+1]=(dp[i][j+1]+dp[i+1][j])%mod;
				}
				if(!(h+j>=i&&h<=i))	dp[i][j]=(dp[i][j]+dp[i+1][j])%mod;
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=n;j++)
//		{
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	dp[n+1][0]=1;
	for(int i=1;i<=n;i++)
	{
		ww=f[i-1];
		for(int j=0;j<=k;j++)
		{
			for(int h=0;h<=n;h++)
			{
				if(!(j<=i&&j+h>=i))
				{
					qwq=(ww*dp[i+1][h])%mod;
					ans=(ans+qwq*(j+h))%mod;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
