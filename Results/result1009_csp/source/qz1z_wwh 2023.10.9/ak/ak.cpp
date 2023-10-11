//0|100
#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005],c[1000005],n,k,p,z,s,minn,pans,st;
long long int ans;
int main()
{
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
//		b[i]=a[i];
		ans+=b[i];
	}
//	cout<<"1"<<endl;
	p=n/k;
	s=p;
	p/=2;
	p*=k;
//	if(p!=n/2+n%2)
//	{
//		cout<<"BOOM !!!!"<<endl;
//		return 0;
//	}
//	cout<<"1"<<endl;
//	sort(a+1,a+n+1);
	if(k==1)
	{
		sort(b+1,b+n+1);
		cout<<ans-b[n/2+1]<<endl;
	}
	else
	{
		minn=2147483647;
//		st=
		for(int i=0;i<=s;i++)
		{
			c[i]=b[i*k+1];
		}
//		cout<<ans-b[pans]<<endl;
		sort(c,c+s+1);
		if(s%2==0)
		{
			cout<<ans-c[s/2]<<endl;
//			cout<<"DWda"<<endl;
		}
		else
		{
			cout<<ans-c[s/2+1]<<endl;
		}
//		for(int i=0;i<=s;i++)
//		{
//			cout<<ans-c[i]<<endl;
//		}
	}	
}
