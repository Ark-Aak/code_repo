//30
#include<bits/stdc++.h>
using namespace std;
int n,m,res,a[1005],f[5][505][505],mod=998244353;
signed main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=m;i++) f[1][i][1]=1;
	for(int i=2;i<=n;i++){
		memset(f[i&1],0,sizeof(f[i&1]));
		for(int j=1;j<=m;j++){
		for(int k=1;k<=a[j];k++){
			if(i-k<0) continue;
			if(k>1)
				f[i&1][j][k]+=f[(i-1)&1][j][k-1];
			if(k==1){
				for(int jj=1;jj<=m;jj++){
					//cout<<jj<<'\n';
					if(j==jj) continue;
					for(int kk=1;kk<=a[jj];kk++){
						if(i-kk<1) continue;
						f[i&1][j][k]+=f[(i-1)&1][jj][kk];
						f[i&1][j][k]%=mod;
					}
				}
			}
			if(i==n) res+=f[i&1][j][k];
			res%=mod;
			//cout<<'k'<<k<<'\n';
			//cout<<i<<' '<<j<<' '<<k<<' '<<f[i][j][k]<<'\n';
		}}
	}cout<<res;
	return 0;
} 
