#include<bits/stdc++.h>
#define int long long
#define N 4005
#define rep(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
int f[N][N];
int mod=998244353;
int ans;
int n;
signed main(void)
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	scanf("%lld",&n);
	string s;
	rep(i,1,n)
	{
		cin>>s;
		rep(k,0,n-1)
			if(s[k]=='1')
				f[i][k+1]=1;
	}
	rep(i,1,n)
	{
		rep(j,i+1,n)
		{
			if(!f[i][j]&&!f[j][i]) continue;
			rep(k,j+1,n)
			{
				if(f[i][j]&&f[j][k]&&f[k][i]) ans++;
				if(f[i][k]&&f[k][j]&&f[j][i]) ans++;
				ans%=mod;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
