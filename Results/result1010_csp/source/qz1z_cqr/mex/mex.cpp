//25
#include<bits/stdc++.h>
using namespace std;
#define int long long
using namespace std;
int n,res,mod=1000000007,b[25],f[20][262144];
bool c[20][262144];
int gmod(int oo){return oo%mod;}
int dfs(int t,int l){
	if(c[t][l]) return f[t][l];
	c[t][l]=1;
	if(t>n){
		int cnt=0,o=l;
		while(o&1){o>>=1;cnt++;}
		return f[t][l]=cnt;
	}
	int ans=0;
	for(int i=0;i<=min(n-1,b[t]);i++)
		ans=gmod(ans+dfs(t+1,l|(1<<i)));
	if(b[t]>=n)
		ans=gmod(ans+dfs(t+1,l)*(b[t]-n+1ll));
	return f[t][l]=ans;
}
signed main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){cin>>b[i];}
	cout<<dfs(1,0);
	return 0;
}

