#include<bits/stdc++.h>
using namespace std;
int n,m,s,ans,ansn;
string aa;
bool a[25][200005];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>aa;
		for(int j=1;j<=m;j++)
		{
			if(aa[j-1]=='0')
			{
				a[i][j]=0;
			}
			else
			{
				a[i][j]=1;
			}
		}
	}
	ansn=2147483647;
	for(int ii=1;ii<=50;ii++)
	{
//		s=0;
		
		for(int i=1;i<=m;i++)
		{
			s=0;
			for(int j=1;j<=n;j++)
			{
				if(a[j][i]==1)
				{
					s++;
				}
			}
			if(s>n/2)
			{
				for(int j=1;j<=n;j++)
				{
					a[j][i]=!a[j][i];
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			s=0;
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==1)
				{
					s++;
				}
			}
			if(s>=m/2)
			{
				for(int j=1;j<=n;j++)
				{
					a[i][j]=!a[i][j];
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==1)
				{
					ans++;
				}
			}
		}
		ansn=min(ans,ansn);
	}
	
	cout<<ansn<<endl;
}
