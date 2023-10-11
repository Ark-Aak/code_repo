#include<bits/stdc++.h>
#define int long long
#define re register
#define rep(i,a,b) for(re int i(a);i<=(b);++i)
#define req(i,a,b) for(re int i(a);i>=(b);--i)
using namespace std;
template<typename T> inline T read(T &num)
{
	re int x(0),f(0);char ch(getchar());
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	while(ch>=48&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=f?-x:x;
}
template<typename T> inline void write(T x)
{
	(x<0)?(putchar('-'),x=-x):0;
	(x>9)?(write(x/10),0):0;
	putchar((x%10)^48);
}
int n,k,ans;
bitset<785399> vis;
vector<int> g[785399];
void dfs(int x,int lef,int rig)
{
	vis.set(x);
	for(re int i:g[x]) if(lef<=i&&rig>=i&&!vis.test(i)) dfs(i,lef,rig);
}
inline int gt(int x){return (k^1)?x*x:x;}
signed main()
{	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n);read(k);
	for(re int i(1),x,y;i^n;++i) read(x),read(y),g[x].emplace_back(y),g[y].emplace_back(x);
	rep(l,1,n) rep(r,l,n)
	{
		if(l^r)
		{
			vis=0;
			int res=0;
			rep(i,l,r) if(!vis.test(i)) ++res,dfs(i,l,r);
			ans+=gt(res);
		}
		else ++ans;
	}
	write(ans);
	return 0;
}
