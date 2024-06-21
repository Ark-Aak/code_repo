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
template<typename T = int> inline T read()
{
	T x;read(x);return x;
}
template<typename T> void write(T x)
{
    if(x<0) x = -x,putchar('-');
    if(x>9) write(x/10);
    putchar(x%10+48);
}
template<typename T> inline void writen(T x)
{
    write(x);
    putchar(10);
}
const int N = 3e6+5;
int n,m;
struct node{
	int x,id;
	inline friend bool operator < (node x,node y){return x.x<y.x;}
}a[N];
namespace bit{
	int t[N];
	#define lowbit(x) (x&(-x))
	inline void add(int x)
	{
		for(;x;x-=lowbit(x))
			t[x]++;
	}
	inline int ask(int x)
	{
		int res = 0;
		for(;x<=m;x+=lowbit(x))
			res+=t[x];
		return res;
	}
}
namespace sgt{
	struct node{
		int mn,mx,tag;
	}t[N<<2];
	#define ls (k<<1)
	#define rs (k<<1|1)
	inline void pushup(int k)
	{
		t[k].mn = min(t[ls].mn,t[rs].mn);
		t[k].mx = max(t[ls].mx,t[rs].mx);
	}
	inline void add(int k,int v){t[k].mn+=v,t[k].mx+=v,t[k].tag+=v;}
	inline void down(int k)
	{
		if(!t[k].tag) return;
		add(ls,t[k].tag),add(rs,t[k].tag);
		t[k].tag = 0;
	}
	inline void change(int k,int l,int r,int x,int y,int v)
	{
		if(l>y||r<x) return;
		if(l>=x&&r<=y) return add(k,v);
		int mid = (l+r)/2;
		down(k);
		change(ls,l,mid,x,y,v),change(rs,mid+1,r,x,y,v);
		pushup(k);
	}
	#undef ls
	#undef rs
}
signed main(int argc, char** argv)
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	freopen(argv[1], "rb", stdin);
	freopen(argv[2], "wb", stdout);
	read(n),read(m);
	long long ans1 = 0,ans2 = 0;
	for(int i = 1,x;i<=m;i++)
		read(a[i].x),a[i].id = i;
	sort(a+1,a+m+1);
	for(int i = 1;i<=m;i++)
		ans1+=bit::ask(a[i].id+1),bit::add(a[i].id);
	ans2 = ans1;
	for(int i = 1;i<=m;i++)
		sgt::change(1,0,m,i,m,1);
	for(int i = 1;i<=m;i++)
	{
		int l = a[i-1].x+1,r = a[i].x-1,ll = l-i,rr = r-i;
		ans1+=1ll*(r-l+1)*sgt::t[1].mn;
		ans2+=1ll*(r-l+1)*sgt::t[1].mx+1ll*(ll+rr)*(r-l+1)/2;
		sgt::change(1,0,m,0,a[i].id-1,1),sgt::change(1,0,m,a[i].id,m,-1);
	}
	int l = a[m].x+1,r = n,ll = l-m-1,rr = r-m-1;
	ans1+=1ll*(r-l+1)*sgt::t[1].mn;
	ans2+=1ll*(r-l+1)*sgt::t[1].mx+1ll*(ll+rr)*(r-l+1)/2;
	write(ans1),putchar(32),write(ans2);
	return 0;
}
