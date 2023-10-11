#include <bits/stdc++.h>
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
const int N = 120000+5;
int T,n,m,f[N][20],dep[N],p[N],q[N],s[N],t[N],tu[N],tv[N],flag;
vector<int> g[N];
void dfs(int u,int fa)
{
	f[u][0] = fa,dep[u] = dep[fa]+1;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i = 17;i>=0;i--)
		if(dep[f[x][i]]>=dep[y])
			x = f[x][i];
	if(x==y) return x;
	for(int i = 17;i>=0;i--)
		if(f[x][i]!=f[y][i])
			x = f[x][i],y = f[y][i];
	return f[x][0];
}
bool ok(int x,int y)
{
	return lca(x,y)==y||lca(x,y)==x;
}
bool solve()
{
	for(int x = 1;x<=m;x++)
		for(int y = 1;y<=m;y++)
			if(x!=y)
			{
				if(lca(p[x],q[x])==q[x])
				{
					if(lca(p[y],q[y])!=q[y])
					{
						int q_y = lca(p[y],q[y]); 
						if(lca(p[x],p[y])==p[x]&&lca(q[x],q_y)==q_y) return 0;
					}
				}
				else if((lca(p[x],p[y])==p[x]&&lca(q[x],q[y])==q[x])||(lca(p[x],q[y])==p[x]&&lca(q[x],p[y])==q[x]))
					return 0;
				if((p[x]==s[x]&&p[y]==t[y])||(p[x]==t[x]&&p[y]==s[y]))
				{
					if(lca(p[x],q[x])==q[x]&&lca(p[y],q[y])==q[y])
					{
						if(dep[q[x]]<dep[q[y]]&&lca(lca(p[x],p[y]),q[y])==q[y]&&ok(s[x],t[y])&&ok(t[x],s[y]))
							return 0;
					}
				}
				if((p[x]==s[x]&&p[y]==s[y])||(p[x]==t[x]&&p[y]==t[y]))
				{
					if(lca(p[x],p[y])==lca(p[x],q[x])&&lca(p[x],q[x])==lca(p[y],q[y])&&ok(s[x],t[y])&&ok(t[x],s[y]))
						return 0;
				}
				if(lca(p[x],q[x])==q[x])
				{
					if(q[x]==s[x]&&lca(s[y],s[x])==s[x]&&lca(lca(s[y],s[x]),t[y])==lca(s[y],t[y])&&ok(s[x],s[y])&&ok(t[x],s[y])&&dep[s[x]]<=dep[s[y]])
						return 0;
					else if(q[x]==t[x]&&lca(t[y],t[x])==t[x]&&lca(lca(t[y],t[x]),s[y])==lca(s[y],t[y])&&dep[t[x]]<=dep[t[y]]&&ok(t[x],t[y])&&ok(s[x],t[y]))
						return 0;
				}
			}
	return 1;
}
signed main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	read(T);
	while(T--)
	{
		read(n);
		for(int i = 1,u,v;i<n;i++)
			read(u),read(v),g[u].push_back(v),g[v].push_back(u);
		dfs(1,0);
		for(int j = 1;j<=17;j++)
			for(int i = 1;i<=n;i++)
				f[i][j] = f[f[i][j-1]][j-1];
		read(m);
		for(int i = 1;i<=m;i++)
		{
			read(p[i]),read(q[i]);
			s[i] = p[i],t[i] = q[i];
			if(dep[p[i]]<dep[q[i]]) swap(p[i],q[i]);
		}
		if(solve()) puts("Yes");
		else puts("No");
		for(int i = 1;i<=n;i++)
		{
			dep[i] = 0;
			g[i].erase(g[i].begin(),g[i].end());
			for(int j = 0;j<=17;j++)
				f[i][j] = 0;
		}
	}
	return 0;
}

