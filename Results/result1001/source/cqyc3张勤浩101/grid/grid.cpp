#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,m;
int main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		if(n>m) swap(n,m);
		if(n==1){
			printf("0\n");
			continue;
		}
		if(n==2){
			ll ans=0;
			for(ll i=1;i<=m-1;i++){
				ans=ans+(m-i)*(i+2);
			}
			printf("%lld\n",ans*2*m);
			continue;
		}
	}
	return 0;
}
/*
3
2 2
2 3
3 2
*/
