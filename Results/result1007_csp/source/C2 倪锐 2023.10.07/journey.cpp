#include<bits/stdc++.h>
#define re register
#define _Yes_ puts("Yes")
#define _No_ puts("No")
// #define int long long
#define rep(i,a,b) for(int i(a);i<=(b);++i)
#define req(i,a,b) for(int i(a);i>=(b);--i)
using namespace std;
char buf[1<<23],*p1=buf,*p2=buf,ubuf[1<<23],*u=ubuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template<typename TP> inline TP read(TP &num)
{
	re TP x=0;re int f=0;re char ch=getchar();
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	while(48<=ch&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=f?-x:x;
}
template<typename TP> inline void write(TP x)
{
	(x<0)?(putchar('-'),x=-x):0;
    (x>9)?(write(x/10),0):0;
	putchar((x%10)^48);
}
template<typename TP> inline void writeln(TP x)
{
	write<TP>(x);
	puts("");
}
int n,m,q,l,r,x,y,ans;
bitset<1000001> vis;
vector<pair<int,int>> g[1000001];
void dfs(int p,int vim,int goal,int gvim)
{
	if(vim>gvim) return;
	if(p==goal) return ans=1,void();
	vis.set(p);
	for(pair<int,int> i:g[p]) if(i.second>=vim&&!vis.test(i.first)) dfs(i.first,i.second,goal,gvim);
}
signed main()
{
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	read(n);read(m);read(q);
	rep(i,1,m) read(x),read(y),g[x].emplace_back(y,i),g[y].emplace_back(x,i);
	rep(journey,1,q)
	{
		read(l),read(r),read(x),read(y);
		ans=0;vis.reset();
		dfs(x,l,y,r);
		ans?_Yes_:_No_;
	} 
	return 0; 
}
