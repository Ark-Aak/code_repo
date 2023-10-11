#include <bits/stdc++.h>
#define ll long long
using namespace std;
int f[410][310],n,k,a[410],sum[410];
int main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	scanf("%d%d",&n,&k);k++;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			int maxx=a[i];
			for(int l=i-1;~l;l--){	
				f[i][j]=min(f[i][j],f[l][j-1]+maxx*(i-l)-(sum[i]-sum[l]));
				maxx=max(maxx,a[l]);
			}
		}
	}
	printf("%d",f[n][k]);
	return 0;
}
/*
6 2
7 9 8 2 3 2

20 4
39524 958937 259688 832496 222561 360806 394792 291334 524923 681754
570969 502688 814973 467235 158907 919239 519917 559138 639223 892817

*/
