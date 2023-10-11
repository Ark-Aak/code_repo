#include<bits/stdc++.h>
#define N 20
using namespace std;
int n, k, m, ans;
int l[N], r[N], s[N];
int num[N];
void dfs(int x) {
	if(x == n + 1) {
		for(int i = 1; i <= m; i++) {
			int g = 0;
			for(int j = l[i]; j <= r[i]; j++) g ^= num[j];
			if(g != s[i]) return;
		}
		ans++;
		return;
	}
	for(int i = 0; i < (1 << k); i++) {
		num[x] = i;
		dfs(x + 1);
	}
}
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> n >> k >> m;
	if(k == 0) {
		cout << 1;
		return 0;
	}
	for(int i = 1; i <= m; i++) cin >> l[i] >> r[i] >> s[i];
	dfs(1);
	cout << ans;
	return 0;
}
