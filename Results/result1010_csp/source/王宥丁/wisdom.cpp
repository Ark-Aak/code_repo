#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
int h[1000010],l[1000010];
const int mod=1e9+7;
int fp(int x,int p)
{
	int ans=1;
	while(p)
	{
		if(p&1)
		{
			ans=ans*x%mod;
		}
		p>>=1;
		x=x*x%mod;
	}
	return ans;
}
int inv(int x)
{
	return fp(x,mod-2);
}
vector<int>u,v;
signed main()
{
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	int n,m,q;
	cin>>n>>m>>q;
	for ( int i = 1 ; i <= 1000000 ; i++ ) 
	{
		h[i]=l[i]=1;
	}
	while(q--)
	{
		char op;
		int x,y;
		cin >> op >> x >> y;
		if(op=='R')
		{
			h[x]=h[x]*y%mod;
		}else{
			l[x]=l[x]*y%mod;
		}
	}
	int ans=(n*m+1)%mod*(n*m)%mod*inv(2)%mod;
	for ( int i = 1 ; i <= n ; i++ )
	{
		ans=ans+(h[i]-1)*(i*m%mod+(i-1)*(m)%mod+1)%mod*m%mod*inv(2)%mod;
		ans%=mod;
		if(h[i]!=1)
		{
			u.push_back(i);
		}
	}
	for ( int i = 1 ; i <= m ; i++ )
	{
		ans=ans+(l[i]-1)*(i+(n-1)*m%mod+i)%mod*n%mod*inv(2)%mod;
		if(l[i]!=1)
		{
			v.push_back(i);
		}
	}
	for ( int i = 0 ; i < u.size() ; i++ )
	{
		int q=u[i];
		for ( int j = 0 ; j < v.size() ; j++ )
		{
			int p=v[j];
			ans=ans+(l[p]*h[q]-h[q]-l[p]+1)%mod*((q-1)*m+p)%mod;
			ans%=mod;
		}
	}
	cout << ans;
	return 0;
}//100
