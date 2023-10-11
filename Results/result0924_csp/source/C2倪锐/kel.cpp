#include<bits/stdc++.h>
// #define int long long
#define re register
#define rep(i,a,b) for(re int i(a);i<=(b);++i)
#define req(i,a,b) for(re int i(a);i>=(b);--i)
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
int n,l,r;
vector<int> ans;
signed main()
{
	freopen("kel.in","r",stdin);
	freopen("kel.out","w",stdout);
	read(n);read(l);read(r);
	int cnt=l;
	rep(i,1,n>>1)ans.emplace_back(cnt++);
	ans.emplace_back(cnt);
	rep(i,1,n>>1)ans.emplace_back(--cnt);
	for(re int i:ans) if(i<l||i>r)puts("Shinomiya"),exitprogram();
	for(re int i:ans) write(i),puts("");
	exitprogram();
}
