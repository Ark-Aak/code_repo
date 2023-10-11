#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
int a[1000010],s[1000010];
signed main()
{
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);//暴力。每次找到最小/最大的区间并去掉。O(n^2/k)
	int n,k;
	cin >> n >> k;
	int cnt=0;
	for ( int i = 1 ; i <= n ; i++ )
	{
		cin >> a[i];
		s[i]=s[i-1]+a[i];
		cnt+=a[i];
	}
	if(k==1)
	{
		sort(a+1,a+n+1);
		cout << cnt-a[n/2+1];
		return 0;
	}
	int op=1;
	while(n!=1)
	{
		if(op==1)
		{
			int mn=inf,ans=0;
			for ( int i = 1 ; i+k-1 <= n ; i++ )
			{
				if(s[i+k-1]-s[i-1]<mn)
				{
					mn=s[i+k-1]-s[i-1];
					ans=i;
				}
			}
			for ( int i = ans ; i+k-1 <= n ; i++ )
			{
				a[i]=a[i+k];
			}
			n-=k;
			for ( int i = 1 ; i <= n ; i++ )
			{
				s[i]=s[i-1]+a[i];
			}
			op=2;
		}else{
			int mx=0,ans=0;
			for ( int i = 1 ; i+k-1 <= n ; i++ )
			{
				if(s[i+k-1]-s[i-1]>mx)
				{
					mx=s[i+k-1]-s[i-1];
					ans=i;
				}
			}
			for ( int i = ans ; i+k-1 <= n ; i++ )
			{
				a[i]=a[i+k];
			}
			n-=k;
			for ( int i = 1 ; i <= n ; i++ )
			{
				s[i]=s[i-1]+a[i];
			}
			op=1;
		}
	}
	cout << cnt-a[1];
	return 0;
 } //期望30 
