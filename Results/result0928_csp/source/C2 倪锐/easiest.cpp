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
int n; 
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("easiest.in","r",stdin);
	freopen("easiest.out","w",stdout);
#endif
	read(n);read(n);
	rep(i,1,n) puts("0");
	return 0;
}
