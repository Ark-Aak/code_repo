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
const int N = 5e6+5;
int n,m,c,a[N];
int head[N],to[N],nxt[N],g[N],cnt;
void add(int x,int y,int w)
{
	nxt[++cnt] = head[x];
	head[x] = cnt;
	to[cnt] = y;
	g[cnt] = w;
}
int dis[N],ans;
bool vis[N];
void dij()
{
	priority_queue<pair<int,int> > q;
	q.push({0,1});
	memset(dis,-1,sizeof dis);
	dis[1] = 0;
	while(!q.empty())
	{
		int u = q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u];i;i = nxt[i])
		{
			int v = to[i];
			if(dis[v]<dis[u]+g[i])
				dis[v] = dis[u]+g[i],q.push({dis[v],v});
		}
	}
}
signed main()
{
	freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
	read(n),read(m),read(c);
	for(int i = 1;i<=n;i++)
		read(a[i]);
	for(int i = 1,u,v;i<=m;i++)
	{
		read(u),read(v);
		for(int j = 0;j<1500;j++)
			add(n*j+u,n*(j+1)+v,a[v]);
	}
	dij();
	for(int i = 1;i<1500;i++)
		ans = max(ans,dis[i*n+1]-c*i*i);
	write(ans);
	return 0;
}

