#include<bits/stdc++.h>
using namespace std;
int T,p,n,zhi[5000005],kl[5000005],cc[5000005],top,l,r,mid;
int main()
{
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	cin>>T>>p;
	for(int i=2;i<=5000000;i++)
	{
		if(zhi[i]==0)
		{
			for(int j=i+i;j<=5000000;j=j+i)
			{
				zhi[j]=1;
				if(i<=p) kl[j]=1;
			}
		} 
	}
	for(int i=2;i<=5000000;i++)
	{
		if(kl[i]==0||zhi[i]==0)
		{
			top++;
			cc[top]=i; 
		}
	}
	while(T--)
	{
		scanf("%lld",&n);
		l=1,r=top;
		while(l<r)
		{
			mid=(l+r)/2;
		//	cout<<cc[mid]<<endl;
			if(cc[mid]>=n) r=mid;
			else l=mid+1;
		}
		printf("%lld\n",cc[l]);
	}
	return 0;
}

