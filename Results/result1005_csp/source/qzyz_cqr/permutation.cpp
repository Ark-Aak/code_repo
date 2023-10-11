//30
#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,xh,f[5][100005];
signed main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>f[0][i];
	for(int i=1;i<=n;i++) cin>>f[1][i];
	for(int j=2;j<=k;j++){
		for(int i=1;i<=n;i++) f[j%3][f[(j-2)%3][i]]=f[(j-1)%3][i];
		//for(int i=1;i<=n;i++){cout<<test[i]<<' ';}cout<<'\n';
		//for(int i=1;i<=n;i++){cout<<f[j][i]<<' ';}cout<<'\n';
	}
	for(int i=1;i<=n;i++) cout<<f[k%3][i]<<' ';
	return 0;
} 
