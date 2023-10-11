#include<bits/stdc++.h>
using namespace std;
int n, m, head[500005], tail[500005], val[500005], nxt[500005], tot, g[500005][2], f[500005], A, B;
bool b[500005];
void add(int u, int v, int w) {
	tail[++tot] = v;
	val[tot] = w;
	nxt[tot] = head[u];
	head[u] = tot;
	tail[++tot] = u;
	val[tot] = w;
	nxt[tot] = head[v];
	head[v] = tot;
	return;
}
void dfs(int x, int pre) {
	A = 0, B = 0;
	for(int i = head[x]; i; i = nxt[i]) {
		int ed = tail[i];
		if(val[i] <= pre)	continue;
		dfs(ed, val[i]);
		g[x][0] = max(g[x][0], B + 1);
		if(b[x]) g[x][1] = A + 1, b[x] = false;
		else g[x][1] = min(g[x][1], A + 1);
		A++;
		A = max(A, g[x][0]);
		B++; 
		B = min(B, g[x][1]);
	}
	return;
}
int main() {
	freopen("increase.in","r",stdin);
	freopen("increase.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= m; ++i) {
		int x, y, z;
		cin>>x>>y>>z;
		add(x, y, z);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j)	g[j][0] = 0, g[j][1] = 0, b[j] = true;
		dfs(i, 0);
		f[i] = max(f[i], g[i][0]);
	}
	for(int i = 1; i <= n; ++i) {
		cout<<f[i]<<" ";
	}
	return 0;
}
