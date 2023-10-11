#include<bits/stdc++.h>
using namespace std;
long long n,ans,mod;
int main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	cin>>n>>mod;
	ans=1;
	for(int i=2;i<=n;i++)
	{
		ans=(ans*i)%mod;
	}
	if(n%2==1)
	{
		cout<<ans;
		return 0;
	}
	
	return 0;
 } 
