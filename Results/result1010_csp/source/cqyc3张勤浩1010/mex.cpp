#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll Maxn=1e5+7,Mod=1e9+7;
ll n,a[Maxn],ans,b[Maxn],V;
void dfs(ll pos){
	if(pos==n+1){
		ll x=0;
		for(ll i=0;i<=V;i++){
			if(!b[i]){
				x=i;
				break;
			}
		}
		ans+=x;
		//cout<<"h\n";
		ans%=Mod;
		return ;
	}
	for(ll i=0;i<=a[pos];i++){
		b[i]++;
		dfs(pos+1);
		b[i]--;
	}
} 
int main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]),V=max(V,a[i]);
	dfs(1);
	printf("%lld",ans%Mod);
	return 0;
}
/*
5
6 8 3 2 1 

8
3 7 1 11 0 4 1 9
*/

