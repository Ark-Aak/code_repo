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
int T,p,n;
namespace subtask3
{
	bitset<30000051> isprime,vis;
	int prime[3000001],pcnt;
	inline void sieve(int n)
	{
		isprime.set(1);
		rep(i,2,n)
		{
			if(!isprime.test(i)&&!vis.test(i)) vis.set(i),prime[++pcnt]=i; 
			for(int j=i+i;j<=n;j+=i) if(!vis.test(j)) vis.set(j),isprime.set(j,0);
		}
	}
	inline int main()
	{
		sieve(30000050);
		while(T--)
		{
			read(n);
			writeln(*lower_bound(prime+1,prime+pcnt+1,n));
		}
		return 0;
	}
}
namespace subtask2
{
	bitset<30000051> isprime,vis;
	int prime[30000001],pcnt;
	inline void sieve(int n)
	{
		isprime.set(1);
		rep(i,2,n)
		{
			if(!isprime.test(i)&&!vis.test(i)) vis.set(i),prime[++pcnt]=i; 
			if(i<=p)for(int j=i+i;j<=n;j+=i) if(!vis.test(j)) vis.set(j),isprime.set(j,0);
		}
	}
	inline int main()
	{
		sieve(30000050);
		while(T--)
		{
			read(n);
			writeln(*lower_bound(prime+1,prime+pcnt+1,n));
		}
		return 0;
	}
}

signed main()
{
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	read(T);read(p);
	if(p>1e7) subtask3::main();
	else subtask2::main();
	return 0;
}
