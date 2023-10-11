#include <bits/stdc++.h>
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
int n,q,x[N];
struct node{
	int x,y;
	friend bool operator < (node x,node y)
	{
		return x.x==y.x?x.y<y.y:x.x<y.x;
	}
}a[N];
signed main()
{
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	read(n),read(q);
	for(int i = 1;i<=n;i++)
		read(a[i].x);
	for(int i = 1;i<=n;i++)
		read(a[i].y);
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)
		x[i] = a[i].x;
	while(q--)
	{
		int lx,rx,ly,ry;
		read(rx),read(ry),read(lx),read(ly);
		int ans = 0,l = lower_bound(x+1,x+n+1,lx)-x,r = upper_bound(x+1,x+n+1,rx)-x-1,mx = 0,_mx = 0;
//		cout<<l<<' '<<r<<'\n';
		for(int i = r;i>=l;i--)
		{
			if(a[i+1].x!=a[i].x&&i!=r) _mx = mx;
			if(a[i].y<ly||a[i].y>ry) continue;
			if(a[i].y>=a[mx].y) mx = i,ans++;//,cout<<"k1 "<<i<<' '<<a[i].x<<' '<<a[i].y<<'\n';
			else if(a[i].x==a[mx].x&&a[i].y>=a[_mx].y) ans++;//,cout<<"k2 "<<a[i].x<<' '<<a[i].y<<' '<<_mx<<'\n';
		}
		writen(ans);
	}
	return 0;
}

