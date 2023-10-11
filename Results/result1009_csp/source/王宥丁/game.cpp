#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
const int mod=1e9+7;
int in(int x,int y,int n,int m)
{
	if(x==0&&y==0)
	{
		return 1;
	}
	if(x==n&&y==0)
	{
		return 1;
	}
	if(x==0&&y==m)
	{
		return 1;
	}
	if(x==n&&y==m)
	{
		return 1;
	}
	return 0;
}
void wy(int &x,int &y,int &op,int n,int m,int &ans)
{
	if(op==1)
	{
		int step=min(n-x,m-y);
		x+=step;
		y+=step;
		if(x==n&&y==m)
		{
			return;
		}
		if(x==n)
		{
			op=2;
			ans++;
		}
		if(y==m)
		{
			op=4;
			ans++;
		}
		return;
	}
	if(op==2)
	{
		int step=min(x,m-y);
		x-=step;
		y+=step;
		if(x==0&&y==m)
		{
			return;
		}
		if(x==0)
		{
			op=1;
			ans++;
		}
		if(y==m)
		{
			op=3;
			ans++;
		}
		return;
	}
	if(op==3)
	{
		int step=min(x,y);
		x-=step;
		y-=step;
		if(x==0&&y==0)
		{
			return;
		}
		if(x==0)
		{
			op=4;
			ans++;
		}
		if(y==0)
		{
			op=2;
			ans++;
		}
		return;
	}
	if(op==4)
	{
		int step=min(n-x,y);
		x+=step;
		y-=step;
//		x++;
//		y--;
		if(x==n&&y==0)
		{
			return;
		}
		if(x==n)
		{
			op=3;
			ans++;
		}
		if(y==0)
		{
			op=1;
			ans++;
		}
		return;
	}
}
int f[1010][1010];
int s[1010][1010];
int calc(int n,int m)
{
	int op=1;//RU,RD,LD,LU
	int x=0,y=0,ans=0;//{0,0},{0,n},{n,0},{n,n}
	do{
		wy(x,y,op,n,m,ans);
	}while(!in(x,y,n,m));
//	cout << ans;
	return ans;
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T;
	cin >> T;
	for ( int i = 1 ; i <= 100 ; i++ )
	{
		for ( int j = 1 ; j <= 100 ; j++ )
		{
			f[i][j]=calc(i,j);
			f[i][j]%=mod;
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+f[i][j];
		}
	}
	while(T--)
	{
		int n,m;
		cin >> n >> m;
		cout <<s[n][m] <<endl;
	}
	return 0;
 } 
 /*
3
5 4
4 4
1000 981
 */
