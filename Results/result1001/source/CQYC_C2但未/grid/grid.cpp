#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m;
int f[105][105];
int sum[105][105];
signed main(){
	freopen("grid.in","r",stdin);
	freopen("grid.out","w",stdout);
	scanf("%lld",&t);
	for(int i=1;i<=101;i++)
		for(int j=1;j<=101;j++){
			for(int x=1;x<=i;x++){
				if((j*x)%i==0)f[i][j]++;
			}
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+f[i][j];
		}
	while(t--){
		scanf("%lld%lld",&n,&m);
		if(n>m)swap(n,m);
		if(n==1)printf("0\n");
		else if(n==2){
			int ans=0;
			for(int i=1;i<m;i++)
				ans+=(i+2)*(m-i)*m;
			printf("%lld\n",ans*2ll);
		}
	}
	return 0;
}

