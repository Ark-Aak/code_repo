#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=147741151;
inline void read(ll &x) {
    x = 0; char ch = getchar(); int f = 1;
    while (!isdigit(ch) && ch ^ '-') ch = getchar();
    if (ch == '-') f = -1, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar(); x *= f;
}
ll n,k,lg,m;
ll solve(ll n,ll k){
	if(k==1) return n;
	ll ans=0;
	for(ll i=1,j=1;i<=n;i<<=1,++j)
		ans=max(j+solve(i-(i>>1)-2,k-1),ans);
	return ans;
}
int main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	read(n),read(k);
	if(k==1){
		printf("%lld",n%mod);
		return 0;
	}
	lg=log2(n);
	if(1ll<<lg<n) ++lg;
	if(lg<=k){
		printf("%lld",lg%mod);
		return 0;
	} 
	printf("%lld",solve(n,k));
	return 0;
}

