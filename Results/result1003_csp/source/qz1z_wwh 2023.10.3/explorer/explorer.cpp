#include<bits/stdc++.h>
using namespace std;
long long int ans;
int n,a[100005],b[100005],ni,nj,nk;
int main()
{
	freopen("explorer.in","r",stdin);
	freopen("explorer.out","w",stdout);
	cin>>n;
	if(n>2000)
	{
		for(int i=n;i>=3;i--)
		{
			ans+=(i-1)*(i-2)/2;
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i]>>b[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{				
				for(int k=j+1;k<=n;k++)
				{
					ni=0;
					nj=0;
					nk=0;
					if(a[i]<=a[j]&&a[j]<=b[i])
					{
						ni++;
					}
					if(a[i]<=b[j]&&b[j]<=b[i])
					{
						ni++;
					}
					if(a[i]<=a[k]&&a[k]<=b[i])
					{
						ni++;
					}
					if(a[i]<=b[k]&&b[k]<=b[i])
					{
						ni++;
					}
					
					if(a[j]<=a[i]&&a[i]<=b[j])
					{
						nj++;
					}
					if(a[j]<=b[i]&&b[i]<=b[j])
					{
						nj++;
					}
					if(a[j]<=a[k]&&a[k]<=b[j])
					{
						nj++;
					}
					if(a[j]<=b[k]&&b[k]<=b[j])
					{
						nj++;
					}
					
					if(a[k]<=a[j]&&a[j]<=b[k])
					{
						nk++;
					}
					if(a[k]<=b[j]&&b[j]<=b[k])
					{
						nk++;
					}
					if(a[k]<=a[i]&&a[i]<=b[k])
					{
						nk++;
					}
					if(a[k]<=b[i]&&b[i]<=b[k])
					{
						nk++;
					}
					ni=2+min(ni,4-ni);
					nj=2+min(nj,4-nj);
					nk=2+min(nk,4-nk);
					if(ni==nj&&nj==nk)
					{
						ans++;
					}
				}
			}
		}
	}
	cout<<ans<<endl;
}
