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
const int N = 2500+5;
int n,m,x[N],y[N],c[N],a[2*N],s[2*N][2*N],ans;
signed main()
{
	freopen("imp.in","r",stdin);
	freopen("imp.out","w",stdout);
	read(n);
	for(int i = 1;i<=n;i++)
		read(x[i]),read(y[i]),read(c[i]),a[++m] = x[i],a[++m] = y[i];
	sort(a+1,a+m+1);
	m = unique(a+1,a+m+1)-a-1;
	for(int i = 1;i<=n;i++)
		x[i] = lower_bound(a+1,a+m+1,x[i])-a,y[i] = lower_bound(a+1,a+m+1,y[i])-a,s[x[i]][y[i]] = c[i];
	for(int i = 1;i<=m;i++)
		for(int j = 1;j<=m;j++)
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	for(int i = 1;i<=m;i++)
		for(int j = i;j<=m;j++)
			ans = max(ans,s[j][j]-s[i-1][j]-s[j][i-1]+s[i-1][i-1]-(a[j]-a[i]));
	write(ans);
	return 0;
}

