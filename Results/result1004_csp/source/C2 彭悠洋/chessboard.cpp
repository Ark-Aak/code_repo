#include <bits/stdc++.h>
using namespace std;
const int N = 2e3+5;
int n,m;
char a[N][N];
signed main()
{
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=m;j++)
			cin>>a[i][j];
	for(int i = 1;i<n;i++)
		for(int j = 1;j<m;j++)
		{
			if(a[i][j]=='0'&&a[i+1][j]=='1'&&a[i][j+1]=='1'&&a[i+1][j+1]=='0') return cout<<"No",0;
			if(a[i][j]=='1'&&a[i+1][j]=='0'&&a[i][j+1]=='0'&&a[i+1][j+1]=='1') return cout<<"No",0;
			if(a[i][j]=='0'&&a[i+1][j]=='1'&&a[i][j+1]=='1') a[i+1][j+1] = '1';
			if(a[i][j]=='0'&&a[i+1][j]=='1'&&a[i+1][j+1]=='0') a[i][j+1] = '0';
			if(a[i][j]=='0'&&a[i][j+1]=='1'&&a[i+1][j+1]=='0') a[i+1][j] = '0';
			if(a[i+1][j]=='1'&&a[i][j+1]=='1'&&a[i+1][j+1]=='0') a[i][j] = '1';
			if(a[i][j]=='1'&&a[i+1][j]=='0'&&a[i][j+1]=='0') a[i+1][j+1] = '0';
			if(a[i][j]=='1'&&a[i+1][j]=='0'&&a[i+1][j+1]=='1') a[i][j+1] = '1';
			if(a[i][j]=='1'&&a[i][j+1]=='0'&&a[i+1][j+1]=='1') a[i+1][j] = '1';
			if(a[i+1][j]=='0'&&a[i][j+1]=='0'&&a[i+1][j+1]=='1') a[i][j] = '0';
		}
	for(int i = 1;i<n;i++)
		for(int j = 1;j<m;j++)
		{
			if(a[i][j]=='0'&&a[i+1][j]=='1'&&a[i][j+1]=='1'&&a[i+1][j+1]=='0') return cout<<"No",0;
			if(a[i][j]=='1'&&a[i+1][j]=='0'&&a[i][j+1]=='0'&&a[i+1][j+1]=='1') return cout<<"No",0;
			if(a[i+1][j]=='1'&&a[i][j+1]=='1')
			{
				if(a[i+1][j+1]=='?') a[i+1][j+1] = '1';
				if(a[i][j]=='?') a[i][j] = '1';
			}
			if(a[i][j]=='1'&&a[i+1][j+1]=='1')
			{
				if(a[i+1][j]=='?') a[i+1][j] = '1';
				if(a[i][j+1]=='?') a[i][j+1] = '1';
			}
		}
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=m;j++)
			if(a[i][j]=='?')
				a[i][j] = '0';
	cout<<"Yes\n";
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=m;j++)
			cout<<a[i][j];
		cout<<'\n';
	}
	return 0;
}

