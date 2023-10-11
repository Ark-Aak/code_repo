#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k; 
int a[402],b[402];
int tot,x[402];
int dp[2][402][302];
int mn[2][402];
int o;
int ans=1e9;
signed main(){
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),b[i]=a[i];
	sort(a+1,a+n+1);
	a[0]=-1;
	b[0]=-1;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			x[++tot]=a[i];
		}
	}
	for(int i=0;i<=1;i++){
		for(int j=0;j<=tot;j++){
			for(int p=0;p<=k;p++){
				dp[i][j][p]=1e9;
				mn[i][p]=1e9;
			}
		}
	}
	for(int i=1;i<=tot;i++) dp[0][i][0]=0;
	mn[0][0]=0;
	for(int i=1;i<=n;i++){
		o^=1;
		for(int j=1;j<=tot;j++){
			for(int p=0;p<=k;p++){
				dp[o][j][p]=1e9;
				mn[o][p]=1e9;
			}
		}
		for(int j=tot;j>=1;j--){
			if(x[j]<b[i]) break;
			if(x[j]>=b[i-1]){
				for(int p=0;p<=k;p++){
					dp[o][j][p]=min(dp[o][j][p],dp[o^1][j][p]+x[j]-b[i]);
				}
			}
			for(int p=1;p<=k;p++){
				dp[o][j][p]=min(dp[o][j][p],mn[o^1][p-1]+x[j]-b[i]);
			}
		}
		for(int p=0;p<=k;p++){
			for(int j=1;j<=tot;j++){
				mn[o][p]=min(mn[o][p],dp[o][j][p]);
			}
		}
	}
	for(int i=1;i<=tot;i++){
		for(int j=0;j<=k;j++){
			ans=min(ans,dp[o][i][j]);
		}
	}	
	printf("%lld",ans);
	return 0;
}


