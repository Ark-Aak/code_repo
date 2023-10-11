#include<bits/stdc++.h>
using namespace std;
int dp[510][510][510];
int a[5010];
const int mod=998244353;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for ( int i = 1 ; i <= m ; i++ )
	{
		cin >> a[i];
		dp[1][i][1]=1;
	}
	for ( int i = 2 ; i <= n ; i++ )
	{
		for ( int j = 1 ; j <= m ; j++ )
		{
			for ( int k = 1 ; k <= a[i] ; k++ )
			{
				if(k!=1)
				{
					dp[i][j][k]=dp[i-1][j][k-1];
				}
				for ( int i1 = 1 ; i1 <= m ; i1++ )
				{
					if(i1==j)
					{
						continue;
					}
					for ( int j1 = 1 ; j1 <= a[i1] ; j1++ )
					{
						if(i-k-j1+1<1)
						{
							break;
						}
						dp[i][j][k]+=dp[i-k-j1+1][i1][j1];
						dp[i][j][k]%=mod;
					}
				}
			}
		}
	}
	int ans=0;
	for ( int i = 1 ; i <= m ; i++ )
	{
		for ( int j = 1 ; j <= a[i] ; j++ )
		{
			ans+=dp[n][i][j];
			ans%=mod;
		}
	}
	cout << ans;
	return 0;
}
