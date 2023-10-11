#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int ans;
int f[105][105];
bool vis[105][105];
const int mod=1000000007;
int dfs(int x,int h){
	if(x==0) return 0;
	if(vis[x][h]) return f[x][h];
	int res=0;
	for(int i=0;i<=k;i++){
		if(i<=x) res+=((i+h)/x+dfs(x-1,h+(i+h)/x))%mod;
		else res+=dfs(x-1,h);
		res%=mod; 
	}
	vis[x][h]=1;
	f[x][h]=res;
	return res;
}
signed main(){
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%lld %lld",&n,&k);
	int t=1,sum=0;
	for(int i=1;i<n;i++) t=t*(k+1)%mod;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			sum+=j*t;
			sum%=mod;
		}
	}
	printf("%lld",(sum-dfs(n,0)+mod)%mod);
	return 0;
}


