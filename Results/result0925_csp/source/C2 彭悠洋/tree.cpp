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
const int N = 4e5+5,mod = 1e9+7;
int n,f[N],k,ans,siz[N];
bool vis[N];
vector<int> g[N];
void dfs(int u,int fa)
{
	f[u] = fa;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
	}
}
int spow(int x,int y)
{
	x%=mod;
	if(y==1) return x;
	return x*x%mod;
}
int get(int n)
{
	int res = 0;
	for(int len = 1;len<=n;len++)
		(res+=len*len%mod*(n-len+1)%mod)%=mod;
	return res;
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	read(n),read(k);
	for(int i = 1,u,v;i<n;i++)
		read(u),read(v),g[u].push_back(v),g[v].push_back(u);
	if(n<=5000)
	{
		dfs(1,0);
		for(int l = 1;l<=n;l++)
		{
			for(int i = 1;i<=n;i++)
				siz[i] = vis[i] = 0;
			int now = 0;
			for(int r = l;r<=n;r++)
			{
				if((siz[r]==0)&&(f[r]>r||f[r]<l)) now++;
				if((f[r]<=r&&f[r]>=l)) now-=siz[r];
				vis[r] = 1,siz[f[r]]++;
				(ans+=spow(now,k))%=mod;
			}
		}
		write(ans);
		return 0;
	}
	int fd = 0;
	for(int i = 1;i<=n;i++)
		if(g[i].size()==n-1)
		{
			fd = i;
			break;
		}
	write((fd*(n-fd+1)%mod+get(fd-1)+get(n-fd))%mod);
	return 0;
}

