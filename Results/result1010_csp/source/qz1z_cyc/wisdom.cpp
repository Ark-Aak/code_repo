#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[1000005][2],x,y,tot,xx[1005],yy[1005],aw[1000005],qq,mod=1000000007,ans;
char c;
int main()
{
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		a[i][0]=1;
		a[i][1]=(i-1)*m+1;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		scanf("%lld%lld",&x,&y);
		if(c=='R')
		{
			a[x][0]=(a[x][0]*y)%mod;
			a[x][1]=(a[x][1]*y)%mod;
		}
		else
		{
			tot++;
			xx[tot]=x,yy[tot]=y;
		}
	}
	for(int i=1;i<=n;i++)
	{
		aw[1]=(aw[1]+a[i][1])%mod;
		qq=(qq+a[i][0])%mod;
	}
	for(int i=2;i<=m;i++)
	{
		aw[i]=(aw[1]+(i-1)*qq)%mod;
	}
	for(int i=1;i<=tot;i++)
	{
		aw[xx[i]]=(aw[xx[i]]*yy[i])%mod;
	}
	for(int i=1;i<=m;i++) ans=(ans+aw[i])%mod;
	cout<<ans; 
}
 
