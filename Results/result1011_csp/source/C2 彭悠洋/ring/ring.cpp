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
const int N = 25;
int n,mod,a[N],tmp[N],id[N],ans;
bool vis[N];
int getl(int x) {return x==1?n:x-1;}
int getr(int x) {return x==n?1:x+1;}
bool get()
{
	for(int i = 1;i<=n;i++)
		id[a[i]] = i,tmp[i] = a[i];
	for(int i = 1;i<=n;i++)
	{
		int k = id[i],x = getl(k),y = getr(k);
		if(min(tmp[x],tmp[y])<i&&i<max(tmp[x],tmp[y])) return 1;
		swap(id[tmp[x]],id[tmp[y]]);
		swap(tmp[x],tmp[y]);
	}
	return 0;
}
void dfs(int x)
{
	if(x>n) return ans+=get(),void();
	for(int i = 1;i<=n;i++)
		if(!vis[i])
			a[x] = i,vis[i] = 1,dfs(x+1),vis[i] = 0;
}
signed main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	read(n),read(mod);
	if(n&1)
	{
		int ans = 1;
		for(int i = 1;i<=n;i++)
			ans = ans*i%mod;
		write(ans);
		return 0;
	}
	dfs(1);
	write(ans%mod);
	return 0;
}

