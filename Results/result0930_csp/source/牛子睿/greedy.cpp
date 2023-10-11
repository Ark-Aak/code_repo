#include <iostream>
#include <cstdio>
#include <cmath>
const long long MOD=147744151ll;
long long n,k;
int main() {
    freopen("greedy.in","r",stdin);
    freopen("greedy.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	if(k==1) printf("%lld\n",n-1);
	if(k==2) printf("%lld",(long long)(sqrt(2*n))%MOD);
	else {
		printf("%lld",(long long)(sqrt(pow(n,k))));
	}
	return 0;
} 