#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=2e5+7,inf=1e9+6;
int n,m,a[25][Maxn],ans=inf,Sm[Maxn];
int Sy[1<<15];
int r[1<<15][15],Svp;
int main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&a[i][j]);
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(a[j][i])
				Sm[i]|=(1<<(j-1));
	if(n<=13){
		for(int i=1;i<=m;i++) Sy[Sm[i]]++;
		for(int i=0;i<(1<<n);i++)
		for(int j=0;j<(1<<n);j++)
			r[i][__builtin_popcount(i^j)]+=Sy[j];
		for(int i=0;i<(1<<n);i++){
			int res=0;
			for(int j=1;j<n;j++)
				res+=min(j,n-j)*r[i][j];
			ans=min(ans,res);
		}
		printf("%d",ans);
		return 0;
	}
	for(int i=0;i<(1<<n);i++){
		int res=0;
		for(int j=1;j<=m;j++){
			int ret=__builtin_popcount(Sm[j]^i);
			Svp++;
			res+=min(ret,n-ret);
		}
		ans=min(ans,res);
		if(Svp>2e7) break;
	}
	printf("%d",ans);
	return 0;
}
/*
3 4
0110
1010
0111
*/

