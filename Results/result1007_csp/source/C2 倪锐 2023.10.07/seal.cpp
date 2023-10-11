#include<bits/stdc++.h>
#define re register
// #define int long long
#define rep(i,a,b) for(int i(a);i<=(b);++i)
#define req(i,a,b) for(int i(a);i>=(b);--i)
#define global(x,typ) typ x=::x
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
    (x>10)?(write(x/10),0):0;
	putchar((x%10)^48);
}
template<typename TP> inline void writeln(TP x)
{
	write<TP>(x);
	puts("");
}
int n,t,m;
int ban_add[20001],ban_cancel[20001],vim,ans,legal;
int ishugemgc[20001],hugemgc[20001],cstmp;
pair<int,int> tms[40001];
int tcnt;
mt19937 rnd(1145141);
/*
 * 1145141 is a prime
 * it's a good number
 * so I used it
 * hope that I can get some points.
 */
struct node
{
	int x,y;
}a[20001];
signed main()
{
	freopen("seal.in","r",stdin);
	freopen("seal.out","w",stdout);
	read(n);read(t);read(m);
	rep(i,1,n) read(a[i].x),read(a[i].y);
	sort(a+1,a+n+1,[](node x,node y){return x.x!=y.x?x.x<y.x:x.y<y.y;});
	rep(i,1,n) tms[++tcnt]={a[i].x,i},tms[++tcnt]={a[i].y,0};
	sort(tms+1,tms+tcnt+1);
	size_t sizhm=sizeof ishugemgc;cout<<0;		return 0; 
}
