#include <bits/stdc++.h>
using namespace std;
int T;
string s;
bool ok(int x,int y)
{
	int mid = (x+y)/2;
	for(int i = 0;i<=mid-x;i++)
	{
		if(s[x+i]=='?'||s[mid+1+i]=='?') continue;
		if(s[x+i]!=s[mid+1+i]) return 0;
	}
	return 1;
}
void solve()
{
	cin>>s;
	int n = s.size();
	s = ' '+s;
	int ans = 0;
	for(int i = 1;i<=n;i++)
		for(int j = i+3;j<=n;j+=2)
			for(int k = i+1;k<j;k+=2)
				if(ok(i,k)&&ok(k+1,j))
					ans++;
	cout<<ans<<'\n';
}
signed main()
{
	freopen("excellent.in","r",stdin);
	freopen("excellent.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}

