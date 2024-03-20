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

const int MAXN = 3005;
const int INF = 1e18;
int n, m, C;
vector <int> G[MAXN];
int w[MAXN][MAXN];
int dis[MAXN][MAXN];
int f[MAXN][MAXN], cnt[MAXN];

void DIS(int u, int fa, int rt) {
	dis[rt][u] = dis[rt][fa] + w[fa][u];
	for (auto v : G[u]) if (v != fa) DIS(v, u, rt);
}

void dp(int u, int fa) {
	for (auto v : G[u]) if (v != fa) dp(v, u);
	rep (i, 1, n) f[u][i] = C + cnt[u] * dis[u][i];
	for (auto v : G[u]) if (v != fa) {
		rep (i, 1, n) f[u][i] += min(f[v][i] - C, f[v][0]);
	}
	f[u][0] = 1e18;
	rep (i, 1, n) f[u][0] = min(f[u][0], f[u][i]);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("post.in", "r", stdin);
	freopen("post.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), C = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read(), w = read();
		G[u].push_back(v);
		G[v].push_back(u);
		::w[u][v] = ::w[v][u] = w;
	}
	rep (i, 1, n) DIS(i, 0, i);
	rep (i, 1, m) cnt[read()]++;
	dp(1, 0);
	print(f[1][0]);
	return 0;
}
