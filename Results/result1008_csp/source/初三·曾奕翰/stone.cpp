#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int n,k,ans;
int p[N];
void dfs(int x){
	if(x==n+1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(p[j]==j){
					for(int t=1;t<j;t++){
						p[t]++;
					}
					p[j]=-1e9;
					break;
				}
			}
			
		}
		for(int i=1;i<=n;i++){
			if(p[i]>=0)ans+=p[i];
		}
		return;
	}
	for(int i=0;i<=k;i++){
		p[x]=i;
		dfs(x+1);
	}
}
signed main() {
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	dfs(1);
	cout<<ans;
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡

