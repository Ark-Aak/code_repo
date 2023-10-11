#include<bits/stdc++.h>
#define int long long
#define go(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
using namespace std;
const int N=5e5+10;
int n;
int a[N],f[N];
signed main(void)
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d",&n);
	a[0]=INT_MAX;
	go(i,1,n)
	{
		scanf("%lld",&a[i]);
		int x=a[i];
		int s;
		for(int j=n-1;j>=0;j--)
		{
			if(a[j]>x)
			{
				f[i]++;
				x=a[j];
			}
		}
	}
	go(i,1,n) printf("%lld ",f[i]);
	return 0;
}
