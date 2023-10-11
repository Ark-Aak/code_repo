#include<bits/stdc++.h>
#define re register
#define int long long
#define rep(i,a,b) for(re int i(a);i<=(b);++i)
#define req(i,a,b) for(re int i(a);i>=(b);--i)
using namespace std;
template<typename T> inline T read(T &num)
{
	re int x=0,f=0; re char ch=getchar();
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	while(48<=ch&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=f?-x:x;
}
template<typename T> inline void write(T x)
{
	(x<0)?(putchar('-'),x=-x):0;
	(x>9)?(write(x/10),0):0;
	putchar(x%10+48);
}
int n,k,a[501];
int dp[501][501];
// dp[i][j] references the minimum cost when the man defeated i monsters and adjusted for j times
signed main()
{
#ifndef ONLINE_JUDGE
	 freopen("path.in","r",stdin);
	 freopen("path.out","w",stdout);
#endif
	read(n);read(k);
	rep(i,1,n) read(a[i]);
	memset(dp,63,sizeof dp);
	dp[0][0]=1;
	rep(in,1,n) // initial num=a[in]
	{
		if(a[in]<a[1]) continue;
		dp[1][0]=min(dp[1][0],a[in]-a[1]);
		dp[1][1]=0;
		rep(i,2,n) 
		{
			int thiscost=dp[i-1][0]+a[in]-a[i];
			dp[i][0]=min(dp[i][0],thiscost<0?1145141919810114:thiscost);
			if(i<=k)dp[i][i]=0;
			rep(j,1,min(i,k))
			{
				dp[i][j]=min(dp[i-1][j-1],dp[i][j-1]);
			}
		}
	}
	int ans=1145141919810114ll;
	//rep(i,1,n){rep(j,0,min(i,k)) cout<<dp[i][j]<<" ";cout<<endl;}

	rep(i,1,k) ans=min(ans,dp[n][i]);
	write(ans);
	return 0;
}
