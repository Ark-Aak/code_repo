#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,mod,inv[15],vis[15],sum=0;
int ine[100005];
void dfs(int x) {
	if(x==n+1) {
		int s[15],flag=0;
		for(int i=1;i<=n;i++) s[i]=inv[i];
		for(int i=1;i<=n;i++) {
			int x=0;
			for(int j=1;j<=n;j++) if(s[j]==i) x=j;
			int s1=x-1,s2=x+1;
			if(s1==0) s1=n;
			if(s2==n+1) s2=1;
			if(min(s[s1],s[s2])<i && i<max(s[s1],s[s2])) {
				sum=(sum+1)%mod;
				return ;
			}
			swap(s[s1],s[s2]);
		}
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(!vis[i]) {
			inv[x]=i;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	scanf("%d %d",&n,&mod);
	ine[0]=1;
	for(int i=1;i<=n;i++) ine[i]=(ine[i-1]*i)%mod;
	if(n%2==1 && n>1) printf("%d",ine[n]);
	else {
		dfs(1);
		printf("%d",sum);
	}
	return 0;
}

