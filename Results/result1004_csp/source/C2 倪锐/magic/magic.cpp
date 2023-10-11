#include<bits/stdc++.h>
#define re register
#define int long long
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
#define y1 y_one
#define y2 y_two
int n,cost[100001],x1,y1,x2,y2,cnt;
vector<int> g[200001];
inline void add_edge(int x,int y)
{
	g[x].emplace_back(y);
	g[y].emplace_back(x);
}
bitset<200001> vis; 
void dfs(int p)
{
	vis.set(p);
	for(re int i:g[p]) if(!vis.test(i)) dfs(i);
}
signed main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	read(n);
	rep(i,1,n) read(cost[i]),read(x1),read(y1),read(x2),read(y2),add_edge(x1,y1),add_edge(x2,y2);
	vis.reset();
	rep(i,1,n) if(!vis.test(i)) dfs(i),++cnt;
	sort(cost+1,cost+n+1);
	int ans=0;
	rep(i,1,cnt) ans+=cost[i];
	writeln(ans);
	return 0; 
}
