#include<bits/stdc++.h>
#define re register
 #define int long long
#define rep(i,a,b) for(re int i(a);i<=(b);++i)
#define req(i,a,b) for(re int i(a);i>=(b);--i)
using namespace std;
// #define getchar()
template<typename T> inline T read(T &num)
{
	re T x=0,f=0;re char ch=getchar();
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	while(48<=ch&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=f?-x:x;
}
template<typename T> inline void write(T x)
{
	(x<0)?(putchar('-'),x=-x):0;
	(x>9)?(write(x/10),0):0;
	putchar((x%10)^48);
}
int n,m,c,w[4001],x,y,ans=0;
vector<int> g[4001];
bitset<4001> vis;
void dfs(int x,int got,int pw)
{
	if(x==1)
	{
		ans=max(ans,got);
		return;
	}
	vis.set(x);
	for(re int i:g[x]) if(i==1) dfs(i,got+w[i]-c*pw*pw,pw+1);
					   else if(!vis.test(i)) dfs(i,got+w[i]-c*pw*pw,pw+1);
	vis.set(x,0);
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
#endif
	read(n);read(m);read(c);
	rep(i,1,n) read(w[i]);
	rep(i,1,m) read(x),read(y),g[x].emplace_back(y);
	vis.reset();
	vis.set(1);
	for(re int i:g[1]) dfs(i,w[i]-c,1);
	cout<<ans;
	return 0;
}
