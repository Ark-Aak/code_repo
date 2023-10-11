#include <iostream>
#include <cstdio>
const int N=405;
int n,k;
int a[N],sum[N],max[N][N];
int dp[N][N];
inline int value(int l,int r) {
	return (r-l+1)*max[l][r]-sum[r]+sum[l-1];
}
int main() {
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++) {
			int res=-0x7fffffff;
			for(int k=i;k<=j;k++)
				res=std::max(res,a[k]);
			max[i][j]=res;
		}
	for(int i=1;i<=n;i++) {
		dp[i][0]=value(1,i);
		for(int j=1;j<=k;j++)
			dp[i][j]=0x3f3f3f3f;
	}
	dp[1][0]=0;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=std::min(k,i-1);j++)
			for(int l=1;l<i;l++)
				dp[i][j]=std::min(dp[i][j],dp[l][j-1]+value(l+1,i));
	printf("%d",dp[n][k]);
	return 0;
} 
