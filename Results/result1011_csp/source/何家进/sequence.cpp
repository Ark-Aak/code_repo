#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
int n,m;
ll dp[2][100005];//前i个数，第i个数为j时的方案数
ll sum[100005];
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m;
	sum[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			dp[i&1][j]=sum[i-1];
		for(int j=1;j<=m;j++)
			for(int k=j*2;k<=m;k+=j)
				dp[i&1][j]=(dp[i&1][j]-dp[(i-1)&1][k])%mod;
		for(int j=1;j<=m;j++)
			sum[i]=(sum[i]+dp[i&1][j])%mod;
	}
	cout<<sum[n];
	return 0;
}
