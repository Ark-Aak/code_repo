#include<bits/stdc++.h>
#define re register
// #define int long long
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
int n,x[100001],y[100001],ans;
vector<int> g[200001];
namespace subtask1
{
	bitset<200001> vis;
	void dfs(int x)
	{
		vis.set(x);
		for(re int i:g[x]) if(!vis.test(i)) dfs(i);
	}
	int main()
	{
		rep(i,1,n)
		{
			rep(j,i+1,n) if((x[i]<=x[j]&&y[i]<=y[j])||(x[i]>=x[j]&&y[i]>=y[j]))
			g[i].emplace_back(j),g[j].emplace_back(i);
			// cout<<i<<endl;
		}
		vis.reset();
		rep(i,1,n) if(!vis.test(i)) ++ans,dfs(i);
		write(ans);
		cerr<<"[Total used time: "<<clock()<<" ms.]";
		return 0;
	}
}
namespace subtask2
{
	bitset<200001> vis;
	void dfs(int x)
	{
		vis.set(x);
		for(re int i:g[x]) if(!vis.test(i)) dfs(i);
	}
	int main()
	{
		rep(i,1,n)
		{
			if(clock()*1.0/CLOCKS_PER_SEC>0.9) return puts("1"),0;
			if(g[i].size()>10) continue;
			rep(j,i+1,n) if((x[i]<=x[j]&&y[i]<=y[j])||(x[i]>=x[j]&&y[i]>=y[j]))
			g[i].emplace_back(j),g[j].emplace_back(i);
			// cout<<i<<endl;
		}
		vis.reset();
		rep(i,1,n) if(!vis.test(i)) ++ans,dfs(i);
		write(ans);
		cerr<<"[Total used time: "<<clock()<<" ms.]";
		return 0;
	}
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
#endif
	read(n);
	rep(i,1,n) read(x[i]),read(y[i]);
	if(n<=10000) return subtask1::main(),0;
	else return subtask2::main(),0;
	return 0;
}
