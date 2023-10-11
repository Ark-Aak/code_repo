#include<bits/stdc++.h>
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
int n,a[5001],ans,b[5001];
bool t[5001];
inline int calc()
{
	memset(t,0,sizeof t);
	rep(i,1,n) t[b[i]]=1;
	rep(i,0,5000) if(!t[i]) return i;
	return 1145141919;
}
void dfs(int p)
{
	if(p==n+1) return ans+=calc(),void();
	rep(i,0,a[p]) b[p]=i,dfs(p+1);
}
signed main()
{
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	read(n);
	rep(i,1,n) read(a[i]);
	dfs(1);
	write(ans);
	return 0; 
}
