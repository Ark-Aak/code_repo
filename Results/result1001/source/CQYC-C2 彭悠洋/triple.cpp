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
int a[4],b[4],x[4],y[4],T;
int get(int x,int y,int u,int v)
{
	if(x==u&&y==v) return 0;
	if(x-y==u-v||x*v==u*y) return 1;
	return 2;
}
signed solve()
{
//	if(get(a[1],a[2],b[1],b[2])==1&&get(a[2],a[3],b[2],b[3])==1) return puts("1"),0;
	int cnt = 0;
	for(int i = 1;i<=3;i++)
		if(a[i]!=b[i])
			x[++cnt] = a[i],y[cnt] = b[i];
	if(cnt<=1) return writen(cnt),0;
	if(cnt==2) return writen(get(x[1],x[2],y[1],y[2])),0;
	int flag1 = 0,flag2 = 0;
	for(int i = 2;i<=3;i++)
	{
		if(a[i]-a[i-1]!=b[i]-b[i-1]) flag1++;
		if(a[i]*b[i-1]!=a[i-1]*b[i]) flag2++;
	}
	if(flag1==0||flag2==0) return puts("1"),0;
	if(flag1==1||flag2==1||a[3]-a[1]==b[3]-b[1]||a[3]*b[1]==a[1]*b[3]) return puts("2"),0;
	if(b[1]==b[2]&&b[2]==b[3]) return puts("2"),0;
	if(b[1]==0&&b[2]==b[3]) return puts("2"),0;
	if(b[2]==0&&b[1]==b[3]) return puts("2"),0;
	if(b[3]==0&&b[1]==b[2]) return puts("2"),0;
	if(b[2]!=b[1]) if((a[2]-a[1])%(b[2]-b[1])==0)
	{
		int mul = (a[2]-a[1])/(b[2]-b[1]);
		if(mul==0) {if(b[2]==b[1]&&b[3]==b[2]) return puts("2"),0;}
		if((a[2]*mul)*b[3]==(a[3]*mul)*b[2]) return puts("2"),0;
	}
	if(a[2]!=a[1]) if((b[2]-b[1])%(a[2]-a[1])==0)
	{
		int mul = (b[2]-b[1])/(a[2]-a[1]);
		if(mul==0) {if(b[2]==b[1]&&b[3]==b[2]) return puts("2"),0;}
		else if((a[2]*mul)*b[3]==(a[3]*mul)*b[2]) return puts("2"),0;
	}
	return writen(min({get(a[1],a[2],b[1],b[2]),get(a[1],a[3],b[1],b[3]),get(a[2],a[3],b[2],b[3])})+1),0;
}
signed main()
{
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	read(T);
	while(T--)
	{
		for(int i = 1;i<=3;i++)
			read(a[i]);
		for(int i = 1;i<=3;i++)
			read(b[i]);
		solve();
	}
	return 0;
}/*
1
-2 0 6
-6 -3 -1*/
