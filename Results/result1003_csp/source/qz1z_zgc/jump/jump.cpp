#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,tt;
int a[N],tr[N],q[N];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		while(tt&&q[tt]<=x)tt--;
		q[++tt]=x;
		printf("%d ",tt);
	}
	return 0;
}
