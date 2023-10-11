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
const int N = 1e5+5;
int n,k;
struct per{
	int p[N];
	void init(int x)
	{
		for(int i = 0;i<N;i++)
			p[i] = x;
	}
	friend per operator + (per x,per y)
	{
		per res;
		res.init(0);
		for(int i = 1;i<=n;i++)
			res.p[x.p[i]] = y.p[i];
		return res;
	}
}a,b,tmp;
signed main()
{
//	freopen("permutation.in","r",stdin);
//	freopen("permutation.out","w",stdout);
	read(n);
	for(int i = 1;i<=n;i++) read(a.p[i]);
	for(int i = 1;i<=n;i++) read(b.p[i]);
	for(int i = 1;i<=200;i++)
	{
		tmp = b,b = a+b,a = tmp;
		cout<<i<<':';
		for(int j = 1;j<=n;j++) write(a.p[j]),putchar(32);
		puts("");
	}
	return 0;
}

