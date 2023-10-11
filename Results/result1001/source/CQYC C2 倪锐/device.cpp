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
int t,k,n;
struct binocalc
{
	int n,fac[100001],mod=998244353;
	inline void reset(){n=0;memset(fac,0,sizeof fac);fac[0]=1;}
	inline void resize(int N){n=N;rep(i,1,n)fac[i]=fac[i-1]*i;}
	inline void resetsize(int N){reset();resize(N);}
	inline int qpow(int x,int y){if(!y)return 1;if(y==1)return x;int res=qpow(x,y>>1);return (y&1)?res*res%mod*x%mod:res*res%mod;}
	inline int inv(int x){return qpow(x,mod-2)%mod;}
	inline int calc_c(int x,int y){return fac[x]%mod*inv(fac[y])%mod*inv(fac[x-y])%mod;}
	inline int calc_a(int x,int y){return calc_c(x,y)*fac[y]%mod;}
}c;
int vis[11];
signed main()
{
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	read(t);
	if(!t) return 0;
	while(t--)
	{
		read(k),read(n);
		if(!n) puts("1");
		else if(n==1)
		{
			int res=k*13*11*7;
			memset(vis,0,sizeof vis);
			while(res) ++vis[res%10],res/=10;
			res=0;
			rep(i,1,9) rep(j,1,9) rep(k,1,9)
			{
				if(!vis[i]||!vis[j]||!vis[k]) continue;
				else if(i!=j&&i!=k&&j!=k) ++res;
				else if(i==j&&i!=k&&vis[i]>=2) ++res;
				else if(i==k&&i!=j&&vis[i]>=2) ++res;
				else if(j==k&&i!=j&&vis[j]>=2) ++res;
				else if(i==j&&j==k&&vis[i]>=3) ++res;
			}
			writeln(res);
		}
		else if(k/100==k%10&&k%10==k/10%10) puts("1");
		else if(k/100!=k%10&&k%10!=k/10%10&&k/10%10!=k/100) puts("27");
		else puts("8");
	}
	return 0;
}
