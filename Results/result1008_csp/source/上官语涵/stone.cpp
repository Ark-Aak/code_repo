#include<bits/stdc++.h>
using namespace std;
int n, k;
int d[110], tmp[110], a[110];
bool check() {
	for(int i = 1; i <= n; i++) if(tmp[i] == i) return false;
	return true;
}
int js() {
	int res = 0;
	for(int i = 1; i <= n; i++) tmp[i] = d[i];
	while(!check()) {
		for(int i = 1; i <= n; i++) {
			int x = a[i];
			if(tmp[x] == x) {
				for(int j = 1; j < x; j++) ++tmp[j];
				tmp[x] = 0;
			}
			else {
				res += tmp[x];
				tmp[x] = 0;
			}
		}
	}
	for(int i = 1; i <= n; i++) res += tmp[i];
	return res;
}
int Sum() {
	int res = 0;
	for(int i = 1; i <= n; i++) a[i] = i;
	for(int i = 1; i <= 720; i++) {
		if(js() > res) res = js(); 
		next_permutation(a + 1, a + n + 1);
	}
	return res;
}
int ans;
void dfs(int x) {
	if(x == n + 1) {
		ans += Sum();
		return;
	}
	for(int i = 0; i <= k; i++) {
		d[x] = i;
		dfs(x + 1);
		d[x] = 0;
	}
}
int main() {
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
	cin >> n >> k;
	dfs(1);
	cout << ans;
}
