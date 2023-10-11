#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5,M=5e5+5;
int n,m;
int head[N],to[M],net[M],w[M],cnt;
void add(int u,int v,int l) {
	to[++cnt]=v;
	net[cnt]=head[u];
	w[cnt]=l;
	head[u]=cnt;
}
int dfs(int now,int s,int o) {
	int L=1e9;
	if(o==0) L=-L;
	for(int i=head[now];i;i=net[i]) {
		if(w[i]<=s) continue ;
		if(o) L=max(dfs(to[i],w[i],o^1),L);
		else L=min(dfs(to[i],w[i],o^1),L);
	}
	return L+1;
}
int main() {
	freopen("increase.in", "r", stdin);
	freopen("increase.out", "w", stdout);
	scanf("%d%d",&n,&m);
	int x,y,z;
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=n;i++) {
		cout<<dfs(i,0,1)<<" ";
	}
	return 0;
}
/*
选择最短路径最长的点 
*/
