#include<bits/stdc++.h>
#define Alice 0
#define Bob 1
#define is ==
#define re register
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
int n,m,x,y,z,dp[5001][5001][2];
vector<pair<int,int>> g[500001];
int dfs(int p,int pre,int who)
{
	if(dp[p][pre][who]) return dp[p][pre][who];
	int cnt;
	if(who==Alice) cnt=-1;
	else cnt=0x3f3f3f3f;
	for(re pair<int,int> i:g[p]) if(i.second>pre)
	{
		if(who==Alice) cnt=max(cnt,dfs(i.first,i.second,!who)+1);
		else cnt=min(cnt,dfs(i.first,i.second,!who)+1);
	}
	return dp[p][pre][who]=(cnt<0||cnt>1e9)?1:cnt;
}
signed main()
{
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	read(n);read(m);
	rep(i,1,m) read(x),read(y),read(z),g[x].emplace_back(y,z),g[y].emplace_back(x,z);
	rep(i,1,n)
	{
	//	cnt=0;
		write(dfs(i,-1,Alice,0)-1),putchar(' ');
	}
	return 0; 
}
