#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int a[200005],inv[20],t[20];
int n,ans=0;
void dfs(int x) {
	if(x==n+1) {
		memset(t,0,sizeof t);
		for(int i=1;i<=n;i++) t[inv[i]]++;
		for(int i=0;i<=n+2;i++) {
			if(!t[i]) {
				ans=(ans+i)%mod;
				return ;
			}
		}
		return ;
	}
	for(int i=0;i<=a[x];i++) {
		inv[x]=i;
		dfs(x+1);
	}
}
int main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dfs(1);
	printf("%d",ans);
	return 0;
}

