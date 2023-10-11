#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,K,inv[15],cnt=0,w[15],sum=0;
void solve(int x) {
	if(x==0) return ;
	for(int i=1;i<=x;i++) {
		if(w[i]==i) {
			w[i]=0;
			for(int j=1;j<i;j++) w[j]++;
			solve(i-1);
		}
	}
}
void dfs(int x) {
	if(x==n+1) {
		cnt=0;
		for(int i=1;i<=n;i++) w[i]=inv[i];
		solve(n);
		for(int i=1;i<=n;i++) cnt+=w[i];
		sum=(sum+cnt)%mod;
		return ;
	}
	for(int i=0;i<=K;i++) {
		inv[x]=i;
		dfs(x+1);
	}
}
signed main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%lld %lld",&n,&K);
	dfs(1);
	printf("%lld",sum);
	return 0;
}

