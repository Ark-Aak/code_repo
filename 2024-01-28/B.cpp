#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 100000 + 10;
const int MOD = 1000000007;
int n, x, y, a[MAXN];
vector <int> G[MAXN];
int f[MAXN];

void dfs(int x, int fa) {
	f[x] = 1;
	for (auto v : G[x]) {
		if (v == fa) continue;
		dfs(v, x);
		f[x] = f[x] * (f[v] + 1) % MOD;
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
#endif
#endif
	n = read(), x = read(), y = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		if (a[u] != 1 || a[v] != 1) continue;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ll ans = 0;
	rep (i, 1, n) {
		if (a[i] != 1) continue;
		if (!f[i]) dfs(i, 0);
	}
	rep (i, 1, n) ans += f[i], ans %= MOD;
	print(ans % MOD);
	return 0;
}
