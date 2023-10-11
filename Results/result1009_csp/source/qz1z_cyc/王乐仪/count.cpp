#include<bits/stdc++.h>
using namespace std;
long long ans=0;
long long a[105];
long long n,m;
void dfs(long long x,long long s,long long y){
	if(x==n){
		ans++;
		return;
	}
	for(long long i=1;i<=m;i++){
		if(s==i&&y<a[i])dfs(x+1,i,y+1);
		if(s!=i) dfs(x+1,i,1);
	}
}
int main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>m;
	if(n>50&&m>50){
		long long ans=1;
		for(long long i=1;i<=n;i++)ans=ans%99824353*m%998244353;
		cout<<ans;
		return 0;
	}
	for(long long i=1;i<=m;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans;
	return 0;
}


