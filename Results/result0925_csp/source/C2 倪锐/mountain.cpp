#include<bits/stdc++.h>
// #define int long long
#define re register
#define rep(i,a,b) for(re int i(a);i<=(b);++i)
#define req(i,a,b) for(re int i(a);i>=(b);--i)
using namespace std;
template<typename T> inline T read(T &num)
{
	re int x(0),f(0);char ch(getchar());
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	while(ch>=48&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=f?-x:x;
}
template<typename T> inline void write(T x)
{
	(x<0)?(putchar('-'),x=-x):0;
	(x>9)?(write(x/10),0):0;
	putchar((x%10)^48);
}
int n,a[1000001],ans[1000001],ans1[1000001];
signed main()
{
	freopen("mountain.in","r",stdin);
	freopen("mountain.out","w",stdout);
	read(n);
	rep(i,1,n)read(a[i]);
	rep(i,2,n) if(a[i]>a[i-1])ans[i]=ans[i-1]+1;
	req(i,n-1,1)if(a[i]>a[i+1])ans1[i]=ans1[i+1]+1;
	rep(i,1,n) write(ans1[i]+ans[i]),puts("");
	return 0;
}
