#include<bits/stdc++.h>
using namespace std;
int n,k,Inf;
int a[405];
int f[405][405];
int ans=1e9;
signed main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	memset(f,0x3f,sizeof f);
	Inf=f[0][0];
	for(int i=1;i<=n;i++)
		if(a[i]>=a[1])f[0][i]=a[i]-a[1];
	for(int i=1;i<n;i++){
		int last=f[0][1];
		for(int j=2;j<n;j++)last=min(last,f[0][j]);
		for(int j=1;j<=k;j++){
			int res=Inf;
			for(int l=1;l<=n;l++){
				f[j][l]=min(f[j][l],last);
				res=min(res,f[j][l]);
			}
			last=res;
		}
		for(int j=0;j<=k;j++)
			for(int l=1;l<=n;l++)
				if(a[l]>=a[i+1])f[j][l]=f[j][l]+a[l]-a[i+1];
				else f[j][l]=Inf;
	}
	for(int i=1;i<=n;i++)
		ans=min(ans,f[k][i]);
	printf("%d",ans);
	return 0;
}/*
6 2
7 9 8 2 3 2
*/
