#include <bits/stdc++.h>
#define lowbit(x) (x&(-x))
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
const int N = 2e5+5;
int ans,n,a[N];
int t[N];
void add(int x,int v)
{
	for(;x<=n;x+=lowbit(x))
		t[x]+=v;
}
int ask(int x)
{
	int res = 0;
	for(;x;x-=lowbit(x))
		res+=t[x];
	return res;
}
int l[N],r[N],vis[N];
signed main()
{
	freopen("gather.in","r",stdin);
	freopen("gather.out","w",stdout);
	read(n);
	for(int i = 1;i<=n;i++)
		read(a[i]);
	for(int i = 1;i<=n;i++)
	{
		if(vis[a[i]]) add(vis[a[i]],-1);
		ans+=ask(i-1)-ask(vis[a[i]]);
		vis[a[i]] = i;
		add(i,1);
	}
	write(ans);
	return 0;
}

