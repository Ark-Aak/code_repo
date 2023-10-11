#include <bits/stdc++.h>
#define int long long
using namespace std;

template<typename T> inline void read(T &x)
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
template<typename T> inline T read()
{
	T x;read(x);return x;
}
template<typename T> inline void write(T x)
{
    if(x<0) x = -x,putchar('-');
    if(x<=9) return putchar(x+48),void();
    write(x/10);
    putchar(x%10+48);
}
template<typename T> inline void writen(T x)
{
    write(x);
    puts("");
}
const int N = 1e5+5;
int n,q,head[N<<1],to[N<<2],nxt[N<<2],g[N<<2],cnt;
void add(int x,int y,int z)
{
	nxt[++cnt] = head[x];
	head[x] = cnt;
	to[cnt] = y;
	g[cnt] = z;
}
int dis[N];
bool vis[N];
void dij(int s)
{
	priority_queue<pair<int,int> > q;
	memset(dis,63,sizeof dis);
	memset(vis,0,sizeof vis);
	q.push({0,s}),dis[s] = 0;
	while(!q.empty())
	{
		int u = q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = head[u];i;i = nxt[i])
		{
			int v = to[i];
			if(dis[v]>dis[u]+g[i])
				dis[v] = dis[u]+g[i],q.push({-dis[v],v});
		}
	}
}
signed main()
{
	freopen("double.in","r",stdin);
	freopen("double.out","w",stdout);
	read(n);
	for(int i = 1,w;i<=n;i++)
		read(w),add(2*i-1,2*i,w),add(2*i,2*i-1,w);
	for(int i = 1,u,v,w1,w2;i<n;i++)
		read(u),read(v),read(w1),read(w2),add(2*u-1,2*v-1,w1),add(2*v-1,2*u-1,w1),add(2*u,2*v,w2),add(2*v,2*u,w2);
	read(q);
	while(q--)
	{
		int s,t;
		read(s),read(t),dij(s);
		writen(dis[t]);
	}
	return 0;
}

