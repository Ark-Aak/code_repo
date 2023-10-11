#include <bits/stdc++.h>
#define uint unsigned int
using namespace std;
const int N = 1e6+5; 
int n,q;
uint f[N],g[5][N],sum[5][N];
string s;
int get(char ch)
{
	if(ch=='m') return 1;
	if(ch=='i') return 2;
	if(ch=='l') return 3;
	if(ch=='k') return 4;
	return 0;
}
int get_pre(int x)
{
	x--;
	if(x<0) x = 4;
	return x;
}
signed main()
{
	freopen("milky.in","r",stdin);
	freopen("milky.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>s>>q,n = s.size(),s = ' '+s;
	if(n<=1000&&q<=1000)
	{
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			memset(f,0,sizeof f);
			g[0][0] = g[1][0] = g[2][0] = g[3][0] = g[4][0] = 0;
			uint ans = 0;
			for(int i = l;i<=r;i++)
			{
				if(s[i]=='m') f[i] = 1;
				else if(s[i]=='i') f[i] = g[1][0];
				else if(s[i]=='l') f[i] = g[2][0];
				else if(s[i]=='k') f[i] = g[3][0];
				else f[i] = g[4][0],ans+=f[i];
				g[get(s[i])][0]+=f[i];
			}
			cout<<ans<<'\n';
		}
		return 0;
	}
	for(int i = 1;i<=n;i++)
	{
		if(s[i]=='m') f[i] = 1;
		else if(s[i]=='i') f[i] = g[1][i-1];
		else if(s[i]=='l') f[i] = g[2][i-1];
		else if(s[i]=='k') f[i] = g[3][i-1];
		else f[i] = g[4][i-1];
		for(int j = 0;j<5;j++) g[j][i] = g[j][i-1];
		g[get(s[i])][i]+=f[i];
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		int ans = g[0][r]-g[0][l-1];
		cout<<ans<<'\n';
	}
	return 0;
}

