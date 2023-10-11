#include<bits/stdc++.h>
//100
#define int long long
using namespace std;
int n,k,m,a,res,p[1000005];
signed main(){
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a);res+=a;
		if(i%k==1 || k==1) p[++m]=a;
	}
	sort(p+1,p+1+m);
	printf("%lld",res-p[1+(m>>1)]);
	return 0;
} 
