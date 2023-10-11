#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],h[500005],head,top;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%lld",&n);
	a[0]=1145141919;
	head=1;
	top=1;
	h[1]=1145141919;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		while(a[i]>=h[top]&&top>=head) top--;
		printf("%lld ",top);
		top++;
		h[top]=a[i];
	}
	return 0;
} 
