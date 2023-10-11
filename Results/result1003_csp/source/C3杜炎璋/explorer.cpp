#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[500005];
signed main(){
	freopen("explorer.in","r",stdin);
	freopen("explorer.out","w",stdout);
	int n,sum=0,ans=0;
	scanf("%lld",&n);
	for(int i=n;i>=1;i--) {
		f[i]+=f[i+1]+1;
		sum+=f[i];
	}
	for(int i=1;i<=n;i++) {
		ans+=sum-f[i]-f[i+1];
		sum-=f[i];
	}
	printf("%lld",ans);
	return 0;
}

