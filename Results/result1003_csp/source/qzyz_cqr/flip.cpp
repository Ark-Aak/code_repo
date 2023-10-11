//100
#include<bits/stdc++.h>
#define int long long
#define MX 1000005
using namespace std;
int n,k,p,mod=998244353ll,h[MX],ny[MX];
signed main(){
	freopen("flip.in","r",stdin);
	freopen("flip.out","w",stdout);
	cin>>n>>k;ny[1]=1;
	for(int i=2;i<=n;i++)
		ny[i]=(ny[i-(mod%i)]*(mod/i+1ll))%mod;
	h[1]=(n*(n+1ll)/2ll)%mod;
	for(int j=2;j<=k;j++)
		h[j]=(h[j-1]*(((n+j)*(n-j+1ll)/2ll)%mod)%mod)*ny[j]%mod;
	cout<<h[k];
	return 0;
}
