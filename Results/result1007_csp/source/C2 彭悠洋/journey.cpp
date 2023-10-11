#include <bits/stdc++.h>
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
const int N = 1e3+5,M = 1e6+5;
int n,m,q,head[M],to[M],nxt[M],cnt = 1,dis[N][N],g[N][N];
bool vis[N];
inline void add(int x,int y)
{
	nxt[++cnt] = head[x];
	head[x] = cnt;
	to[cnt] = y;
}
inline int bfs(int s,int t,int st)
{
	queue<int> q;
	memset(dis[s],-1,sizeof dis[s]);
	q.push(s),dis[s][s] = st;
	while(!q.empty())
	{
		int u = q.front();q.pop();
//		if(u==t) return dis[u];
		for(int i = head[u];i;i = nxt[i])
		{
			int v = to[i];
			if(dis[s][u]<=i/2&&dis[s][v]==-1) dis[s][v] = dis[s][u]+1,q.push(v);
		}
	}
	if(dis[s][t]==-1) return 2e9;
	return dis[s][t];
}
signed main()
{
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	read(n),read(m),read(q);
	for(int i = 1,u,v;i<=m;i++)
		read(u),read(v),add(u,v),add(v,u),g[u][v] = g[v][u] = i;
	if((q<=1000&&n<=1000)||n<=100)
	{
		while(q--)
		{
			int l,r,s,t;
			read(l),read(r),read(s),read(t);
			if(bfs(s,t,l-1)<=r) puts("Yes");
			else puts("No");
		}
		return 0;
	}
	while(q--)
	{
		int l,r,s,t;
		read(l),read(r),read(s),read(t);
		if(l==r)
		{
			if(g[s][t]>=l-1&&g[s][t]!=0) puts("Yes");
			else puts("No");
		}
		else
		{
			if(vis[s]==0) bfs(s,0,0),vis[s] = 1;
			if(dis[s][t]<=r&&dis[s][t]!=-1) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}

