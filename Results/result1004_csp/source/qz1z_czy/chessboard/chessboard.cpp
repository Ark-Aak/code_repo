#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define red(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=2e3+10;
int n,m;
int fl;
char mp[N][N];
int c;
bool solve()
{
	rep(i,1,n-1)
	{
		rep(j,1,m-1)
		{
			if(mp[i][j]=='0'&&mp[i+1][j+1]=='0'&&mp[i][j+1]=='1'&&mp[i+1][j]=='1')
				return false;
			if(mp[i][j]=='1'&&mp[i+1][j+1]=='1'&&mp[i][j+1]=='0'&&mp[i+1][j]=='0')
				return false;
		}
	}
	return true;
}
void dfs(int stp)
{
	if(stp==c)
	{
		if(solve())
		{
			cout<<"Yes"<<'\n';
			rep(i,1,n)
			{
				rep(j,1,m)
					cout<<mp[i][j];
				cout<<'\n';
			}
			exit(0);
		}
		return;
	}
	rep(i,1,n)
	{
		rep(j,1,m)
		{
			if(mp[i][j]=='?')
				mp[i][j]='1',dfs(stp+1),stp--;
			if(mp[i][j]=='?')
				mp[i][j]='0',dfs(stp+1),stp--;
		}
	}
}
signed main(void)
{
//	freopen("chessboard.in","r",stdin);
//	freopen("chessboard.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	scanf("%d%d",&n,&m);
	rep(i,1,n)
	{
		rep(j,1,m)
		{
			cin>>mp[i][j];
			if(mp[i][j]=='?')
				c++;
		}
	}
	
	dfs(0);
	cout<<"No";
	return 0;
}
