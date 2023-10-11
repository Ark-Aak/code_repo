#include<bits/stdc++.h>
using namespace std;
#define int long long
#define re register
#define rep(i,a,b) for(re int i(a);i<=(b);++i)
#define req(i,a,b) for(re int i(a);i>=(b);--i)
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
int T,p,q,r,a,b,c;
signed main()
{
	freopen("triple.in","r",stdin);
	freopen("triple.out","w",stdout);
	read(T);
	while(T--)
	{
		read(p),read(q),read(r),read(a),read(b),read(c);
		if(p==a&&q==b&&r==c) puts("0");
		else if(!a&&!b&&!c) puts("1");
		else if((p==a)+(q==b)+(r==c)==2) puts("1");
		else if(p-a==q-b&&q-b==r-c) puts("1");
		else if(p&&q&&r&&a%p==0&&b%q==0&&c%r==0&&a/p==b/q&&a/p==c/r) puts("1");
		else if(p==a&&q-b==r-c) puts("1");
		else if(q==b&&p-a==r-c) puts("1");
		else if(r==c&&q-b==p-a) puts("1");
		else if(q&&r&&p==a&&b%q==0&&c%r==0&&b/q==c/r) puts("1");
		else if(p&&r&&q==b&&a%p==0&&c%r==0&&a/p==c/r) puts("1");
		else if(q&&p&&r==c&&b%q==0&&a%p==0&&b/q==a/p) puts("1");
		else if(p==a&&(!b||!c)) puts("2");
		else if(q==b&&(!a||!c)) puts("2");
		else if(r==c&&(!b||!a)) puts("2");	
		else if(p==a&&q%b==r%c) puts("2");
		else if(q==b&&p%a==r%c) puts("2");
		else if(r==c&&q%b==p%a) puts("2");
		else if(p==a) puts("2");
		else if(q==b) puts("2");
		else if(r==c) puts("2");
		else if(a==b&&!c) puts("2");
		else if(a==c&&!b) puts("2");
		else if(b==c&&!a) puts("2");
		else if(!a&&!b) puts("2");
		else if(!b&&!c) puts("2");
		else if(!a&&!c) puts("2");
		// -------------------------------------------------
		else if(q-b==r-c) puts("2");
		else if(p-a==r-c) puts("2");
		else if(q-b==p-a) puts("2");
		else if(q&&r&&b%q==0&&c%r==0&&b/q==c/r) puts("2");
		else if(p&&r&&a%p==0&&c%r==0&&a/p==c/r) puts("2");
		else if(q&&p&&b%q==0&&a%p==0&&b/q==a/p) puts("2");
		else if(q-b+r-c==p-a) puts("2");
		else if(q-b+p-a==r-c) puts("2");
		else if(p-a+r-c==q-b) puts("2");
		else if((!b||!c)) puts("3");
		else if((!a||!c)) puts("3");
		else if((!b||!a)) puts("3");
		else if(q%b==r%c) puts("3");
		else if(p%a==r%c) puts("3");
		else if(q%b==p%a) puts("3");
		else puts("3");

	}
	return 0;
}
