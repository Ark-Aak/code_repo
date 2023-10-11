#include<bits/stdc++.h>
#define ll long long
#define N 2005
#define endl "\n" 
using namespace std;
ll phi[N],p[N],tot,n,m;
ll f[N][N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("ring.in","r",stdin);
    freopen("ring.out","w",stdout);
   	cin>>n>>m;
   	ll t1=1,t2=1,t3=1;
   	const ll mod=m;
   	for(int i=2;i<=n;i++){
   		t1=t1*i%mod;
   		if(i<=n-1)t2=t2*i%mod;
   		if(i<=n-2)t3=t3*i%mod%mod;
	}
	if(n&1)cout<<t1%mod;
	else cout<<(t1%mod-t2%mod+t3%mod+mod+mod+mod+mod+mod+mod)%mod;
//	439455059
//	368862484
    return 0;
}
