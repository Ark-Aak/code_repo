#include<bits/stdc++.h>
#define int long long
#define go(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
using namespace std;
const int N=5e5+10;
int n;
struct Node{
	int l,r;
}a[N];
int ans;
signed main(void)
{
	freopen("explorer.in","r",stdin);
	freopen("explorer.out","w",stdout);
	scanf("%lld",&n);
	int fl=0;
	go(i,1,n)
	{
		scanf("%lld %lld",&a[i].l,&a[i].r);
		if(a[i].l>a[i].r) swap(a[i].l,a[i].r);
		if(a[i].l!=2*i-1||a[i].r!=2*i) fl=1;
	}
	if(!fl) printf("%lld",n*(n-1)/2*(n-2)/3);
	go(i,1,n)
	{
		go(j,i+1,n)
		{
			go(k,j+1,n)
			{
				if(a[i].l<a[i].r&&a[i].r<a[j].l&&a[j].l<a[j].r&&a[j].r<a[k].l&&a[k].l<a[k].r) ans++;
				if(a[i].l<a[j].l&&a[j].l<a[j].r&&a[j].r<a[k].l&&a[k].l<a[k].r&&a[k].r<a[i].r) ans++;
				if(a[i].l<a[j].l&&a[j].l<a[k].l&&a[k].l<a[i].r&&a[i].r<a[j].r&&a[j].r<a[k].r) ans++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
