#include <bits/stdc++.h>
using namespace std;
const int N = 22+5,M = 2e5+5,K = 5e6+5;
int n,m,a[N][M],to[K],sum[K],s[N],ans = 2e9;
signed main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	char ch;
	for(int i = 0;i<n;i++)
		for(int j = 1;j<=m;j++)
			cin>>ch,a[i][j] = ch-48;
	for(int j = 1;j<=m;j++)
	{
		int len = 0,zt = 0;
		for(int i = 0;i<n;i++)
		{
			if(a[i][j])
				len++,zt|=(1<<i);
		}
		sum[zt]++;
	}
	for(int i = 1;i<(1<<n);i++)
		to[i] = to[i-(i&(-i))]+1;
	for(int i = 0;i<(1<<n);i++)
	{
		int now = 0;
		for(int j = 0;j<(1<<n);j++)
			s[to[(i^j)]]+=sum[j];
		for(int j = 0;j<=n;j++)
			now+=min(n-j,j)*s[j],s[j] = 0;
//		cout<<i<<' '<<now<<'\n';
		ans = min(ans,now);
	}
	cout<<ans;
	return 0;
}

