#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int b[5003];
int c[5003];
int ans,mx;
const int mod=1000000007;
void dfs(int x){
	if(x>n){
		for(int i=0;i<=mx+1;i++){
			if(!c[i]){
				ans+=i;
				ans%=mod;
				return;
			}
		}
	}
	for(int i=0;i<=b[x];i++){
		c[i]++;
		dfs(x+1);
		c[i]--;
	}
}
int dfs2(int x,int s){
	if(x>n) return s;
	int res=min(s,b[x]+1)*dfs2(x+1,s)%mod;
	for(int i=s;i<=b[x];i++){
		c[i]++;
		int o=s;
		while(c[o]>0) o++;
		res+=dfs2(x+1,o);
		res%=mod;
		c[i]--;
	}
	return res;
}
signed main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&b[i]),mx=max(mx,b[i]);
	if(n<=7&&mx<=7){
		dfs(1);
		printf("%lld",ans);
		return 0;
	}
	printf("%lld",dfs2(1,0));
	return 0;
}


