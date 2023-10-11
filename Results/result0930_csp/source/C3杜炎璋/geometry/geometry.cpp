#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("geometry.in","r",stdin);
	freopen("geometry.out","w",stdout);
	int n,l;
	scanf("%lld %lld",&n,&l);
	if(n==2*l) printf("%lld",n+n/2);
	else if(n==l) printf("%lld",l);
	return 0;
}

