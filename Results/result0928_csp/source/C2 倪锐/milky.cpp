#include<bits/stdc++.h>
#define re register
 #define int unsigned
#define rep(i,a,b) for(re signed i(a);i<=signed(b);++i)
#define req(i,a,b) for(re signed i(a);i>=signed(b);--i)
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
string s;
int q,l,r;
vector<int> ton[201];
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("milky.in","r",stdin);
	freopen("milky.out","w",stdout);
#endif
	cin>>s;
	s=' '+s;
	read(q);
	rep(_,1,q) 
	{
		read(l),read(r);
		rep(i,1,200) ton[i].clear(),vector<int>().swap(ton[i]);
		rep(i,l,r) ton[s[i]].emplace_back(i);
		int res=0;
		rep(M,0,ton['m'].size()-1)
			rep(I,0,ton['i'].size()-1)
				rep(L,0,ton['l'].size()-1)
					rep(K,0,ton['k'].size()-1)
						rep(Y,0,ton['y'].size()-1)
						{
							if
							(!( ton['m'][M]<ton['i'][I]&&
								ton['i'][I]<ton['l'][L]&&
								ton['l'][L]<ton['k'][K]&&
								ton['k'][K]<ton['y'][Y])
							) continue;
							++res;
							// cout<<M<<" "<<I<<" "<<L<<" "<<K<<" "<<Y<<endl;
						}
		write(res);puts("");
	}
	return 0;
}
