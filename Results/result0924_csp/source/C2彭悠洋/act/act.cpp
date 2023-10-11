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
int n,q; 
signed main()
{
	freopen("act.in","r",stdin);
	freopen("act.out","w",stdout);
	read(n),read(q);
	for(int i = 1,x;i<=n;i++)
		read(x),read(x);
	while(q--)
	{
		if(read<int>()==0)
		{
			read<int>();
			puts("Alice");
			continue;
		}
		if(read<int>()==0)
		{
			puts("Alice");
			continue;
		}
		puts("Bob");
	}
	return 0;
}
