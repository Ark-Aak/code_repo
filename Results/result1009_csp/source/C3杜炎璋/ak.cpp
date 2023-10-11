#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],ans[1000005];
int val[1000005],to[100005];
signed main(){
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	int n,k,sum=0;
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i],val[i]=a[i],to[i]=i+1;
	if(k==1) {
		sort(a+1,a+n+1);
		printf("%lld",sum-a[n/2+1]);
	}
	return 0;
}

