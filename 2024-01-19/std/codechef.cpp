#include<stdio.h>
#include<bits/stdc++.h>
#define fir first
#define sec second
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef __int128 int128;
typedef __uint128_t uint128;
typedef pair<int,int> pii;
template<typename type>
inline void chmin(type &x,const type &y)
{
	if(y<x)
		x=y;
}
template<typename type>
inline void chmax(type &x,const type &y)
{
	if(x<y)
		x=y;
}
constexpr int Max=1010,Size=260;
int f[3][Size][Size],g[3][Size][Size];
int n,a[Max][3];
void solve()
{
	cin>>n;
	const int lim=min(n,250);
	for(int i=0;i<n;++i)
		for(int j=0;j<3;++j)
			cin>>a[i][j];
	for(int x=0;x<n;++x)
	{
		memcpy(g,f,sizeof(g));
		memset(f,0,sizeof(f));
		for(int y=max(0,x-lim);y<=x;++y)
			for(int z=max(0,x-lim);z<=x;++z)
			{
				int u=x-y?x-y+1:0,v=x-z?x-z+1:0;
				chmax(f[0][u][v],g[0][x-y][x-z]+a[x][0]);
				chmax(f[1][1][v],g[0][x-y][x-z]+a[x][1]);
				chmax(f[2][1][u],g[0][x-y][x-z]+a[x][2]);
				chmax(f[0][1][v],g[1][x-y][x-z]+a[x][0]);
				chmax(f[1][u][v],g[1][x-y][x-z]+a[x][1]);
				chmax(f[2][u][1],g[1][x-y][x-z]+a[x][2]);
				chmax(f[0][v][1],g[2][x-y][x-z]+a[x][0]);
				chmax(f[1][u][1],g[2][x-y][x-z]+a[x][1]);
				chmax(f[2][u][v],g[2][x-y][x-z]+a[x][2]);
			}
		for(int i=0;i<3;++i)
			for(int y=0;y<=lim;++y)
				for(int z=0;z<=lim;++z)
					f[i][y][z]-=y+z;
	}
	int ans=0;
	for(int x=0;x<3;++x)
		for(int y=0;y<=lim;++y)
			for(int z=0;z<=lim;++z)
				chmax(ans,f[x][y][z]);
	cout<<ans<<"\n";
	memset(f,0,sizeof(f));
}
signed main()
{
	freopen("codechef.in","r",stdin),freopen("codechef.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
