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

int n, m;
vector <int> G[15];
bitset <15> vis;
int ans = 1e9;

void dfs(int step, int u, int val) {
	if (vis[u]) return (void) (ans = min(ans, val));
	vis[u] = 1;
	int cnt = 0;
	for (auto v : G[u]) {
		++cnt;
		dfs(step + 1, v, max(val, v));
	}
	if (!cnt) ans = min(ans, val);
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	rep (i, 1, m) {
		int u, v;
		read(u), read(v);
		G[u].emplace_back(v);
	}
	rep (i, 1, n) {
		vis.reset();
		ans = 1e9;
		dfs(1, i, i);
		print(ans), putchar(10);
	}
	return 0;
}
