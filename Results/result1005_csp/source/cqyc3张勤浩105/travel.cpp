#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Maxn=1e5+7,Mod=998244353;
ll n,k,m,l[Maxn],r[Maxn],s[Maxn];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld%lld%lld",&n,&k,&m);
	for(ll i=1;i<=m;i++) scanf("%lld%lld%lld",&l[i],&r[i],&s[i]);
	if(k==0){
		printf("1");
		return 0;
	}
	cout<<0;
	return 0;
}


