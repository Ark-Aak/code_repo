#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re register
#define rep(i,a,b) for(re int i(a);i<=(b);++i)
#define req(i,a,b) for(re int i(a);i>=(b);--i)
char buf[1<<23],*p1=buf,*p2=buf,ubuf[1<<23],*u=ubuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
template<typename T> inline T read(T &num)
{
	re int x=0,f=0;
	re char ch=getchar();
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
template<typename T> inline void writeln(T x)
{
	write<T>(x);
	puts("");
}
int n,q,m,a[500001],bgn[500001],ans;
struct interval
{
	int l,r;
}x[500001],y[500001];
namespace subtask1
{
	int main()
	{
		read(q);
		rep(i,1,n) read(x[i].l),read(x[i].r);
		size_t siz=sizeof(int)*(n+2);
		rep(_,1,q)
		{
			read(m);
			memset(bgn,0,siz);
			rep(i,1,m) read(a[i]),++bgn[a[i]];
			rep(i,1,n) bgn[i]+=bgn[i-1];
			ans=0;
			rep(i,1,n) ans+=bool((bgn[x[i].r]-bgn[x[i].l-1])&1);
		    writeln(ans);	
		}
		return 0;
	}
}
signed main()
{
	freopen("badge.in","r",stdin);
	freopen("badge.out","w",stdout);
	read(n);
	if(n*q<=1e8) subtask1::main();
	else subtask1::main();
	cerr<<"[Total used time: "<<clock()<<"ms.]";
	return 0;
}
