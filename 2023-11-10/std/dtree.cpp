#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,mod,f,s,inv[N];
signed main(){
	freopen("dtree.in","r",stdin);
	freopen("dtree.out","w",stdout);
	cin>>n>>mod;
	
	inv[1]=1;inv[2]=(mod+1)/2;
	for(int i=3;i<=n;i++){
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		s=(s+(f=((i+1)*(i-2)/2+2*s)%mod*inv[i]%mod))%mod;
	}
	for(int i=1;i<=n;i++)f=f*i%mod;
	
	
	cout<<f;
	return 0;
}