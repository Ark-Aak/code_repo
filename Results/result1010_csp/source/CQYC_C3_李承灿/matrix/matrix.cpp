#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[5][5];
int ans,res;
string s[25];
void dfs2(int x){
	if(x>m){
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==1) sum++;
			}
		}
		ans=min(ans,sum);
		return;
	}
	dfs2(x+1);
	for(int i=1;i<=n;i++) a[i][x]^=1;
	dfs2(x+1);
	for(int i=1;i<=n;i++) a[i][x]^=1;
}
void dfs(int x){
	if(x>n){
		dfs2(1);
		return;
	}
	dfs(x+1);
	for(int i=1;i<=m;i++) a[x][i]^=1;
	dfs(x+1);
	for(int i=1;i<=m;i++) a[x][i]^=1;
}
signed main(){
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) cin>>s[i],s[i]=' '+s[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=s[i][j]-'0';
			if(a[i][j]==1) res++;
		}
	}
	ans=min(res,n*m-res);
	dfs(1);
	printf("%lld",ans);
	return 0;
}


