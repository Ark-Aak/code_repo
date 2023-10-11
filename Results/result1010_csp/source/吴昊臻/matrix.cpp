#include<bits/stdc++.h>
using namespace std;
int n,m,k,mx,tem,lst=1;
long long dp[(1<<12)+1000][5005],ans=1e10,h[1005],l[1005],mod=1e9+7;
string y[13][2];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.in","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>y[i][0];
		for(int j=0;j<m;j++)
		{
			if(y[i][0][j]=='1')
			y[i][1][j]='0';
			else
			y[i][1][j]='1';
		}
	}
	for(int i=0;i<=(1<<n)-1;i++)
	{
		for(int j=0;j<m;j++)
		{
			long long ans1=0;
			for(int z=1;z<=n;z++)
			{
				if(i&(1<<(z-1))==1)
				{
					if(y[z][1][j]=='1')
						ans1++;
				}
				else if(y[z][0][j-1]=='1')
					ans1++;
			}
			dp[i][j]=dp[i][j-1]+min(n-ans1,ans1);
		}
		ans=min(ans,dp[i][m-1]);
	}
	cout<<ans;
}	
/*
3 4
0110
1010
0111
*/
