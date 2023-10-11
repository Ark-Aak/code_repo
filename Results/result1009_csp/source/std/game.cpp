#include<bits/stdc++.h>
using namespace std;
#define re register
#define cmin(a,b) ((a)<(b)>(a):(b))
const int MAX=10000000;
const int mod=1000000007;
int smu[10000100],pri[1000100],cnt1;
bool pr[10000100];
int main()
{
	freopen("game.in","r",stdin) ;
	freopen("game.out","w",stdout);
	re int n,m,t,x,y,x1,y1;re unsigned long long y2;
	re int ans;
	smu[1]=1;
	for(re int i=2;i<=MAX;i++)
	{
		if(!pr[i])pri[++cnt1]=i,smu[i]=-i+1;
		for(re int j=1;j<=cnt1&&((y=i*(x=pri[j]))<=MAX);j++)
		if(i%x)smu[y]=smu[i]*(1-x),pr[y]=1;
		else{smu[y]=smu[i],pr[y]=1;break;}
	}
	for(re int i=2;i<=MAX;i++)(smu[i]+=smu[i-1])>=mod?(smu[i]-=mod):smu[i]<0?smu[i]+=mod:0;
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d%d",&n,&m);
		ans=(-2ll*m*n)%mod;if(ans<0)ans+=mod;
		if(n>m)x=n,n=m,m=x;
		for(re int i=1;i<=n;i=x1+1)
		{
			x=n/i,y=m/i;x1=n/x,y1=m/y;if(y1<x1)x1=y1;y2=(unsigned long long)x*y;
			if(y2>1000000000000llu)y2%=mod;y2=y2*(x+y+2)%mod;
			ans=(ans+y2*500000004%mod*(smu[x1]-smu[i-1]+mod))%mod;
		}printf("%u\n",ans);
	}
}
