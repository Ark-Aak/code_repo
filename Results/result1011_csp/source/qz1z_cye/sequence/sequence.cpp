#include<bits/stdc++.h>
using namespace std;
long long n,m,f[2005][2005],ans[2005],mod=998244353;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++) f[1][i]=1;
	ans[1]=m%mod;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]+=ans[i-1];
			f[i][j]%=mod;
			for(int h=j+j;h<=m;h+=j)
			{
				f[i][j]=(f[i][j]+mod-f[i-1][h])%mod;
			}
		}
		for(int j=1;j<=m;j++) ans[i]=(ans[i]+f[i][j])%mod;
	}
	cout<<ans[n];
	return 0;
 } 
