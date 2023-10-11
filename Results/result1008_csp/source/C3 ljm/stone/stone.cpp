#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
int n, k, ans, now = 1e9;
int a[30], b[30];
void dfs1(int x) {
	if(x == n + 1) {
		int sum = 0;
		for(int i = 1; i <= n; i++) sum += a[i];
		now = min(now, sum);
		return;
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] == i) {
			for(int j = 1; j < i; j++) a[j]++;
			a[i] = 0;
			dfs1(x + 1);
			for(int j = 1; j < i; j++) a[j]--;
			a[i] = i;
		}
	}
	dfs1(x + 1);
}
void dfs(int x) {
	if(x == n + 1) {
		now = 1e9;
		for(int i = 1; i <= n; i++) b[i] = a[i];
		dfs1(1);
		for(int i = 1; i <= n; i++) a[i] = b[i];
		ans = (ans + now) % mod; 
		return;
	}
	for(int i = 0; i <= k; i++) {
		a[x] = i;
		dfs(x + 1);
	}
}
signed main() {
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
    cin >> n >> k;
    dfs(1);
    cout << ans;
	return 0;
}

