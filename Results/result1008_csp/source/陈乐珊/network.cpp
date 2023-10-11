#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int n,q,root;
int head[N],to[N],net[N],cnt;
struct sss {
	string s;
	int x;
}a[N];
void add(int u,int v) {
	to[++cnt]=v;
	net[cnt]=head[u];
	head[u]=cnt;
}
int ans=1e9;
int b[N];
void dfs(int now,int fa) {
	b[now]=min(now,b[fa]);
	for(int i=head[now];i;i=net[i]) {
		if(to[i]==fa) continue ;
		dfs(to[i],now);
	}
}
int main() {
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	scanf("%d%d",&n,&q);
	int u,v;
	for(int i=1;i<=n;i++) {
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=q;i++) {
		cin>>a[i].s;
		scanf("%d",&a[i].x);
	}
	root=a[1].x;
	b[0]=1e9;
	dfs(root,0);
	for(int i=1;i<=q;i++) {
		if(a[i].s=="JC") {
			ans=min(ans,b[a[i].x]);
		} else {
			printf("%d\n",min(ans,b[a[i].x]));
		}
	}
	return 0;
}

