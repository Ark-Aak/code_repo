#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[500005];
int ans[500005];
signed main() {
	freopen("double.in","r",stdin);
	freopen("double.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}

	for(int i=1;i<=n;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 10

