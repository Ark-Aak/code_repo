#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define int long long
#define re register
#define rep(i,a,b) for(re int i(a);i<=(b);++i)
#define req(i,a,b) for(re int i(a);i>=(b);--i)
template<typename t> inline t read(t &num)
{
	re int x=0,f=0;
	re char ch=getchar();
	while(ch<48||ch>57) f|=ch=='-',ch=getchar();
	while(48<=ch&&ch<=57) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=f?-x:x;
}
template<typename t> inline void write(t x)
{
	(x<0)?(putchar('-'),x=-x):0;
	(x>9)?(write(x/10),0):0;
	putchar((x%10)^48);
}
template<typename t> inline void writeln(t x)
{
	write<t>(x);
	puts("");
}
int T,pw[10001],hs[10001],n,ans;
string s,A1,A2,B1,B2,t;
bool chk(string a1,string a2,string b1,string b2)
{
	int flga=1,flgb=1;
	rep(i,0,a1.size()-1) if(a1[i]!=a2[i]&&a1[i]!='?'&&a2[i]!='?')
	{
		flga=0;
		break;
	}
	rep(i,0,b1.size()-1) if(b1[i]!=b2[i]&&b1[i]!='?'&&b2[i]!='?')
	{
		flgb=0;
		break;
	}
	return flga&&flgb;
}
signed main()
{
freopen("excellent.in","r",stdin);
freopen("excellent.out","w",stdout);
	read(T);
	while(T--)
	{
		cin>>s;
		if(s.size()<=100)
		{
			n=s.size();
			s=" "+s;
			ans=0;
			rep(i,1,n)rep(j,i+3,n)
			{
				// cout<<i<<' '<<j<<endl;
				rep(k,1,(j-i-1)>>1)
				{
					A1=s.substr(i,k),
					A2=s.substr(i+k,k),
					B1=s.substr(i+k+k,(j-i+1-k-k)>>1),
					B2=s.substr(i+k+k+B1.size(),(j-i+1-k-k)>>1);
					// cout<<A1<<" "<<A2<<' '<<B1<<" "<<B2<<endl;
					if(chk(A1,A2,B1,B2)) ++ans;
				}
			}
			writeln(ans);
			continue;
		}
		if(s.find("?")==-1)
		{
			writeln(0);
		}
		else writeln(s.size()/2-1);
	}
	return 0;
}
