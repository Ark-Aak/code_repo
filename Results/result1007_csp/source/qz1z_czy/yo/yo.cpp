#include<bits/stdc++.h>
#define int long long
#define rp(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
#define lp(i,a,b) for(int (i)=(a);(i)>=(b);--(i))
using namespace std;
const int N=1e6+10;
int n;
string s,t;
int dp[N];
void dfs(int step)
{
	if(step==n)
	{
		int ctx=0,cty=0;
		for(int i=0;i<n;i+=2) ctx+=dp[i];
		for(int i=1;i<n;i+=2) cty+=dp[i];
		if(abs(ctx-cty)%11==0)
		{
			cout<<"yoimiya";
			exit(0);
		}
		else
		{
			cout<<"oimiya";
			exit(0);
		}
	}
	dp[step]=s[step]-'0';
	dfs(step+1);
	dp[step]=0;
	dfs(step+1);
}
signed main(void)
{
	freopen("yo.in","r",stdin);
	freopen("yo.out","w",stdout);
	cin>>n>>s>>t;
	dfs(0);
	cout<<"yoimiya";
	return 0;
}
