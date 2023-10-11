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
const int N = 3e3+5;
int n,q,m,l[N],r[N],a[N];
signed main()
{
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
	read(n),read(q);
	for(int i = 1;i<=n;i++)
		read(l[i]),read(r[i]);
	while(q--)
	{
		read(m);
		for(int i = 1,x;i<=m;i++)
			read(x),a[x]++;
		for(int i = 1;i<=n;i++)
			a[i]+=a[i-1];
		int ans = 0;
		for(int i = 1;i<=n;i++)
			if((a[r[i]]-a[l[i]-1])%2==1)
				ans++;
		writen(ans);	
		for(int i = 1;i<=n;i++) a[i] = 0;
	}
	return 0;
}

