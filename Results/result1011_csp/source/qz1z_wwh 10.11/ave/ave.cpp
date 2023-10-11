#include<bits/stdc++.h>
using namespace std;
double a[1000005],ans;
int n;
int main()
{
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
	}
	sort(a+1,a+n+1);
	ans=(a[1]+a[2])/2;
	for(int i=3;i<=n;i++)
	{
		ans=(ans+a[i])/2;
	}
	printf("%.6lf",ans);
}
