#include<bits/stdc++.h>
using namespace std;
unsigned long long n,k,a[500005],tim,kk,ans;
int main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]--;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		tim+=a[i]-a[i-1];
		kk++;
		if(kk>=k||i==n)
		{
			ans+=(tim+a[i])*kk;
			tim+=2*a[i];
			kk=0;
			if(i==n) break;
		}
		else
		{
			if(1ll*((a[i+1]-a[i]))*kk>=1ll*a[i]*(n-i))
			{
				ans+=(tim+a[i])*kk;
				tim+=2*a[i];
				kk=0;
			}
		}
	}
	cout<<ans;
	return 0;
}

