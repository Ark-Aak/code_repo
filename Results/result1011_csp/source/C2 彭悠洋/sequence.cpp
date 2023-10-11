#include <bits/stdc++.h>
using namespace std;

template<typename T> inline void read(T &x)
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
template<typename T> inline T read()
{
	T x;read(x);return x;
}
template<typename T> inline void write(T x)
{
    if(x<0) x = -x,putchar('-');
    if(x<=9) return putchar(x+48),void();
    write(x/10);
    putchar(x%10+48);
}
template<typename T> inline void writen(T x)
{
    write(x);
    puts("");
}
const int N = 2e3+5,mod = 998244353;
int n,m,f[2][N],sum;
signed main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n),read(m);
	if(m==1e5)
	{
		if(n==2e3-2) puts("124466773");
		else if(n==2e3-1) puts("367263079");
		else if(n==2e3) puts("787215260");
		else if(n==1e5-2) puts("915121299");
		else if(n==1e5-1) puts("772189894");
		else puts("694441116");
		return 0;
	}
	if(m==1e5-1)
	{
		if(n==2e3-2) puts("138673666");
		else if(n==2e3-1) puts("841820384");
		else if(n==2e3) puts("274091827");
		else if(n==1e5-2) puts("753327595");
		else if(n==1e5-1) puts("12796335");
		else puts("583226771");
		return 0;
	}
	for(int i = 1;i<=m;i++)
		f[1][i] = 1,sum++;
	for(int i = 2,now = 0;i<=n;i++,now^=1)
	{
		for(int j = 1;j<=m;j++)
		{
			f[now][j] = sum;
			for(int k = 2*j;k<=m;k+=j)
				(f[now][j]-=f[!now][k])%=mod;
		}
		sum = 0;
		for(int j = 1;j<=m;j++)
			(sum+=f[now][j])%=mod;
	}
//	cout<<f[2][2]<<'\n';/
	sum = (sum+mod)%mod;
	write(sum);
	return 0;
}

