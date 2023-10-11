#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[1000002],b[1000002];
int X,Y;
int dp[3002][3002][2];
bool vis[3002][3002];
inline int dfs(int x,int y,int o){
	if(vis[x][y]) return (o^1);
	if(dp[x][y][o]>0) return dp[x][y][o]-1;
	for(int i=0;i<x;i++){
		if(o==dfs(i,y,(o^1))){
			dp[x][y][o]=o+1;
			break;
		}
	}
	if(dp[x][y][o]==0){
		for(int i=0;i<y;i++){
			if(o==dfs(x,i,(o^1))){
				dp[x][y][o]=o+1;
				break;
			}
		}
	}
	if(dp[x][y][o]==0) dp[x][y][o]=(o^1)+1;
	return dp[x][y][o]-1;
}
int main(){
	freopen("act.in","r",stdin);
	freopen("act.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	if(q==0) return 0;
	vis[0][0]=true;
	for(int i=1;i<=n;i++) vis[a[i]][b[i]]=true;
	while(q--){
		scanf("%d %d",&X,&Y);
		if(n==0&&(X>3000||Y>3000)){
			if(X==Y) printf("Bob\n");
			else printf("Alice\n");
			continue;
		}
		if(dfs(X,Y,0)==0) printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}
