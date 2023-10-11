#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,mod=1000000007,qn[105];
int main() 
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n>>k;
	qn[0]=1;
	for(int i=1;i<=n;i++)
	{
		qn[i]=(qn[i-1]*(k+1))%mod;
	}
	cout<<((n-k)*qn[n-1])%mod;
	return 0;
}
