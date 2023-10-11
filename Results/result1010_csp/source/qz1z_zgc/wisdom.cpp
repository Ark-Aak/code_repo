#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mod=1e9+7;
typedef long long LL;
int n,m,k;
LL h[N],l[N],res; 
int main()
{
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)h[i]=1;
	for(int i=1;i<=m;i++)l[i]=1;
	while(k--)
	{
		char op[5];
		int x;
		LL y;
		scanf("%s%d%lld",op,&x,&y);
		if(*op=='R')h[x]=(h[x]*y)%mod;
		else if(*op=='S')l[x]=(l[x]*y)%mod;
	}
	LL plus=0,sum=0;
	for(int i=1;i<=m;i++)
	{
		plus=((1LL*i*l[i])%mod+plus)%mod;
		sum=(sum+l[i])%mod;
	}
	for(int i=1;i<=n;i++)res=(res+(h[i]*((plus+(i-1)*m%mod*sum%mod)%mod)%mod))%mod;
	printf("%lld\n",res);
	return 0;
}
