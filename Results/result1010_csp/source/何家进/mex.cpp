#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,b[114514];
int a[114514];
int num[114514];
int ans;
int cnt;
int mex()
{
	memset(num,0,sizeof num);
	for(int i=1;i<=n;i++)
		num[a[i]]++;
	for(int i=0;i<=10;i++)
		if(!num[i])
			return i;
}
void dfs(int x)
{
	if(x>n)
	{
		ans=(ans+mex())%mod;
		return;
	}
	for(int i=0;i<=b[x];i++)
	{
		a[++cnt]=i;
		dfs(x+1);
		--cnt;
	}
}
int main()
{
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>b[i];
	dfs(1);
	cout<<ans;
	return 0;
}
