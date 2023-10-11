#include<bits/stdc++.h>
#define re register
#define int long long
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
#define Mod 1000000007
#define Inv 500000004
namespace Std
{
	struct modint
	{
		int val,mod;
		int qpow(int x,int y)
		{
			if(y==1)return x;if(!y) return 1;
			int res=qpow(x,y>>1);
			return (y&1)?res*res%mod*x%mod:res*res%mod;
		}
		int inv(int x){return qpow(x,mod-2);}
		void modify(int x){val=(x%mod+mod)%mod;}
		void add(int x){(val+=x)%=mod;}
		void minus(int x){((val-=x%mod)+=mod)%=mod;}
		void multiply(int x){(val*=x)%=mod;}
		void divide(int x){(val*=inv(x))%=mod;}
		void reset(int x,int md){val=x%md,mod=md;}
	};
}
int n,m,q,x,y;
unordered_map<int,int> visln;
Std::modint sumln[2000001],sumcl[2000001];
Std::modint ans;
char opt;
vector<pair<int,int>> ln,cl;
inline int tval(int x,int y)
{
	return (x-1)*m+y;
}
signed main()
{	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	read(n);read(m);read(q);
	ans.reset(0,1000000007);
	rep(i,1,max(n,m)) sumln[i].reset(0,1000000007),sumcl[i].reset(0,1000000007);
	while(q--)
	{
		while(!isalpha(opt=getchar()));
		read(x);read(y);
		if(opt=='R') ln.emplace_back(x,y);
		else cl.emplace_back(x,y);
	}
	sort(ln.begin(),ln.end());
	sort(cl.begin(),cl.end());
	ans.modify((1+n*m%Mod)*n*m%Mod*Inv);
	rep(i,1,n) sumln[i].modify(((i-1)*m%Mod+1+i*m%Mod)*m%Mod*Inv);
	rep(i,1,m) sumcl[i].modify((i+(n-1)*m%Mod+i)*n%Mod*Inv%Mod);
	for(pair<int,int> i:ln)
	{
		ans.add(sumln[i.first].val*(i.second-1));
		sumln[i.first].multiply(i.second);
		if(visln[i.first]) (visln[i.first]*=i.second)%=Mod;
		else visln[i.first]=i.second%Mod;
	}
	for(pair<int,int> i:cl)
	{
		ans.add(sumcl[i.first].val*(i.second-1)%Mod);
		sumcl[i.first].multiply(i.second);
		for(pair<int,int> j:visln)
		{
			int tmp=tval(j.first,i.first)%Mod*(j.second-1)%Mod*(i.second-1)%Mod;
			ans.add(tmp);
			sumcl[i.first].add(tmp);
		}
	}
	writeln(ans.val);
	return 0; 
}
