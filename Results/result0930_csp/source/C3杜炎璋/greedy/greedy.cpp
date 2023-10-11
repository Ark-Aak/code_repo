#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=147744151;
signed main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	int n,k;
	scanf("%lld %lld",&n,&k);
	if(k==1) {
		printf("%lld",((n)/2)%mod);
		return 0;
	} else if(k==2){
		printf("%lld",(((n)/4+1)/2+1)%mod);	
	} else if(k>=log2(n*2-1)) {
		printf("%lld",((long long)log2(n*2-1))%mod);
	}
	return 0;
}

