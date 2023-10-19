#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

int n, m;
int ans[200005], c[200005], v[200005], l[200005], r[200005];
vector <int> G[200005];
bitset <200005> vis;

void dfs(int u, int col) {
	c[u] = col;
	ans[col] = max(ans[col], v[u]);
	vis[u] = 1;
	for (auto x : G[u]) {
		if (!vis[x]) dfs(x, col);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("journey.in", "r", stdin);
	freopen("journey.out", "w", stdout);
#endif
#endif
	cin >> n >> m;
	rep (i, 1, n) {
		cin >> l[i] >> r[i] >> v[i];
	}
	rep (i, 1, m) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	rep (i, 1, n) if (!vis[i]) dfs(i, i);
	rep (i, 1, n) cout << ans[c[i]] << " ";
	return 0;
}
