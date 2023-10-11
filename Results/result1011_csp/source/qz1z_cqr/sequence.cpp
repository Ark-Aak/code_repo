//O(nmm) 30pts 
#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,res,f[3][100005];
int gmod(int oo){return oo%998244353ll;}
signed main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	cin>>n>>m;
	if(n==1){cout<<m;return 0;}
	for(int i=1;i<=m;i++){f[1][i]=1;}
	for(int i=2;i<=n;i++){
	for(int j=1;j<=m;j++){
		f[i&1][j]=0;
		for(int k=1;k<=j;k++)
			f[i&1][j]=gmod(f[i&1][j]+f[(i&1)^1][k]);
		for(int k=j+1;k<=m;k++)
			if(k%j) f[i&1][j]=gmod(f[i&1][j]+f[(i&1)^1][k]);
		if(i==n) res=gmod(res+f[i&1][j]);
	}}cout<<res;
	return 0;
}

