#include<bits/stdc++.h>
using namespace std;
long long n,dp[1005][1005],mod=1000000007,aa,bb;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=1000;j++)
		{
			dp[i][j]=(i+j)/(__gcd(i,j))-2;
			dp[i][j]=dp[i][j]%mod;
		}
	}
	for(int i=1;i<=1000;i++)
	{
		for(int j=1;j<=1000;j++)
		{
			dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+dp[i][j])%mod;
		}
	}
	while(n--)
	{
		scanf("%lld%lld",&aa,&bb);
		printf("%lld\n",dp[aa][bb]);
	}
	return 0;
}
