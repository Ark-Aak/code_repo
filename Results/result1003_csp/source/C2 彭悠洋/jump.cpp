#include <bits/stdc++.h>
#define int long long
#define ls (k*2)
#define rs (k*2+1)
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
const int N = 5e5+5,inf = 2e9;
int n,t[N*4],ans[N];
void pushup(int k)
{
	t[k] = max(t[ls],t[rs]);
}
void build(int k,int l,int r)
{
	if(l==r) return t[k] = -inf,void();
	int mid = (l+r)/2;
	build(ls,l,mid),build(rs,mid+1,r);
	pushup(k);
}
void change(int k,int l,int r,int x,int v)
{
	if(l==r) return t[k] = v,void();
	int mid = (l+r)/2;
	if(mid>=x) change(ls,l,mid,x,v);
	else change(rs,mid+1,r,x,v);
	pushup(k);
}
int ask(int k,int l,int r,int v)
{
	if(l==r) return l;
	int mid = (l+r)/2;
	if(t[rs]>v) return ask(rs,mid+1,r,v);
	else if(t[ls]>v) return ask(ls,l,mid,v);
	return 0;
}
signed main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	read(n);
	build(1,1,n);
	for(int i = 1,x;i<=n;i++)
		read(x),change(1,1,n,i,x),ans[i] = ans[ask(1,1,n,x)]+1;
	for(int i = 1;i<=n;i++)
		write(ans[i]),putchar(32);
	return 0;
}

