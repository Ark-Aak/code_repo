#include<bits/stdc++.h>
#define BOOM cout<<"BOOM!!"<<endl;
using namespace std;
int n,k,a[2000005],ste,maxn,ap[2000005],apoi,sum[1000005],sumn;
int dp[2000005],f[2000005],aha;
int main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	cin>>n>>k;
	if(k==0)
	{
		BOOM;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>ste;
		a[ste]++;
		maxn=max(maxn,ste);
	}
	apoi++;
	ap[apoi]=0;
	for(int i=1;i<=maxn;i++)
	{
		if(a[i]!=0)
		{
			apoi++;
			ap[apoi]=i;
			sumn+=a[i];
			sum[i]=sumn;
		}
	}
	for(int i=1;i<=maxn;i++)
	{
		dp[i]=2147483647;
	}
	for(int ii=2;ii<=maxn;ii++)
	{
		int i=ap[ii];
		for(int jj=0;jj<ii;jj++)
		{
			int j=ap[jj];
			if(sum[i]-sum[j]<=k)
			{
//				cout<<i<<"  "<<j<<endl;
				dp[i]=min(dp[i],dp[j]+(n-sum[j])*(i-1)*2);
			}
			else
			{
				aha=(sum[i]-sum[j])/k;
				if((sum[i]-sum[j])%k!=0)
				{
					aha++;
				}
				
				dp[i]=min(dp[i],dp[j]+aha*(n-sum[j])*(i-1)*2);
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<dp[i]<<endl;
//	}
//	cout<<endl;
	cout<<dp[maxn]<<endl;
}
