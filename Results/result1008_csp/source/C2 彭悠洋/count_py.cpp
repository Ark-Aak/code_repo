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
const int N = 5e3+5,M = 1e5+5,mod = 998244353;
int n,m,k,a[M],b[M],ton[N],dp[N][N],g[N];
signed main()
{
//	freopen("count.in","r",stdin);
//	freopen("count.out","w",stdout);
	read(n),read(m);
	for(int i = 1;i<=m;i++)
		read(a[i]),b[i] = a[i],ton[a[i]]++;
//	sort(b+1,b+m+1);
//	k = unique(b+1,b+m+1)-b-1;
	k = m;
//	for(int i = 1;i<=k;i++)
//		cout<<b[i]<<' '<<ton[b[i]]<<'\n';
//	cout<<k<<'\n';
	for(int i = 1;i<=k;i++)
		dp[1][i] = 1;//ton[b[i]];
	g[1] = m;
	g[0] = 1;
	for(int i = 2;i<=n;i++)
	{
		for(int j = 1;j<=k;j++)
		{
			if(i-b[j]-1==0) dp[i][j] = (g[i-1]-1)%mod;
			else if(i-b[j]-1>0) dp[i][j] = (g[i-1]-g[max(0ll,i-b[j]-1)]+dp[i-b[j]-1][j])%mod;
			else dp[i][j] = g[i-1]%mod;
			(g[i]+=dp[i][j])%=mod;
		}
	}
//	for(int i = 1;i<=n;i++)
//		for(int j = 1;j<=k;j++)
//			cout<<dp[i][j]<<" \n"[j==k];
	int ans = 0;
	for(int i = 1;i<=k;i++)
		(ans+=dp[n][i])%=mod;
	ans = (ans+mod)%mod;
	write(ans);
	return 0;
}

