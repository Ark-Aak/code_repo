#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
ll n,m;
int dp[2005][2005];
int sum[2005],ans;
int main() {
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++) dp[1][i]=1;
	for(int i=2;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			for(int k=1;k<=m;k++) {
				if(k<j&&j%k==0) continue ;
				dp[i][k]=(dp[i][k]+dp[i-1][j])%mod;
				if(i==n) ans=(ans+dp[i][k])%mod;
			}
		}
	}
	cout<<ans;
	return 0;
}

