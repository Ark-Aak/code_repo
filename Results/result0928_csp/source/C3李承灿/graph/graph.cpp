#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,X[100005],Y[100005],f[100005],s;
int Find(int x){
	return x==f[x]?x:f[x]=Find(f[x]);
}
signed main(){
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld %lld",&X[i],&Y[i]),f[i]=i;
	s=n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(X[i]<=X[j]&&Y[i]<=Y[j]){
				if(f[Find(i)]!=f[Find(j)]){
					s--;
					f[Find(i)]=f[Find(j)];
				}
			}
		}
	}
	printf("%lld",s);
	return 0;
}


