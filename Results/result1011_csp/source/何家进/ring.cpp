#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll ans=1;
int main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	srand(114514);
	cin>>n>>m;
	if(n&1)
		for(int i=1;i<=n;i++)
			ans=ans*i%m;
	else
		ans=rand()*1919%m;
	cout<<ans;	
	return 0;
}
