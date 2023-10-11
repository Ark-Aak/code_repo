#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	int n,k;
	long long ans=1;
	for(int i=1;i<=n+k;i++)ans=ans*2%1000000007;
	cout<<ans%1000000007;
	return 0;
}


