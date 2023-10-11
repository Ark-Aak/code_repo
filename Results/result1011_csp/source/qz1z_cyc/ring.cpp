#include<bits/stdc++.h>
using namespace std;
long long ans=1,n,m,ans2=1,ans3=1;
int main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		ans=(ans*i)%m;
		if(i<=n/2) ans2=(ans2*i)%m;
	}
	if(n%2==1)
	{
		cout<<ans;
		return 0;
	}
	ans3=(((((n/2-1)*(n/2-2))%m)*n)%m+(n/2-2)*2*n)%m;
	cout<<ans<<" "<<ans2<<" "<<ans3<<endl;
	cout<<(ans-(2*ans2*ans2)%m-ans3+2*m)%m;
	return 0;
}
