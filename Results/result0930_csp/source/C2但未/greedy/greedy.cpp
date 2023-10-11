#include<bits/stdc++.h>
#define int long long
using namespace std;
const int Mod=147744151;
int n,k;
int cnt;
int f[1000005][30];
int solve(int n,int k){
	if(f[n][k])return f[n][k];
	if(n<=0)return 0;
	if(k==1)return n-1;
	int res=1e18;
	for(int mid=1;mid<=n;mid++)
	res=min(res,max(solve(mid-1,k-1),solve(n-mid-1,k))+1);
	//printf("%d %d %d\n",n,k,min(n-1,res));
	return f[n][k]=min(n-1,res);
}
signed main(){
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	if(k==1){
		printf("%lld",(n-1)%Mod);
		return 0;
	}
	int ans=log2(n);
	if(1ll<<ans!=n)ans++;
	if(k>=ans){
		printf("%lld\n",ans);
		return 0;
	}
	printf("%lld\n",solve(n,k));
	return 0;
}

