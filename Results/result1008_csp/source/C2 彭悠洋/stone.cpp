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
const int N = 105,mod = 998244353;
int n,cnt,k,a[N],tmp[N];
int get()
{
	memcpy(tmp,a,sizeof tmp);
	while(1)
	{
		bool flag = 1;
		for(int i = 1;i<=n;i++)
			if(tmp[i]==i)
			{
				for(int j = 1;j<i;j++)
					tmp[j]+=1;
				tmp[i] = 0;
				flag = 0;
				break;
			}
		if(flag)
		{
			int res = 0;
			for(int i = 1;i<=n;i++)
				res+=tmp[i];
			return res;
		}
	}
}
int ans;
void dfs(int x)
{
	if(x>n) return (ans+=get())%=mod,void();
	for(int i = 0;i<=k;i++)
		a[x] = i,dfs(x+1);
}
signed main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	read(n),read(k);
	dfs(1);
	write(ans);
	return 0;
}

