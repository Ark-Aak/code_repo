#include<bits/stdc++.h>
using namespace std;
int n,k,ans1=0,ans2;
int a[500005];
int st[500005],tp;
int id[500005];
int ans[500005];
signed main() {
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		while(st[tp]<=a[i]&&tp>0) tp--;
		if(tp==0) ans[i]=1;
		else ans[i]=ans[id[tp]]+1;
		st[++tp]=a[i];
		id[tp]=i;
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
