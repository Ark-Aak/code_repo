#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 210;
const int M = 1e5 + 10;
const int Mod = 998244353;

int a[N], ans;
int n, m, d[N], vis[N][N][N], res = 0;
void dfs(int pos, int x, int cnt) {
	if(pos == n + 1) {
		ans = (ans + 1) % Mod;
		return;
	}
	for(int i = 1; i <= m; i++) {
		if(i == x) {
			if(cnt == a[x]) continue;
			else {
				d[pos] = x;
				dfs(pos + 1, x, cnt + 1);
				d[pos] = 0;
			}
		} else {
			d[pos] = i;
			dfs(pos + 1, i, 1);
			d[pos] = 0;
		}
	}
}
signed main() {
//	freopen("count.in", "r", stdin);
//	freopen("count.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) cin >> a[i];
	dfs(1, 0, 0);
	cout << ans;
}
