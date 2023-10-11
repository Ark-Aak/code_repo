#include<bits/stdc++.h>
#define re register
#define mod 1000000007
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
int a[1001][1001],n,m,q;
char opt;
int x,y;
signed main()
{
	freopen("1.in","r",stdin);
	freopen("wisdom_暴力.out","w",stdout);
	read(n);read(m);read(q);
	rep(i,1,n)rep(j,1,m) a[i][j]=++x;
	while(q--)
	{
		while(!isalpha(opt=getchar()));
		read(x);read(y);
		if(opt=='R') rep(i,1,m) (a[x][i]*=y)%=mod;
		else rep(i,1,n) (a[i][x]*=y)%=mod;
	}
	int ans=0;
	rep(i,1,n) rep(j,1,m) (ans+=a[i][j])%=mod;
	write(ans);
	return 0; 
}
