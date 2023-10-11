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
int n,q;
struct point
{
	int x,y;
}a[1000001];
int uu,r,d,l,sum[10001][10001],vis[10001][10001],ans;
vector<int> vc[100001];
signed main()
{
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	read(n);read(q);
	rep(i,1,n) read(a[i].x);
	rep(i,1,n) read(a[i].y);
	rep(i,1,n) vis[a[i].x][a[i].y]=1;
//	sort(a+1,a+n+1,[](point x,point y){return x.x<y.x;});
	//req(i,n,1) req(j,n,1) sum[i][j]+=sum[i+1][j]+sum[i][j+1]-sum[i+1][j+1];
	while(q--)
	{
		read(uu);read(r);read(d);read(l);ans=0;
		rep(i,d,uu)rep(j,l,r){if(!vis[i][j])continue;int flg=0; rep(I,i+1,uu)rep(J,j+1,r) if(vis[I][J]){flg=1;break;} if(!flg)++ans;}
		writeln(ans);
	}
	return 0; 
}


