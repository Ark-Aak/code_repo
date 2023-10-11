#include<bits/stdc++.h>
#define int long long
#define rp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int n,mod,s=1;
signed main(void)
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
//	int t1=clock();
	scanf("%lld %lld",&n,&mod);
	rp(i,1,n) s=s*i%mod;
	printf("%lld\n",s%mod);
//	int t2=clock();
//	printf("%lld",t2-t1);
	return 0;
}
