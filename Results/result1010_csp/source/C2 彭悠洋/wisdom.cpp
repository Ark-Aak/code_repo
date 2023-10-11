#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9+7,N = 1e6+5;
int n,m,k;
int mulr[N],mulc[N],sum,ans,cnt;
signed main()
{
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++) mulr[i] = 1;
	for(int i = 1;i<=m;i++) mulc[i] = 1;
	while(k--)
	{
		char op;int x,y;
		cin>>op>>x>>y;
		if(op=='R') (mulr[x]*=y)%=mod;
		else (mulc[x]*=y)%=mod;
	}
	for(int i = 1;i<=m;i++)
		(sum+=mulc[i]*i%mod)%=mod,(cnt+=mulc[i])%=mod;
	(cnt*=m)%=mod;
	for(int i = 1;i<=n;i++)
	{
		ans+=mulr[i]*sum;
		(sum+=cnt)%=mod;
	}
	cout<<ans;
	return 0;
}

