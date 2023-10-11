#include<bits/stdc++.h>
using namespace std;
int n,k,p[100005],q[100005],a[100005];
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=n;i++) scanf("%d",&q[i]);
	for(int i=2;i<=k;i++)
	{
		for(int i=1;i<=n;i++)
		{
			a[p[i]]=q[i];
		}
		for(int i=1;i<=n;i++)
		{
			p[i]=q[i];
			q[i]=a[i];
		}

	}
	for(int i=1;i<=n;i++) cout<<q[i]<<" ";
	return 0;
}
