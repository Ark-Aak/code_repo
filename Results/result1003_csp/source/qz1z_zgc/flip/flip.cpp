#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5,mod=998244353;
typedef long long LL;
int n,k,cnt;
LL f[N][N];
int main()
{
	freopen("flip.in","r",stdin);
	freopen("flip.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==k)
	{
		LL res=1;
		for(int i=1;i<=n;i++)
		{
			res=res*(2*i-1)%mod;
		}
		printf("%lld",res);
	}
	return 0;
}
