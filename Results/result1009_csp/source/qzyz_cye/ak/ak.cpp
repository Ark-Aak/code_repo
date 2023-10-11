#include<bits/stdc++.h>
using namespace std;
long long n,k,a[1000005],sm,bi,sa,res1,res2,flag,ans=0,sum;
int main()
{
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	cin>>n>>k;
	if(k!=1)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		for(int i=1;i<=n;i++)
		{
			sm=bi=sa=0;
			flag=0;
			for(int j=1;j<=i-1;j++)
			{
				if(a[j]<a[i]) sm++;
				if(a[j]>a[i]) bi++;
				if(a[j]==a[i]) sa++;
			}
			res1=(k-(sm%k))%k;
			res2=(k-(bi%k))%k;
			if(!(res1+res2<=sa&&(sa-res1-res2)%k==0))
			{
				flag=1;
				continue;
			}
			sm=bi=sa=0;
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]<a[i]) sm++;
				if(a[j]>a[i]) bi++;
				if(a[j]==a[i]) sa++;
			}
			res1=(k-(sm%k))%k;
			res2=(k-(bi%k))%k;
			if(!(res1+res2<=sa&&(sa-res1-res2)%k==0))
			{
				flag=1;
				continue;
			}
			if(flag==0) ans=max(ans,a[i]);
		}
		cout<<sum-ans;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		sort(a+1,a+n+1);
		cout<<sum-a[n/2+1];
	}
	
 } 
 
// f(i,j)=lcm(i,j)/i+lcm(i,j)/j-2
 
 
 
 
