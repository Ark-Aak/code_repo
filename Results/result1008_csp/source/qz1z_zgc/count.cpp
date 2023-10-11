#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=998244353LL;
LL n,m;
LL quick_power(LL a,LL b)
{
	LL res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	LL res=quick_power((LL)m,(LL)n),cnt=0;
	for(LL i=1;i<=m;i++)
	{
		LL x,flag=1;
		scanf("%lld",&x);
		cnt+=x;
		for(LL j=x+1;j<=n;j++)//Á¬Ðøj¸öi
		{
			flag=-flag;
			LL t=(n-j+1)%mod*quick_power(m,n-j)%mod*flag%mod;
			t=((t%mod)+mod)%mod;
			res=(res+t)%mod;
		}
	}
	if(cnt<n)puts("0");
	else printf("%lld\n",((res%mod)+mod)%mod);
	return 0;
} 
