#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
int a[20];
int ans;
int n;
map<int,int>mp;
const int mod=1e9+7;
void mex()
{
	for ( int i = 0 ; i <= 5010 ; i++ )
	{
		if(mp[i]==0)
		{
			ans+=i;
			return;
		}
	 } 
}
void dfs(int x)
{
	if(x==n+1)
	{
		mex();
		ans%=mod;
		return;
	}
	for ( int i = 0 ; i <= a[x] ; i++ )
	{
		mp[i]++;
		dfs(x+1);
		mp[i]--;
	}
}
signed main()
{
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	cin >>n;
	for ( int i = 1 ; i <= n ; i++ )
	{
		cin >> a[i];
	}
	dfs(1);
	cout << ans;
	return 0;
}//10
/*
7
7 7 7 7 7 7 7
*/
