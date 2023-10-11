#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,sum;
int tot,s[1000003];
int a[1000003];
signed main(){
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i];
	for(int i=1;i<=n;i+=k){
		s[++tot]=a[i];
	}
	sort(s+1,s+tot+1);
	printf("%lld",sum-s[tot/2+1]);
	return 0;
}


