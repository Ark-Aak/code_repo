#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105,mod=1e9+7;
int n,k;
int p[N],ans;
void dfs(int now,int s) {
	if(now>n) {
		for(int i=n;i>=1;i--) {
			if(p[i]==i) {
				p[i]=0;
				for(int j=i-1;j>=1;j--)
					p[j] ++ ;
			}
			ans=(ans+p[i])%mod;
		}
		return ;
	}
	p[now]=s;
	for(int i=0;i<=k;i++) {
		dfs(now+1,i);
	}
}
int main() {
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	scanf("%lld%lld",&n,&k);
	dfs(0,0);
	cout<<ans/2;
	return 0;
}
/*
dp[i][j][e] 
dp[i][j][e] = dp[i+1][j:0-->k][e]+dp[i+1][(i+1)-(e-1)][e-1]
*/
