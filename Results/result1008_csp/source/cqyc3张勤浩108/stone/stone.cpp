#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Mod=1e9+7;
ll n,k,ans=1; 
int main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n+k;i++) ans=ans*2%Mod;
	cout<<ans;
	return 0;
}


