#include<bits/stdc++.h>
using namespace std;
int n;
long long ans;
int main()
{	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	cin>>n;
	for(int i=2*n-1,j=1;i>=1;i-=2,++j) ans+=1ll*i*j;
	cout<<ans;
	return 0;
}
