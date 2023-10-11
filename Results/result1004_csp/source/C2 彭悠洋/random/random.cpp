#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 4e3+5,mod = 998244353;
int n,g[N][N],s[N][N],m,ans[10],tmp[N][N];
char ch;
int qpow(int x,int y)
{
	if(y<0) return 0;
	int res = 1;
	while(y)
	{
		if(y&1) res = res*x%mod;
		y>>=1;
		x = x*x%mod;
	}
	return res;
}
signed main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			cin>>ch,g[i][j] = ch-48;
	for(int i = 1;i<=n;i++)
		for(int j = i+1;j<=n;j++)
			if(!(g[i][j]||g[j][i]))
				m++;
	if(n<=500)
	{
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++)
			{
				if(i==j) continue;
				for(int k = 1;k<=n;k++)
				{
					if(i==k||j==k) continue;
					if(g[i][j]&&g[j][k]&&g[k][i]) ans[3]++;
					else if(g[i][j]&&g[j][k]&&g[k][i]==0) ans[2]+=(g[i][k]==0);
					else if(g[i][j]&&g[j][k]==0&&g[k][i]==0) ans[1]+=(g[k][j]==0&&g[i][k]==0);
					else if(!(g[i][j]||g[j][k]||g[k][i])) ans[0]+=(g[j][i]==0&&g[k][j]==0&&g[i][k]==0);
				}
			}
	}
	else
	{
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++)
				s[i][j] = s[i-1][j]+s[j-1][i]-s[i-1][j-1]+g[i][j];
//		for(int i = 1;i<=n;i++)
//			for(int k = 1;k<=n;k++)
//				
	}
	ans[0]/=3,ans[3]/=3;
	ans[0]%=mod,ans[1]%=mod,ans[2]%=mod,ans[3]%=mod;
	cout<<(ans[0]*qpow(2,m-3)%mod+ans[1]*qpow(2,m-2)%mod+ans[2]*qpow(2,m-1)%mod+ans[3]*qpow(2,m)%mod)%mod;
	return 0;
}

