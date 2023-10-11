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
const int N = 1e3+5;
int T,a[N],cnt,bit[N],tot,to[N],dis[N][N],ans[N][N];
bool vis[N];
bool ok(int x)
{
	while(x) if(x%10==0) return 0; else x/=10;
	return 1;
}
vector<int> g[N];
void get(int x)
{
	int tmp = x;
	tot = 0;
	while(x) bit[++tot] = x%10,x/=10;
	bit[4] = bit[1],bit[5] = bit[2],bit[6] = bit[3];
	tot = 0;
	for(int i = 1;i<=6;i++)
		for(int j = i+1;j<=6;j++)
			for(int k = j+1;k<=6;k++)
				to[++tot] = bit[i]*100+bit[j]*10+bit[k],
				to[++tot] = bit[i]*100+bit[k]*10+bit[j],
				to[++tot] = bit[j]*100+bit[i]*10+bit[k],
				to[++tot] = bit[j]*100+bit[k]*10+bit[i],
				to[++tot] = bit[k]*100+bit[i]*10+bit[j],
				to[++tot] = bit[k]*100+bit[j]*10+bit[i];
	sort(to+1,to+tot+1),tot = unique(to+1,to+tot+1)-to-1;
	for(int i = 1;i<=tot;i++)
		g[tmp].push_back(to[i]);
}
void bfs(int s)
{
	queue<int> q;
	q.push(s);dis[s][s] = 0;
	while(!q.empty())
	{
		int u = q.front();q.pop();
		for(auto v:g[u])
			if(dis[s][v]==-1)
				dis[s][v] = dis[s][u]+1,q.push(v);
	}
	for(int i = 1;i<=cnt;i++)
		if(dis[s][a[i]]!=-1) ans[s][dis[s][a[i]]]++;
}
signed main()
{
	freopen("device.in","r",stdin);
	freopen("device.out","w",stdout);
	for(int i = 111;i<=999;i++)
		if(ok(i))
			a[++cnt] = i;
	for(int i = 1;i<=cnt;i++)
		get(a[i]);
	memset(dis,-1,sizeof dis);
	for(int i = 1;i<=cnt;i++)
		bfs(a[i]);
	for(int i = 1;i<=cnt;i++)
		for(int j = 1;j<=1000;j++)
			ans[a[i]][j]+=ans[a[i]][j-1];
	read(T);
	while(T--)
	{
		int n,k;
		read(k),read(n);
		n = min(n,1000);
		writen(ans[k][n]);
	}
	return 0;
}

