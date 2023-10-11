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
int n;
struct node{
	int c,p[5];
	friend bool operator < (node x,node y)
	{
		return x.c<y.c;
	}
}a[N];
int f[N*2],ans;
int find(int x)
{
	if(f[x]==x) return x;
	return f[x] = find(f[x]);
}
signed main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	read(n);
	iota(f+1,f+2*n+1,1);
	for(int i = 1;i<=n;i++)
	{
		read(a[i].c);
		for(int j = 1;j<=4;j++)
			read(a[i].p[j]);
		f[find(a[i].p[1])] = find(a[i].p[2]),f[find(a[i].p[3])] = find(a[i].p[4]);
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)
		if(find(a[i].p[1])!=find(a[i].p[3])||find(a[i].p[2])!=find(a[i].p[4]))
			ans+=a[i].c,f[find(a[i].p[1])] = f[find(a[i].p[3])],f[find(a[i].p[2])] = f[find(a[i].p[4])];
	write(ans);
	return 0;
}

