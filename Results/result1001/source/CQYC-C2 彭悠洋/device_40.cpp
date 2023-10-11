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
int T,n,k,bit[10],cnt;
signed main()
{
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	read(T);
	while(T--)
	{
		read(k),read(n);
		cnt = 0;
		while(k) bit[++cnt] = k%10,k/=10;
		sort(bit+1,bit+4),cnt = unique(bit+1,bit+4)-bit-1;
		if(n!=1) 
		{
			puts("1");
			continue;
		}
		if(cnt==1) puts("1");
		else if(cnt==2) puts("7");
		else puts("24");
	}
	return 0;
}

