#include<bits/stdc++.h>
#define int long long
#define rp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=1e6+10;
int n,q;
struct node{
	int x,y;
}a[N];
signed main(void)
{
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
//	int t1=clock();
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	scanf("%lld %lld",&n,&q);
	rp(i,1,n) scanf("%lld",&a[i].x);
	rp(i,1,n) scanf("%lld",&a[i].y);
	while(q--)
	{
		int u,r,d,l;
		scanf("%lld %lld %lld %lld",&u,&r,&d,&l);
		int res=0;
		rp(i,1,n)
		{
			if(a[i].x>=d&&a[i].x<=u&&a[i].y>=l&&a[i].y<=r)
			{
				int f=0;
				rp(j,1,n)
				{
					if(a[j].x>a[i].x&&a[j].x<=u&&a[j].y>a[i].y&&a[j].y<=r)
					{
						f=1;
						break;
					}
				}
				if(!f) res++;
			}
		}
		printf("%lld\n",res);
	}
//	int t2=clock();
//	printf("%lld",t2-t1);
	return 0;
}
