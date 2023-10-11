#include <bits/stdc++.h>
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
const int mod = 1e9+7;
int get(int n)
{
	int res = 0;
	for(int len = 1;len<=n;len++)
		(res+=len*len%mod*(n-len+1)%mod)%=mod;
	return res;
}
int get_py(int n)
{
	int res = 0;
	for(int i = 1;i<=n;i++)
		for(int j = i;j<=n;j++)
			(res+=(j-i+1)*(j-i+1)%mod)%=mod;
	return res;
}
int x;
signed main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	while(1) write(get(x = read<int>())),putchar(32),writen(get_py(x));
	return 0;
}

