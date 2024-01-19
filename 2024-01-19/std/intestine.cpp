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
constexpr int Max=510;
constexpr ll mod=998244353;
inline ll qpow(ll x,ll y=mod-2)
{
	ll ans=1;
	for(;y;(x*=x)%=mod,y>>=1)
		if(y&1)
			(ans*=x)%=mod;
	return ans;
}
inline void mod_add(ll &x,const ll &y)
{
	x+=y;
	if(x>=mod)
		x-=mod;
}
int n,fa[Max],deg[Max],siz[Max],cnt;
ll f[Max][Max],g[Max][Max],val[Max][Max],fac[Max],inv_fac[Max];
inline void add(const int &x)
{
	for(int i=cnt;i;--i)
		for(int j=x;j<=n;++j)
			mod_add(g[i][j],g[i-1][j-x]);
}
inline void del(const int &x)
{
	for(int i=1;i<=cnt;++i)
		for(int j=x;j<=n;++j)
			mod_add(g[i][j],mod-g[i-1][j-x]);
}
vector<int>e[Max];
signed main()
{
	freopen("intestine.in","r",stdin),freopen("intestine.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n;
	for(int i=2;i<=n;++i)
		cin>>fa[i],e[fa[i]].push_back(i),++deg[fa[i]];
	fac[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=fac[i-1]*i%mod;
	inv_fac[n]=qpow(fac[n]);
	for(int i=n;i;--i)
		inv_fac[i-1]=inv_fac[i]*i%mod;
	for(int i=1;i<=n;++i)
		siz[i]=1;
	for(int i=n;i;--i)
		siz[fa[i]]+=siz[i];
	f[1][1]=1;
	for(int i=1;i<=n;++i)
		(f[1][1]*=fac[deg[i]])%=mod;
	for(int i=1;i<=n;++i)
		for(int j=0;j<i;++j)
			mod_add(val[i][j],inv_fac[i]*fac[j]%mod*fac[i-j-1]%mod);
	for(int u=1;u<=n;++u)
	{
		if(!deg[u])
			continue;
		cnt=deg[u]-1;
		memset(g,0,sizeof(g));
		for(int i=0;i<=n;++i)
			g[0][i]=f[u][i];
		for(auto v:e[u])
			add(siz[v]);
		for(auto v:e[u])
		{
			del(siz[v]);
			for(int k=0;k<=cnt;++k)
				for(int i=1;i<=n;++i)
					mod_add(f[v][i],g[k][i-1]*val[cnt+1][k]%mod);
			add(siz[v]);
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cout<<f[i][j]<<" \n"[j==n];
	return 0;
}