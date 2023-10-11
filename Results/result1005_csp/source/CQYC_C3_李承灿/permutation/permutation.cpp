#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,K,f[3][100005],t; 
int k;
int p[100005],q[100005];
int r(int x,int y){
	if(x+y>=3) return x+y-3;
	return x+y;
}
signed main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%lld %lld",&n,&K);
	for(int i=1;i<=n;i++) scanf("%lld",&p[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&q[i]);
	for(int i=1;i<=n;i++){
		f[0][i]=p[i];
		f[1][i]=q[i];
	}
	k=K;
	for(int i=2;i<=k;i++){
		for(int j=1;j<=n;j++){
			f[r(t,2)][f[t][j]]=f[r(t,1)][j];
		}
		t=r(t,1);
		if(k!=K||(n<=1000&&K<=1000)) continue;
		int z=0;
		for(int j=1;j<=n;j++){
			if(f[r(t,1)][j]!=q[j]){
				z=1;
				break;
			}
		}
		if(z==0){
			for(int j=1;j<=n;j++){
				if(f[t][j]!=p[j]){
					z=1;
					break;
				}
			}
		}
		if(z==0) k=(k-1)%(i-1),i=0;
	}
	for(int i=1;i<=n;i++) printf("%lld ",f[r(t,1)][i]);
	return 0;
}


