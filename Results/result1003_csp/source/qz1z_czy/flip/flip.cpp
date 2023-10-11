#include<bits/stdc++.h>
#define int long long
#define go(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
using namespace std;
const int N=5e5+10;
const int Mod=998244353;
int ans;
int n,k;
signed main(void)
{
	freopen("flip.in","r",stdin);
	freopen("flip.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	ans=k==1? (n*(n+1)%Mod/2):(n*(n+2));
	printf("%lld",ans%Mod);
	return 0;
}
