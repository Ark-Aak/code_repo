#include<bits/stdc++.h>
using namespace std;
long long n, head[500005], tail[1000005], nxt[1000005], tot;
long long siz[500005], f[500005], ans[500005];
long long read() {
	long long x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')	f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x<<3) + (x<<1) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
void add_edge(int u, int v) {
	tail[++tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
	tail[++tot] = u;
	nxt[tot] = head[v];
	head[v] = tot;
	return;
}
void dfs(int x, int fa) {
	siz[x] = 1;
	for(int i = head[x]; i ;i = nxt[i]) {
		int ed = tail[i];
		if(ed == fa)	continue;
		dfs(ed, x);
		siz[x] += siz[ed];
	}
	f[x] = siz[x] * x * 2 - x;
	for(int i = head[x]; i; i = nxt[i]) {
		int ed = tail[i];
		if(ed == fa)	continue;
		f[x] += siz[ed] * (siz[x] - siz[ed] - 1) * x;
	}
	ans[1] += f[x];
	return;
}
void dfs2(int x, int fa) {
	for(int i = head[x]; i; i = nxt[i]) {
		int ed = tail[i];
		if(ed == fa)	continue;
		ans[ed] = ans[x] - (siz[ed] * 2 + (siz[x] - siz[ed]) * siz[ed]) * x;
		ans[ed] += ((siz[ed] - 1) * (siz[x] - siz[ed]) * 2 + (siz[x] - siz[ed]) * 2) * ed;
		int t = siz[x];
		siz[x] -= siz[x] - siz[ed];
		siz[ed] = t;
		dfs2(ed, x);
	}
	return;
}
int main() {
	n = read();
	for(int i = 1; i < n ; ++i) {
		long long u, v;
		u = read(); v = read();
		add_edge(u, v);
	}
	dfs(1, 0);
	dfs2(1, 0);
	cout<<ans[2];
	return 0;
}
