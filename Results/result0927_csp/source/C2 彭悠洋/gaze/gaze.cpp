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
const int N = 2e5+5;
int n,m,a[N],ask[N],id[N],ans[N],b[N];
void solve1()
{
	while(m--)
	{
		int op,x,y;
		read(op),read(x);
		if(op==1)
		{
			int ans = 0;
			for(int i = 1;i<=n;i++)
				if(a[i]>=x&&a[i-1]<x)
					ans++;
			writen(ans);
		}
		else read(a[x]);
	}
}
set<int> s,tmp;
bool cmp(int x,int y)
{
	return ask[x]<ask[y];
}
vector<int> v[N];
bool vis[N];
void solve2()
{
	for(int i = 1,x;i<=m;i++)
		read(x),read(ask[i]),id[i] = i,b[i] = ask[i];
	sort(id+1,id+m+1,cmp);
	sort(b+1,b+m+1);
	for(int i = 1;i<=n;i++)
		s.insert(i);
	for(int i = 1;i<=n;i++)
		v[upper_bound(b+1,b+m+1,a[i])-b].push_back(i);
	ans[0] = 1;
	vis[0] = vis[n+1] = 1;
	for(int i = 1;i<=m;i++)
	{
		ans[id[i]] = ans[id[i-1]];
//		cout<<i<<' '<<v[i].size()<<'\n';
		for(auto j:v[i])
		{
//			cout<<j<<' ';
			s.erase(j);
			vis[j] = 1;
			if(vis[j+1]==0&&vis[j-1]==0) ans[id[i]]++;
			else if(vis[j+1]&&vis[j-1]) ans[id[i]]--;
		}
//		cout<<'\n';
	}
	for(int i = 1;i<=m;i++)
		writen(ans[i]);
}
signed main()
{
	freopen("gaze.in","r",stdin);
	freopen("gaze.out","w",stdout);
	read(n),read(m);
	for(int i = 1;i<=n;i++)
		read(a[i]);
	if(n<=2000&&m<=2000) return solve1(),0;
	solve2();
	return 0;
}

