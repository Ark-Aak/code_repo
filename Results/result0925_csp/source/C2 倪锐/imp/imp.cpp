#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast") 
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
#define int long long
#define re register
#define rep(i,a,b) for(re int i(a);i<=(b);++i)
#define req(i,a,b) for(re int i(a);i>=(b);--i)
using namespace std;
// using namespace __gnu_pbds;
template<typename T> inline T read(T &num)
{
	re int x(0),f(0);re char ch(getchar());
	while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return num=(f?-x:x);
}
template<typename T> inline void write(T x)
{
	(x<0)?(putchar('-'),x=-x):0;
	(x>9)?(write(x/10),0):0;
	putchar((x%10)^48);
}
int n,ans=-2147483647;
struct point
{
	int x,y,w;
}a[250001];
set<int> id;
int rc[500001],cnt;
map<int,int> sum;
pair<int,int> prvi={0,0};
unordered_map<int,int> val,wz;
inline int get_value(int fr,int to)
{
	return val[to]-val[fr]+wz[fr];
}
// The variables the random algorithm needs is defined as follows
int chx,chy;
mt19937 rnd(11451419);
// end
signed main()
{
	freopen("imp.in","r",stdin);
	freopen("imp.out","w",stdout);
	read(n);
	rep(i,1,n)read(a[i].x),read(a[i].y),read(a[i].w),
			  sum[max(a[i].x,a[i].y)]+=a[i].w,
			  ((a[i].x==a[i].y)?(wz[a[i].x]+=a[i].w,0):0);
	for(auto &i:sum) val[i.first]+=i.second+val[prvi.first],prvi=i,id.insert(i.first);
	// cout<<val[0]<<" "<<val[3]<<'\n';
	// for(auto i:val)cout<<i.first<<" "<<i.second<<'\n';
	for(re int i:id)rc[++cnt]=i;
	if(cnt>50000) goto RandomAlgorithm;
	rep(i,1,cnt)rep(j,i,cnt) ans=max(ans,get_value(i,j)-j+i);
	write(ans);
	return 0;
// Random algorithm is as follows.
RandomAlgorithm:
	while(clock()*1.0/CLOCKS_PER_SEC<.95)
	{
		chx=rnd()%cnt+1;
		chy=rnd()%cnt+1;
		if(chy<chx) chx^=chy^=chx^=chy;
		ans=max(ans,get_value(chx,chy)-chy+chx);
	}
	write(ans);
	return 0;
}
