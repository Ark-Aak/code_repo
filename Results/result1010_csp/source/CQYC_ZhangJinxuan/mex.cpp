#include <bits/stdc++.h>
using namespace std;

int n, a[66], res[66];
bool vis[66];
const int p = 1e9 + 7;
long long ans;

int mex() {
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; ++i) vis[res[i]] = 1;
	for (int i = 0; i < 66; ++i) {
		if (!vis[i]) return i;
	} 
}

void dfs(int i) {
	if (i == n + 1) {
		(ans += mex());
		ans %= p;
		return;
	}
	for (int j = 0; j <= a[i]; ++j) {
		res[i] = j;
		dfs(i + 1);
	}
}
int main() {
	freopen("mex.in", "r", stdin);
	freopen("mex.out","w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}
