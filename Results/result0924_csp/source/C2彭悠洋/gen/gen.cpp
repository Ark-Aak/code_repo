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
const int N = 2e5+5,mod = 1e9+7;
int n,deg[N],ton[N],ans,m;
signed main()
{
	freopen("gen.in","r",stdin);
	freopen("gen.out","w",stdout);
	read(n),read(m);
	for(int i = 1,u,v;i<=m;i++)
		read(u),read(v),deg[u]++,deg[v]++;
	if(n<=2000)
	{
		for(int i = 1;i<=n;i++)
			for(int j = i;j<=n;j++)
				(ans+=(deg[i]^deg[j])%mod*(deg[i]|deg[j])%mod*(deg[i]&deg[j])%mod)%=mod;
		write(ans);
		return 0;
	}
	for(int i = 1;i<=n;i++)
		ton[deg[i]]++;
	for(int i = 1;i<=2000;i++)
		for(int j = i+1;j<=2000;j++)
			(ans+=(i^j)%mod*(i|j)%mod*(i&j)%mod*ton[i]%mod*ton[j]%mod)%=mod;
	write(ans);
	return 0;
}

