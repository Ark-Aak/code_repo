#include<bits/stdc++.h>
#define mod 1000000007
#define int long long
#define re register
#define rep(i,a,b) for(re int i(a);i<=(b);++i)
#define req(i,a,b) for(re int i(a);i>=(b);--i)
#define siz 191
using namespace std;
template<typename T> inline T read(T &num)
{
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch)) f|=ch=='-',ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=f?-x:x;
}
template<typename T> inline void write(T x)
{
	(x<0)?(putchar('-'),x=-x):0;
	(x>9)?(write(x/10),0):0;
	putchar(x%10+48);
}
inline void exitprogram()
{
	cerr<<"Total used time: "<<clock()<<" ms."<<endl;
	exit(0);
}
int n,m,deg[2000001],x,y,ans,cnt[2000001];
vector<int> gr;
signed main()
{
	freopen("gen.in","r",stdin);
	freopen("gen.out","w",stdout);
	read(n);read(m);
	rep(i,1,m) read(x),read(y),++deg[x],++deg[y];
	if(n<=2e4)
	{
		rep(i,1,n)rep(j,i,n) (ans+=(deg[i]^deg[j])*(deg[i]|deg[j])*(deg[i]&deg[j]))%=mod;
		write(ans);
		exitprogram();
	}
	rep(i,1,n)
	{
		rep(j,0,siz) (ans+=((deg[i]^j)*(deg[i]&j)*(deg[i]|j))*cnt[j])%=mod;
		for(re int j:gr) (ans+=(deg[i]^j)*(deg[i]&j)*(deg[i]|j))%=mod;
		if(deg[i]>siz) gr.emplace_back(deg[i]);
		++cnt[deg[i]];
	}
	write(ans);
	exitprogram();
	return 0;
}
