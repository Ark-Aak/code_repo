#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,m;
const int mod=998244353;
struct node{
	int l,r;
}t[100005];
int r(int x,int y){
	x%=mod;
	int z=1;
	while(y){
		if(y&1) z=z*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return z;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%lld %lld %lld",&n,&k,&m);
	if(m==0){
		printf("%lld",r(n,r(2,k)));
		return 0;
	}
	if(k==0){
		printf("1");
		return 0;
	}
	return 0;
}


