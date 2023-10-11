#include<bits/stdc++.h>
using namespace std;
long long int ans,dp[2005][2005],sum[2005][2005];
int n,m,o;
vector<int>md[2005];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m;
	o=998244353;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(i%j==0)
			{
				md[i].push_back(j);
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		dp[n][i]=1;
//		sum[n][i]=sum[n][i+1]+1;
	}
	for(int i=m;i>=1;i--)
	{
		sum[n][i]=sum[n][i+1]+1;
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]+=sum[i+1][1];
			dp[i][j]%=o;
			for(int k:md[j])
			{
				if(k<j)
				{
					dp[i][j]-=(dp[i+1][k])%o;
					if(dp[i][j]<0)
					{
						dp[i][j]+=o;
					}
					dp[i][j]%=o;
				}
				else
				{
					break;
				}
			}
		}
		for(int j=m;j>=1;j--)
		{
			sum[i][j]=sum[i][j+1]+dp[i][j];
			sum[i][j]%=o;
		}
	}
	cout<<sum[1][1]<<endl;
}
