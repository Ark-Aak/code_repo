#include<bits/stdc++.h>
#define re register
#define mod 147744151
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
template<typename T> inline void writemod(T x)
{
	write((x+mod+mod)%mod);
}
int n,k;
signed main()
{
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout); 
	read(n),read(k);
	if(k==1) writemod(n>>1ll);
	else if(k==2) writemod((int)sqrt(n<<1));
	else if((int)ceil(log(n)/log(2))<=k) writemod((int)ceil(log(n)/log(2)));
	else writemod((int)ceil(log(n)/log(2)));
	return 0;
}
