#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int n, k, ans;
vector <int> G[500];
bitset <500> vis;

void dfs(int now, int fa, int l, int r) {
	if (now < l || now > r) return;
	vis[now] = 1;
	for (auto x : G[now]) {
		if (x == fa) continue;
		dfs(x, now, l, r);
	}
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
#endif
	cin >> n >> k;
	rep (i, 1, n - 1) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	rep (l, 1, n) {
		rep (r, l, n) {
			vis.reset();
			int tans = 0;
			rep (i, l, r) {
				if (!vis[i]) {
					dfs(i, i, l, r);
					tans++;
					tans %= 1000000007;
				}
			}
			tans %= 1000000007;
			if (k == 2) tans *= tans;
			tans %= 1000000007;
			ans += tans;
			ans %= 1000000007;
		}
	}
	cout << ans;
	return 0; 
}
