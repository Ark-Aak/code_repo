#include<bits/stdc++.h>
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
#define red(i,a,b) for(int (i)=(a);(i)>=(b);++(i))
using namespace std;
string s;
int a[30];
int ans;
signed main(void)
{
	freopen("reinforce.in","r",stdin);
	freopen("reinforce.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>s;
	int len=s.size()-1;
	rep(i,0,len) a[s[i]-'a']++;
	rep(i,0,25) ans=max(ans,a[i]);
	rep(i,1,len-1) if(s[i]==s[i-1]) ans++;
	printf("%d",ans);
	return 0;
}
