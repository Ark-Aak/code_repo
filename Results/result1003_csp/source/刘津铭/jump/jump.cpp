#include<bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int n;
int a[N], b[N], d[N], ans[N], tot;
map<int, int>g;
int c[N * 4];
int query(int u, int L, int R, int l, int r) {
	if(l <= L && R <= r) return c[u];
    if(r < L || R < l) return 0;
	int mid = (L + R) / 2;
	return max(query(u * 2, L, mid, l, r), query(u * 2 + 1, mid + 1, R, l, r));	
}
void pushup(int u) {
	c[u] = max(c[u * 2], c[u * 2 + 1]);
}
void update(int u, int L, int R, int x, int y) {
	if(L == R) {
		c[u] = max(c[u], y);
		return; 
	} 
	int mid = (L + R) / 2;
	if(x <= mid) update(u * 2, L, mid, x, y);
	else update(u * 2 + 1, mid + 1, R, x, y);
	pushup(u);
}
signed main() {
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	for(int i = 1; i <= n; i++) {
		if(i == 1 || b[i] != b[i - 1]) {
			d[++tot] = b[i];
		}
	}
	for(int i = 1; i <= tot; i++) g[d[i]] = i;
	for(int i = 1; i <= n; i++) {
		a[i] = g[a[i]];
		//cout << a[i] << endl;
	}
	for(int i = 1; i <= n; i++) {
		//cout << query(1, 1, n + 1, a[i] + 1, n + 1) << endl;
		ans[i] = ans[query(1, 1, n + 1, a[i] + 1, n + 1)] + 1;
		printf("%lld ", ans[i]);
		update(1, 1, n + 1, a[i], i);
	}
	return 0;
} 
