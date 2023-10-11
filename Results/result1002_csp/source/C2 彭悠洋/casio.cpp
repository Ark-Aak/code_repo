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
const int N = 3e7,M = 2e6+5;
int T,p,ans[N+5],zhi[M],cnt,mn[N+5];
signed main()
{
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	read(T),read(p);
	for(int i = 2;i<=N;i++)
	{
		if(mn[i]==0) zhi[++cnt] = i;
		for(int j = 1;j<=cnt&&zhi[j]*i<=N;j++)
		{
			mn[zhi[j]*i] = zhi[j];
			if(i%zhi[j]==0) break;
		}
	}
	for(int i = N,now = N+1;i;i--)
	{
		if(mn[i]>p||mn[i]==0) now = i;
		ans[i] = now;
	}
	while(T--) writen(ans[read<int>()]);
	return 0;
}
//15 p = 2
//1:3*3*3 = 27
//2:3*5 = 15
