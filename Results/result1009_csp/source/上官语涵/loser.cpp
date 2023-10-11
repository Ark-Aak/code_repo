#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int a[N], vis[N], f[N][22], dep[N], s[N], s2[N], cnt, cnt2;
vector<int>v[N];
vector<int>q[N];
void dfs(int x, int fa) {
	f[x][0] = fa;
	dep[x] = dep[fa] + 1;
	for(int i = 0; i < v[x].size(); i++) {
		if(v[x][i] == fa) continue;
		dfs(v[x][i], x);
	}
}
int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20; i >= 0; i--) if(dep[f[x][i]] >= dep[y]) x = f[x][i];
	if(x == y) return x;
	for(int i = 20; i >= 0; i--) {
		if(f[x][i] != f[y][i]) {
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}
void change(int x, int y) {
	a[x] ^= 1;
	if(x == y) return;
	change(f[x][0], y);
}
void query(int x, int p) {
	
	s[++cnt] = a[x];
	if(x == p) return;
	query(f[x][0], p);
}
void query2(int y, int p) {
	s2[++cnt2] = a[y];
	if(y == p) return;
	query2(f[y][0], p);
}
int main() {
	freopen("loser.in", "r", stdin);
	freopen("loser.out", "w", stdout);
	int n, Q, root;
	cin >> n >> Q;
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		q[y].push_back(x);
		vis[y]++;
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if(!vis[i]) root = i;
	}
	dfs(root, 0);
	for(int i = 1; i <= 20; i++) {
		for(int j = 1; j <= n; j++) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
	}
	while(Q--) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if(op == 1) {
			int p = lca(x, y);
			change(x, p);
			change(y, p);
			a[p] ^= 1;
		}
		else {
			int p = lca(x, y);
			cnt = cnt2 = 0;
			query(x, p);
			query2(y, p);
			int ff = 0, num = 0, ans = 0;
			for(int i = cnt2 - 1; i >= 1; i--) s[++cnt] = s2[i];
			for(int i = 1; i <= cnt; i++) {
				if(s[i] == 0) ++ff;
				else --ff;
				if(ff < 0) num = 0, ff = 0;
				else ++num;
				if(ff == 0) ans = max(ans, num);
			}
			printf("%d\n", ans);
		}
	}

}
