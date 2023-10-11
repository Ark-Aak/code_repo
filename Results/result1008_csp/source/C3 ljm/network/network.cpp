#include<bits/stdc++.h>
using namespace std;
int n, q;
vector<int>p[1000006];
int ans[1000006];
void dfs(int x, int fa, int now) {
	now = min(now, x);
	ans[x] = min(ans[x], now);
	for(int i = 0; i < p[x].size(); i++) {
		int y = p[x][i];
		if(y == fa) continue;
		dfs(y, x, now);
	}
}
int a[1000006], tot, b[1000006];
void dfs2(int x, int fa) {
	tot++;
	a[x] = tot;
	b[tot] = x;
	for(int i = 0; i < p[x].size(); i++) {
		int y = p[x][i];
		if(y == fa) continue;
		dfs2(y, x);
	}
}
int c[4000006];
void pushup(int u) {
	c[u] = min(c[u * 2], c[u * 2 + 1]);
}
void build(int u, int L, int R) {
	if(L == R) {
		c[u] = b[L];
		return;
	}
	int mid = (L + R) / 2;
	build(u * 2, L, mid);
    build(u * 2 + 1, mid + 1, R);
	pushup(u);
}
int query(int u, int L, int R, int l, int r) {
	if(l <= L && R <= r) return c[u];
	if(r < L || R < l) return 1e9;
	int mid = (L + R) / 2;
	return min(query(u * 2, L, mid, l, r), query(u * 2 + 1, mid + 1, R, l, r));
}
signed main() {
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n - 1; i++) {
    	int u, v;
    	scanf("%d %d", &u, &v);
    	p[u].push_back(v);
    	p[v].push_back(u);
    	ans[i] = 1000000000;
	} 
	ans[n] = 1000000000;
	if(n <= 4000 && q <= 4000) {
	    while(q--) {
		    int x;
		    string opt;
		    cin >> opt;
		    scanf("%d", &x);
		    if(opt[0] == 'J') {
			    dfs(x, 0, 1000000000);
		    }
		    else printf("%d\n", ans[x]);
	    }
	    return 0;
	}
	int x = 0;
	for(int i = 1; i <= n; i++) {
		if(p[i].size() == 1) {
			x = i;
			break;
		}
	}
	dfs2(x, 0);
	build(1, 1, n);
	int L = 1e9, R = -1e9; 
	while(q--) {
		int x;
		string opt;
		cin >> opt;
		scanf("%d", &x);
		if(opt[0] == 'J') {
			L = min(L, a[x]);
			R = max(R, a[x]);
			//cout << L << " " << R << endl;
		}
		else {
			printf("%d\n", min(query(1, 1, n, min(L, a[x]), max(L, a[x])), query(1, 1, n, min(R, a[x]), max(R, a[x]))));
		} 
	}
	return 0;
}
/*
7 8
3 4
4 7
7 2
2 1
1 5
5 6


*/

