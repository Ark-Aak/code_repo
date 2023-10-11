#include<bits/stdc++.h>
using namespace std;
int t,n,v,p,ans,a[2005][2005];
string s;
int main()
{
	freopen("excellent.in","r",stdin);
	freopen("excellent.out","w",stdout);
	cin>>t;
	for(int ii=1;ii<=t;ii++)
	{
		cin>>s;
		ans=0;
		n=s.size();
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				a[i][j]=0;
			}
		}
		v=1;
		for(int i=0;i<n;i++)
		{
			if(s[i]!='?')
			{
				v=0;
			}
		}
		if(v==0)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=i;j+j-i+1<n;j++)
				{
					p=1;
					for(int k=0;k<=j-i;k++)
					{
						if(s[i+k]!=s[j+1+k]&&s[i+k]!='?'&&s[j+1+k]!='?')
						{
							p=0;
							break;
						}
					}
					if(p==1)
					{
						a[i][j]=1;
//						cout<<i<<"  -  "<<j<<endl;
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				for(int j=i;j<n;j++)
				{
					if(a[i][j]==1)
					{
						for(int k=j+j-i+2;k<n;k++)
						{
							if(a[j+j-i+2][k]==1)
							{
//								cout<<j+j-i+2<<" |   "<<i<<" - "<<j<<"  -  "<<k<<endl;
								ans++;
							}
						}
					}
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			for(int i=0;i<n;i++)
			{
				for(int j=i;j+j-i+1<n;j++)
				{
					p=1;					
					if(p==1)
					{
						a[i][j]=1;
//						cout<<i<<"  -  "<<j<<endl;
					}
				}
			}
			for(int i=0;i<n;i++)
			{
				for(int j=i;j<n;j++)
				{
					if(a[i][j]==1)
					{
						for(int k=j+j-i+2;k<n;k++)
						{
							if(a[j+j-i+2][k]==1)
							{
//								cout<<j+j-i+2<<" |   "<<i<<" - "<<j<<"  -  "<<k<<endl;
								ans++;
							}
						}
					}
				}
			}
			cout<<ans<<endl;
		}		
		
	}
}
