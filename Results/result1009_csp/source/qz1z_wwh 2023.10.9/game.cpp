#include<bits/stdc++.h>
using namespace std;
int t,n,m,dp[1005][1005],s;
int gcd(int aa,int bb)
{
	for(int id=40;id>=1;id--)
	{
//		cout<<aa<<" "<<bb<<"  "<<aa%id<<"  "<<bb%id<<"  "<<id<<endl;
		if(aa%id==0&&bb%id==0)
		{
//			cout<<"_________________________"<<endl;
			return id;
		}
	}
	return 0;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>t;
	for(int i=1;i<=1000;i++)
	{
		dp[i][i]=0;
		for(int j=i+1;j<=1000;j++)
		{
			s=gcd(i,j);
//			cout<<"+++++++++++++++++++++"<<" "<<i<<" "<<j<<" "<<s<<"    "<<__gcd(i,j)<<endl;
//			if(s!=__gcd(i,j))
//			{
//				cout<<"BOOM"<<endl;
//			}
			if(s==1)
			{
				dp[i][j]=i+j-2;
			}
			else
			{
				dp[i][j]=dp[i/s][j/s];
			}
		}
	}
//	dp[0][0]=1;
	for(int i=1;i<=1000;i++)
	{
		for(int j=i;j<=1000;j++)
		{
			dp[i][j]+=dp[i-1][j];
//			dp[i][j]%=1000000007;
			dp[i][j]+=dp[i][j-1];
			if(j!=i)
			dp[i][j]-=dp[i-1][j-1];
			dp[i][j]%=1000000007;
		}
	}
//	for(int i=1;i<=10;i++)
//	{
//		for(int j=1;j<=10;j++)
//		{
//			cout<<dp[i][j]<<"  ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m;
		cout<<(dp[min(n,m)][max(n,m)]*2)%1000000007<<endl;
	}
}
