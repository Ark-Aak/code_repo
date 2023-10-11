#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005,Mod=998244353;
int n,m,ans;
int a[N];
int p[N];
int f[2][N][N];
void dfs(int x,int lian){
	if(x==n+1){
		ans++;
		ans%=Mod;
		return;
	}
	for(int i=1;i<=m;i++){
		if(i!=p[x-1]){
			p[x]=i;
			dfs(x+1,1);
			p[x]=0;
		}
		else{
			if(lian+1>a[i]) continue;
			p[x]=i;
			dfs(x+1,lian+1);
			p[x]=0;
		}
	}
}
signed main() {
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+m+1);
	if(n<=5&&m<=5){
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=m;i++)
		f[1][i][1]=1;
	for(int i=1;i<=n;i++){
		
		for(int j=1;j<=m;j++){
			int sum=0;
			for(int t=1;t<min(i+1,a[j]);t++){
				f[i&1][j][t+1]+=f[(i&1)^1][j][t];
				f[i&1][j][t+1]%=Mod;
			}
			for(int t=1;t<=min(i,a[j]);t++){
				sum+=f[(i&1)^1][j][t];
				sum%=Mod;
			}
			for(int t=1;t<=m;t++){
				if(j==t) continue;
				f[i&1][t][1]+=sum;
				f[i&1][t][1]%=Mod;
			}
		}
		for(int j=0;j<=m;j++)
			for(int t=0;t<=m;t++)
				f[i&1^1][j][t]=0;
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=a[i];j++){
			ans+=f[n&1][i][j];
			ans%=Mod;
		}
	}
	cout<<ans;
	return 0;
}//ÒªÓÃprintf£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡
/*
20 30
12 3 11 8 2 1 10 4 3 3 7 19 18 18 5 10 4 3 9 15 9 15 13 9 10 4 20 3 17 6 
*/
