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
const int N = 1e3+5,mod = 1e9+7;
int T,n,m,a[N][N];
int dfs(int x,int y,int addx,int addy,int n,int m)
{
	if(x==1&&y==1||x==1&&y==m||x==n&&y==1||x==n&&y==m) return 0;
	int add = 0;
	if(x==1||x==n) add = 1,addx*=-1;
	if(y==1||y==m) add = 1,addy*=-1;
	return dfs(x+addx,y+addy,addx,addy,n,m)+add;
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
//	for(int i = 1;i<N;i++)
//		a[1][i] = a[i][1] = i-1;
	for(int i = 1;i<=11;i++)
		for(int j = 1;j<=11;j++)
			a[i][j] = dfs(2,2,1,1,i+1,j+1);
//	for(int i = 1;i<=5;i++)
//		for(int j = 1;j<=5;j++)
//			cout<<a[i][j]<<" \n"[j==5];
	for(int i = 1;i<=11;i++)
		for(int j = 1;j<=11;j++)
			(a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1])%=mod;
	read(T);
	while(T--)
	{
		read(n),read(m);
		writen(a[n][m]);
	}
	return 0;
}

