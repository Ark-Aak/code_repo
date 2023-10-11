#include <bits/stdc++.h>
#define int long long 
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
const int N = 1e6+5;
int n,a[N];
signed main()
{
	freopen("ave.in","r",stdin);
	freopen("ave.out","w",stdout);
	read(n);
	for(int i = 1;i<=n;i++)
		read(a[i]);
	sort(a+1,a+n+1);
	double ans = a[1];
	for(int i = 2;i<=n;i++)
		ans = (ans+a[i])*1.0/2;
	printf("%.6lf",ans);
	return 0;
}

