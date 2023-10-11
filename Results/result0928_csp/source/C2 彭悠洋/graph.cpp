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
const int N = 1e5+5;
int n,a[N],b[N],f[N],tmp[2*N],cnt,m;
int find(int x)
{
	if(f[x]==x) return f[x];
	return f[x] = find(f[x]);
}
vector<int> v[N];
int p[N],mx;
signed main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	read(n);
	for(int i = 1;i<=n;i++)
		read(a[i]),read(b[i]),tmp[i] = a[i];
	if(n<=1000)
	{
		iota(f+1,f+n+1,1);
		for(int i = 1;i<n;i++)
			for(int j = i+1;j<=n;j++)
				if((a[i]<=a[j]&&b[i]<=b[j])||(a[i]>=a[j]&&b[i]>=b[j]))
					f[find(i)] = find(j);
		int ans = 0;
		for(int i = 1;i<=n;i++)
			if(f[i]==i)
				ans++;
		write(ans);
	}
//	sort(tmp+1,tmp+n+1),m = unique(tmp+1,tmp+n+1)-tmp-1;
//	for(int i = 1;i<=n;i++)
//		v[lower_bound(tmp+1,tmp+m+1,a[i])-tmp].push_back(b[i]);
//	for(int i = 1;i<=m;i++)
//	{
//		for(int j )
//	}
	return 0;
}

