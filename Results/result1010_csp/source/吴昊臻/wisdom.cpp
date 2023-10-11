#include<bits/stdc++.h>
using namespace std;
int n,m,k,mx,tem,lst=1;
long long dp[1005][1005],ans,h[1005],l[1005],mod=1e9+7;
char y;
int main()
{
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.in","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(long long i=1;i<=n;i++)
		h[i]=1;
	for(long long i=1;i<=m;i++)
		l[i]=1;
	for(long long i=1;i<=k;i++)
	{
		cin>>y>>mx>>tem;
		if(y=='R')
			h[mx]=(h[mx]*tem)%mod;
		else
			l[mx]=(l[mx]*tem)%mod;
	}
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++)
			ans=(ans+(((i-1)*m+j)%mod*(h[i]*l[j])%mod)%mod)%mod;
	cout<<ans;
}	
/*
3 4 4
R 2 4
S 4 1
R 3 2
R 2 0
*/
