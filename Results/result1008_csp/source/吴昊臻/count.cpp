#include<bits/stdc++.h>
using namespace std;
long long n,m,dp[5005][5005],a[100005],mx,w,mod=998244353,b[500005],top=1;
int ksm(long long i,long long j)
{
	long long ans=1,ans1=i;
	while(j!=0)
	{
		if(j%2) ans=(ans*ans1)%mod;
		ans1=(ans1*ans1)%mod;
		j/=2;
	}
	return ans;
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	dp[1][1]=m;
	b[1]=m;
	for(long long i=1;i<=m;i++)
		cin>>a[i],mx=max(a[i],mx);
	sort(a+1,a+m+1);
	for(long long i=2;i<=n;i++)
	{
		while(a[top]<i) top++;
		b[i]=m-top+1;
	}
	for(long long i=2;i<=n;i++)
	{
		for(long long j=1;j<=mx;j++)
		{
			if(dp[i-1][j-1]!=0)
			dp[i][j]=(dp[i-1][j-1]*b[j]*ksm(b[j-1],mod-2))%mod;
			if(j==1)
				for(long long z=1;z<=n;z++)
					dp[i][j]=(dp[i][j]+dp[i-1][z]*(m-1))%mod;
		} 
	}
	for(long long i=0;i<=n;i++)
		w+=dp[n][i],w%=mod;
	cout<<w;
}
/*
20 30
12 3 11 8 2 1 10 4 3 3 7 19 18 18 5 10 4 3 9 15 9 15 13 9 10 4 20 3 17 6 
*/
