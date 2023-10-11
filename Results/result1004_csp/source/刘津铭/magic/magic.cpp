#include<bits/stdc++.h>
#define int long long 
#define N 200005
using namespace std;
int n, tot;
int c[N], a[N][6];
vector<int>p[N], g[N];
struct edge{
	int u, v, len;
}e[3000006];
int cnt = 0;
void add(int U, int V, int W) {
	e[++cnt].u = U;
	e[cnt].v = V;
	e[cnt].len = W;
}
int fa[1000006];
int find(int x) {
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void join(int x, int y) {
	int fx = find(x), fy = find(y);
	if(fx != fy) fa[fx] = fy;
}
bool cmp(edge a, edge b) {
	return a.len < b.len;
}
int work() {
	int ans = 0;
	for(int i = 1; i <= cnt; i++) {
		int U = e[i].u, V = e[i].v;
		if(find(U) != find(V)) {
			join(U, V);
			ans += e[i].len;
		}
	}
	return ans;
}
signed main() {
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) {
		int c = 0;
		scanf("%lld", &c);
		int A = tot + 1, B = tot + 2, C = tot + 3, D = tot + 4;
		for(int j = 1; j <= 4; j++) {
			scanf("%lld", &a[i][j]);
			tot++;
			g[a[i][j]].push_back(tot);
		}
		add(A, B, 0);
		add(C, D, 0);
		add(B, C, c);
	}
	for(int i = 1; i <= 2 * n; i++) {
		add(g[i][0], g[i][1], 0);
	}
	for(int i = 1; i <= tot; i++) fa[i] = i;
	sort(e + 1, e + cnt + 1, cmp);
	printf("%lld", work());
	return 0;
}
