#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5,mod=1e9+7;
ll T,n,m,ans;
ll f[1005][1005];
ll gcd(ll x,ll y) {
	return (y==0?x:gcd(y,x%y));
}
ll g(ll x,ll y) {
	if(x==y) return 0;
	if(x==1) return y/2%mod;
	if(y==1) return x/2%mod;
	if(x>y) swap(x,y);
	ll z=gcd(x,y);
	x/=z;
	y/=z;
	z=(x/2*2+y/2*2)%mod;
	if(y%2==1) z++;
	if(x%2==1) z--;
	return (z+mod)%mod;
}
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	scanf("%lld",&T) ;
	for(ll i=1;i<N;i++) {
		for(ll j=1;j<N;j++) {
			f[i][j]=(f[i-1][j]+f[i][j-1]-f[i-1][j-1]+g(i,j))%mod;
//			cout<<f[i][j]<<" ";
		}
//		cout<<"\n";
	}
	while(T--) {
		scanf("%lld%lld",&n,&m);
		printf("%lld\n",f[n][m]);
	}
	return 0;
}
/*
g(n,m)=n/2+m/2(n!=mÇÒn,m»¥ÖÊ)
f(n,m)=f(n-1,m)+f(n,m-1)-f(n-1)(f-1)+g(n/gcd(n,m),m/gcd(n,m));

3
5 4
4 4
1000 981

*/
