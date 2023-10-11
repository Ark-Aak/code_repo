//100
#include<bits/stdc++.h>
#define MX 500005
using namespace std;
int n,a[MX],res[MX],r=1,st[MX];
signed main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d",&n);st[1]=0;a[1]=1000000009;
	for(int i=1;i<=n;i++) scanf("%d",&a[i+1]);
	for(int i=2;i<=n+1;i++){
		while(a[st[r]]<=a[i]) r--;
		res[i]=res[st[r]]+1;st[++r]=i;
		printf("%d ",res[i]);
	}
	return 0;
}
