#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int n,m,deg[500005],cnt[500005],ans;
signed main()
{
	freopen("gen.in","r",stdin);
	freopen("gen.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
	}
	sort(deg+1,deg+n+1);
	for(int i=1;i<=n;i++)
	{
		cnt[deg[i]]++;
	}
	int id=unique(deg+1,deg+n+1)-deg-1;
	for(int i=1;i<=id;i++)
	{
		for(int j=i+1;j<=id;j++)
		{
			ans+=(((deg[i]^deg[j])*(deg[i]|deg[j]))%mod*(deg[i]&deg[j]))%mod*cnt[deg[i]]%mod*cnt[deg[j]]%mod;
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}
