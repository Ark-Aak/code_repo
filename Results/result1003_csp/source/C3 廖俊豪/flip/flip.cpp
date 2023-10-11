#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int mod=998244353;
int n,k,ans;
int s[25];
bool check(int l,int r){
	if(!s[l])return 0;
	if(!s[r])return 0;
	for(int i=l+1;i<=r;i++){
		if(s[i]^s[i-1])continue;
		return 0;
	}
	return 1;
}
void dfs(int x){
	if(x>k){
		ans++;
		return;
	}
	for(int i=1;i<=2*n-1;i++){
		for(int j=i;j<=2*n-1;j++){
			if(check(i,j)){
				for(int l=i;l<=j;l++)s[l]^=1;
				dfs(x+1);
				for(int l=i;l<=j;l++)s[l]^=1;
			}
		}
	}
}
signed main(){
	scanf("%lld %lld",&n,&k);
	freopen("flip.in","r",stdin);
	freopen("flip.out","w",stdout);
	if(n==k){
		ans=1;
		for(int i=2;i<=n;i++)ans=(ans*(i*2-1))%mod;
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=2*n-1;i++)s[i]=(i&1);
	dfs(1);
	printf("%lld",ans);
	return 0;
}//数量级的数量级对了,那就是对了(doge 
