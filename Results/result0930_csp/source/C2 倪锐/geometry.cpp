#include<bits/stdc++.h>
#define re register
#define rep(i,a,b) for(re int i(a);i<=(b);++i)
#define req(i,a,b) for(re int i(a);i>=(b);--i)
#define int long long
using namespace std;
template<typename T> inline T read(T &num)
{
	re T x=0,f=0; re char ch=getchar();
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
int l,L;
signed main()
{
	freopen("geometry.in","r",stdin);
	freopen("geometry.out","w",stdout); 
	read(L);read(l);
	if(L%l==0) write((L/l-1)*l*3);
	else if(L%(L-l)==0)write((L/(L-l)-1)*(L-l)*3);
	else write((L-1)*3);
	return 0;
}
