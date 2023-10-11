#include <bits/stdc++.h>
#define int long long
using namespace std;

template<typename T> void read(T &x)
{
	x = 0;
	T f = 1;char ch = getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f = -1,ch = getchar();
			break;
		}
		ch = getchar();
	}
	while(ch>='0'&&ch<='9')
		x = (x<<3)+(x<<1)+ch-48,ch = getchar();
	x*=f;
}
template<typename T> T read()
{
	T x;read(x);return x;
}
template<typename T> void write(T x)
{
    if(x<0) x = -x,putchar('-');
    if(x<=9) return putchar(x+48),void();
    write(x/10);
    putchar(x%10+48);
}
template<typename T> void writen(T x)
{
    write(x);
    puts("");
}
const int N = 405;
int n,K,a[N],dp[N][N],s[N],mx; 
signed main()
{
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	read(n),read(K);
	for(int i = 1;i<=n;i++)
		read(a[i]);
	for(int i = 1;i<=n;i++)
		s[i] = s[i-1]+a[i];
	memset(dp,63,sizeof dp);
	for(int i = 0;i<=K;i++)
		dp[0][i] = 0;
	for(int i = 1;i<=n;i++)
	{
		mx = max(mx,a[i]);
		dp[i][0] = i*mx-s[i];
		for(int j = 1;j<=K;j++)
		{
			int now = 0;
			for(int k = i-1;k;k--)
				now = max(now,a[k+1]),dp[i][j] = min(dp[k][j-1]+(i-k)*now-(s[i]-s[k]),dp[i][j]);
		}
	}
	int ans = dp[n][0];
	for(int i = 1;i<=K;i++)
		ans = min(dp[n][i],ans);
	write(ans);
	return 0;
}

