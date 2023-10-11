#include<bits/stdc++.h>
using namespace std;
long long n,m,a[25][200005],ans=1145141919810,kl[25],ans2,ans3;
string s;
void dfs(long long x)
{
	if(x==n)
	{
		ans3=0;
		for(long long i=1;i<=m;i++)
		{
			ans2=0;
			for(long long j=1;j<=n;j++)
			{
				if((a[j][i]+kl[j])%2==1) ans2++;
			}
			if(ans2>=(n+1)/2) ans3+=n-ans2;
			else ans3+=ans2;
		}
		ans=min(ans,ans3);
		return;
	}
	kl[x+1]=1;
	dfs(x+1);
	kl[x+1]=0;
	dfs(x+1);
} 
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>s;
		for(long long j=1;j<=m;j++)
		{
			a[i][j]=s[j-1]-'0';
		}
	}
	dfs(0);
	cout<<ans;
	return 0;
}

