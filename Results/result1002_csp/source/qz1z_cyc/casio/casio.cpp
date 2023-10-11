#include<bits/stdc++.h>
using namespace std;
int T,P,n,zhi[2000005],cc[2000005],top,cen[2000005],tt;
int main()
{
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	cin>>T>>P;
	for(int i=2;i<=2000000;i++)
	{
		if(zhi[i]==0)
		{
			for(int j=i+i;j<=2000000;j=j+i)
			{
				if(cc[j]==0) cc[j]=i;
				zhi[j]=1;
				tt++;
			}
		}
	}
	for(int i=2;i<=2000000;i++)
	{
		if(zhi[i]==0||cc[i]>P)
		{
			top++;
			cen[top]=i;
		}
	}
	while(T--)
	{
		scanf("%d",&n);
		int l=1,r=top;
		while(l<r)
		{
			
			int mid=(l+r)/2;
			if(cen[mid]<n) l=mid+1;
			else r=mid;
		}
		cout<<cen[r]<<endl;
	}
//	cout<<"times:"<<tt*5;
	return 0;
}
