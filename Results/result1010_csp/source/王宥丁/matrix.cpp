#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
string s[30];
int cnt[200010];
int res=inf;
signed main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for ( int i = 0 ; i < n ; i++ )
	{
		cin >> s[i];
	}
//	for ( int i = 0 ; i < n ; i++ )
//	{
//		cout << s[i] << endl;
//	 } 
	for ( int i = 0 ; i < (1ll<<n) ; i++ )
	{
		for ( int j = 0 ; j < n ; j++ )
		{
			if((i>>j)&1)
			{
				for ( int k = 0 ; k < m ; k++ )
				{
					if(s[j][k]=='0')
					{
						cnt[k]++;
					}
				}
			}else{
				for ( int k = 0 ; k < m ; k++ )
				{
					if(s[j][k]=='1')
					{
						cnt[k]++;
					}
				}
			}
		}
		int ans=0;
		for ( int i = 0 ; i < m ; i++ )
		{
			ans=ans+min(cnt[i],n-cnt[i]);
		}
		res=min(res,ans);
		memset(cnt,0,sizeof(cnt));
	}
	cout << res;
	return 0;
}//10
