#include<bits/stdc++.h>
using namespace std;
int n,x[1000005];
double ans;
int main()
{
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	sort(x+1,x+1+n);
	ans=x[1]*1.0;
	for(int i=2;i<=n;i++)
	{
		ans=(ans+x[i]*1.0)/2.0;
	}
	printf("%.6lf",ans);
	return 0;
}
