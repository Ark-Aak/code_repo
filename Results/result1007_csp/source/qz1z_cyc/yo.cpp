#include<bits/stdc++.h>
using namespace std;
int n,dp[100005][12],p=11,s[100005];
string t,ss;
int main()
{
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	cin>>n>>ss;
	for(int i=1;i<=n;i++)
	{
		s[i]=ss[i-1]-'0';
	}
	cin>>t;
	t=" "+t;
	if(t[n]=='y')
	{
		dp[n][0]=1;
		if(n%2==1) dp[n][11-s[n]]=1;
		else dp[n][s[n]]=1;
	}
	else
	{
		if(s[n]==0) dp[n][0]=0;
		else dp[n][0]=1;
		for(int i=1;i<=10;i++)
		{
			dp[n][i]=1;
		}
	}
	for(int i=n-1;i>=1;i--)
	{
		for(int j=0;j<=10;j++)
		{
			if(t[i]==t[i+1])
			{
				if(i%2==1)
				{
					if(dp[i+1][(j+s[i])%p]==1||dp[i+1][j]==1) dp[i][j]=1;
				}
				else
				{
					if(dp[i+1][(j-s[i]+p)%p]==1||dp[i+1][j]==1) dp[i][j]=1;
				}
			}
			else
			{
				if(i%2==1)
				{
					if(dp[i+1][(j+s[i])%p]==1&&dp[i+1][j]==1) dp[i][j]=0;
					else dp[i][j]=1;
				}
				else
				{
					if(dp[i+1][(j-s[i]+p)%p]==1||dp[i+1][j]==1) dp[i][j]=0;
					else dp[i][j]=1;
				}
			}
		}
	}
	if(t[1]=='y')
	{
		if(dp[1][0]==1) cout<<"yoimiya";
		else cout<<"oimiya";
	}
	if(t[1]=='o')
	{
		if(dp[1][0]==1) cout<<"omiya";
		else cout<<"yomiya";
	}
}
