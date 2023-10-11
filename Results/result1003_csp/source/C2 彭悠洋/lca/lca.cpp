#include <bits/stdc++.h>
#define int long long
using namespace std;

template<typename T> void read(T &x)
{
	x = 0;
	T f = 1;char ch = getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		{
			f = -1,ch = getchar();
			break;
		}
		ch = getchar();
	}
	while(ch>='0'&&ch<='9')
		x = (x<<3)+(x<<1)+ch-48,ch = getchar();
	x*=f;
}
template<typename T> T read()
{
	T x;read(x);return x;
}
template<typename T> void write(T x)
{
    if(x<0) x = -x,putchar('-');
    if(x<=9) return putchar(x+48),void();
    write(x/10);
    putchar(x%10+48);
}
template<typename T> void writen(T x)
{
    write(x);
    puts("");
}
const int N = 5e5+5; 
int n,sz[N],f[N];
vector<int> g[N];
void dfs1(int u,int fa)
{
	sz[u] = 1;
	int tmp = 0;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs1(v,u);
		f[1]+=sz[v]*sz[u]*u;
		tmp+=sz[v]*sz[u];
		sz[u]+=sz[v];
	}
}
void dfs2(int u,int fa)
{
	if(u!=1) f[u] = f[fa]-(sz[1]-sz[u])*sz[u]*fa+sz[u]*(sz[1]-sz[u])*u;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs2(v,u);
	}
}
signed main()
{
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	read(n);
	for(int i = 1,u,v;i<n;i++)
		read(u),read(v),g[u].push_back(v),g[v].push_back(u);
	dfs1(1,0),dfs2(1,0);
	for(int i = 1;i<=n;i++)
		write(f[i]*2ll+(n+1)*n/2),putchar(32);
	return 0;
}

