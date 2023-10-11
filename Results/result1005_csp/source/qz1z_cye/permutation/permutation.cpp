#include<bits/stdc++.h>
using namespace std;
long long n,k,p[100005],q[100005],a[100005];
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&q[i]);
	for(int i=1;i<=k-1;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[p[j]]=q[j];
		}
		for(int j=1;j<=n;j++)
		{
			p[j]=q[j];
			q[j]=a[j];
		}
//		cout<<i<<":  "<<endl;
//		for(int i=1;i<=n;i++)
//		{	
//			cout<<a[i]<<" ";
//		}
//		cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
} 
