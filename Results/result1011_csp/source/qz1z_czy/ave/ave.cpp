#include<bits/stdc++.h>
#define rp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=2e6+10;
int n;
int a[N];
double ans;
signed main(void)
{
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	scanf("%d",&n);
	rp(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	ans=a[1];
	rp(i,2,n) ans=(ans+a[i])/2.0;
	printf("%.6f",ans);
	return 0;
}
