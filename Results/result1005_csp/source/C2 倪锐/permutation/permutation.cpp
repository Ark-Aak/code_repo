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
struct per
{
	int p[100003],n;
	inline void reset(){memset(p,0,sizeof p);n=0;}
	inline void resize(int N){n=N;}
	inline void resetsize(int N){reset();resize(N);}
	inline int size(){return n;}
	inline void swap(per a)
	{
		assert(size()==a.size());
		per tmp;
		tmp.resetsize(size());
		tmp=a;
		memcpy(a.p,p,sizeof(int)*(size()+2));
		memcpy(p,tmp.p,sizeof(int)*(size()+2));
	}
}x,y,z;
per operator + (per x,per y)
{
	assert(x.size()==y.size());
	per res;
	res.resetsize(x.size());
	rep(i,1,x.size()) res.p[x.p[i]]=y.p[i];
	return res;
}
inline void readper(per &x)
{
	rep(i,1,x.size()) read(x.p[i]);
}
inline void writeper(per x,char mid)
{
	rep(i,1,x.size()) write(x.p[i]),putchar(mid);
}
int n,k;
signed main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	read(n),read(k),--k;
	x.resetsize(n),y.resetsize(n),z.resetsize(n);
	readper(x),readper(y);
	rep(i,1,k) z=x+y,x.swap(y),y.swap(z);
	writeper(y,' ');
	return 0; 
}
