#include<bits/stdc++.h>
using namespace std;
int f[3][100005],same=0,g[100005][3];
int main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	int n,k;
	scanf("%d %d",&n,&k);
	same=k+10;
	for(int i=1;i<=n;i++) {
		scanf("%d",&f[0][i]);
		g[i][0]=f[0][i];
	}
	for(int i=1;i<=n;i++) {
		scanf("%d",&f[1][i]);
		g[i][1]=f[1][i];
	}
	for(int i=2;i<=k;i++) {
		for(int j=1;j<=n;j++) {
			f[i%3][f[(i+1)%3][j]]=f[(i+2)%3][j];
		}
		int flag1=1,flag0=1;
		for(int j=1;j<=n;j++) {
			if(f[(i+2)%3][j]!=g[j][0]) {
				flag0=0;
				break;
			}
		}
		for(int j=1;j<=n;j++) {
			if(f[i%3][j]!=g[j][1]) {
				flag1=0;
				break;
			}
		}
		if(flag0==1 && flag1==1) {
			same=i;
			break;
		}

	}
	int w=(k)%(same-1);
	for(int i=1;i<=n;i++) {
		f[0][i]=g[i][0];
		f[1][i]=g[i][1];
	}
	for(int i=2;i<=w;i++) {
		for(int j=1;j<=n;j++) 
			f[i%3][f[(i+1)%3][j]]=f[(i+2)%3][j];
	}
	for(int i=1;i<=n;i++) {
		printf("%d ",f[(w)%3][i]);
	}
	return 0;
}

