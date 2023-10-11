#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[100005],sm,bi,sa,f1,f2,sum;
int main()
{
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(k==1)
	{
		sort(a+1,a+1+n);
		cout<<sum-a[n/2+1];
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		sm=bi=sa=f1=f2=0;
		for(int j=1;j<i;j++)
		{
			if(a[j]>a[i]) bi++;
			if(a[j]<a[i]) sm++;
			if(a[j]==a[i]) sa++;
		}
		if(((bi+sa)%k==0&&sm%k==0)||((sm+sa)%k==0&&bi%k==0)) f1=1;
		sm=bi=sa=0;
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]>a[i]) bi++;
			if(a[j]<a[i]) sm++;
			if(a[j]==a[i]) sa++;
		}
		if(((bi+sa)%k==0&&sm%k==0)||((sm+sa)%k==0&&bi%k==0)) f2=1;
		if(f1==1&&f2==1) ans=max(ans,a[i]);
	}
	cout<<sum-ans;
	return 0;
}
