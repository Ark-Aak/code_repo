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
const int N = 5e5+5,mod = 1e9+7;
int n,b[N],ans,vis[N];
int get()
{
	int res = 0;
	while(vis[res]) res++;
	return res;
}
void dfs(int x)
{
	if(x>n) return (ans+=get())%=mod,void();
	for(int i = 0;i<=b[x];i++)
		vis[i]++,dfs(x+1),vis[i]--;
}
signed main()
{
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	read(n);
	for(int i = 1;i<=n;i++)
		read(b[i]);
	dfs(1);
	write(ans);
	return 0;
}

