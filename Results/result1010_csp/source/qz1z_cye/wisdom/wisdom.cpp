#include<bits/stdc++.h>
using namespace std;
long long n,m,k,gc[1000005],lie[1000005],x,y,mod=1e9+7,ans,sum,last;
char cc;
int main()
{
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) gc[i]=1;
	for(int i=1;i<=m;i++) lie[i]=1;
	for(int i=1;i<=k;i++)
	{
		cin>>cc;
		scanf("%lld%lld",&x,&y);
		if(cc=='R')
		{
			gc[x]=(gc[x]*y)%mod;
		}
		else
		{
			lie[x]=(lie[x]*y)%mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		sum=(sum+gc[i])%mod;
	} 
	for(int i=1;i<=n;i++)
	{
		last=(last+(((i-1)*m+1)*gc[i])%mod)%mod;
	}
	ans=(lie[1]*last)%mod;
	for(int i=2;i<=m;i++)
	{
		last+=sum;
		last%=mod;
		ans=(ans+last*lie[i])%mod;
	}
	cout<<ans;
	return 0;
}
