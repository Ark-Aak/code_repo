#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
bool a[60][60];
int col[50010];
int ans[50010];
int n,k;
queue<int>q;
signed main()
{
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	cin >> n >> k;
	for ( int i = 1 ; i <= n ; i++ )
	{
		cin >> col[i];
	}
	getchar();
	for ( int i = 1 ; i <= k ; i++ )
	{
		for ( int j = 1 ; j <= k ; j++ )
		{
			a[i][j]=getchar()-'0';
		}
		getchar();
	}
	memset(ans,0x3f,sizeof(ans));
	ans[1]=0;
	q.push(1);
	while(!q.empty())
	{
		int fr=q.front();
		for ( int i = 1 ; i <= n ; i++ )
		{
			if(a[col[fr]][col[i]]&&ans[fr]+abs(fr-i)<ans[i])
			{
				ans[i]=ans[fr]+abs(fr-i);
				q.push(i);
			}
		}
		q.pop();
	}
	if(ans[n]==0x3f3f3f3f3f3f3f3f)
	{
		cout << -1;
		return 0;
	}
	cout << ans[n];
	return 0;
 } //40
 /*
5 4
1 4 2 3 4
1010
0001
0110
0100
 */
