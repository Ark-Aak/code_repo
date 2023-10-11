#include<bits/stdc++.h>
using namespace std;
int t,p,n,s[30000005];
short a[40000005];
int main()
{
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	cin>>t>>p;
	for(int i=1;i<=t;i++)
	{
		cin>>s[i];
		n=max(n,s[i]);
	}
	for(int i=2;i<=n+1000000;i++)
	{
		if(a[i]==0)
		{
			for(int j=2;j*i<=n+1000000;j++)
			{
//				if(i>p&&j>p)
//				{
//					a[i*j]=2;
//				}
//				else
				{
					a[i*j]=1;
				}				
			}
		}
	}
	for(int i=p+1;i<=n+1000000;i++)
	{
		if(a[i]==0)
		{
			for(int j=p+1;j*i<=n+1000000&&j*i>0;j++)
			{
				if(a[j]==0)
				{
					a[i*j]=2;
				}							
			}
		}
	}
//	for(int i=p+1;i<=n+1000000;i++)
//	{
//		if(a[i]==0)
//		{
//			for(int j=p+1;j*i<=n+1000000;j++)
//			{
//				
//			}
//		}
//	}
	for(int ii=1;ii<=t;ii++)
	{
		for(int i=s[ii];i<=n+1000000;i++)
		{
			if(a[i]!=1)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
}
