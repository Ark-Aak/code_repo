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
const int N = 5e4+5,M = 55;
int n,m,b[N],dis[N],a[M][M],pre[N][M],nxt[N][M];
char ch[M][M];
bool vis[N];
signed main()
{
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
		cin>>b[i];
	for(int i = 1;i<=m;i++)
		for(int j = 1;j<=m;j++)
			cin>>ch[i][j],a[i][j] = (ch[i][j]=='1');
	for(int j = 1;j<=m;j++)
		for(int i = 1,now = 0;i<=n;i++)
		{
			if(b[i]==j) now = i;
			pre[i][j] = now;
		}
	for(int j = 1;j<=m;j++)
		for(int i = n,now = 0;i;i--)
		{
			if(b[i]==j) now = i;
			nxt[i][j] = now;
		}
	priority_queue<pair<int,int> > q;
	q.push({0,1});
	memset(dis,63,sizeof dis);
	dis[1] = 0;
	while(!q.empty())
	{
		int u = q.top().second;q.pop();
//		cout<<u<<'\n';
		if(u==n) return cout<<dis[n],0;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 1;i<=m;i++)
		{
			int v = pre[u][i];
			if(dis[v]>dis[u]+abs(i-v)&&a[b[u]][i]&&v!=0)
				dis[v] = dis[u]+abs(v-u),q.push({-dis[v],v});
			v = nxt[u][i];
			if(dis[v]>dis[u]+abs(i-v)&&a[b[u]][i]&&v!=0)
				dis[v] = dis[u]+abs(v-u),q.push({-dis[v],v});
		}
	}
	if(dis[n]==dis[0]) dis[n] = -1;
	cout<<dis[n];	
	return 0;
}
//O(n*k + n log n)
