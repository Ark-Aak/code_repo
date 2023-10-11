#include<bits/stdc++.h>
using namespace std;
int n,a[500005],p,b[500005],ans[500005];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		b[i]=i;
	}
	a[0]=2147483647;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			b[i]=i-1;
		}
		else
		{
			p=b[i-1];
			while(a[p]<=a[i])
			{
				p=b[p];
			}
			b[i]=p;
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]=ans[b[i]]+1;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
}
