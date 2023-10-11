#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005];
double ans;
int main()
{
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	ans=a[1]*1.00000;
	for(int i=2;i<=n;i++)
	{
		ans=(ans+a[i]*1.0000)/2.00;
	}
	printf("%.6lf",ans);
	return 0;
 } 
