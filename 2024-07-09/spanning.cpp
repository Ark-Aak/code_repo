#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef __int128 i128;
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

const int MAXN = 50;
int T, n, m;
vector <pii> edges;
int fa[MAXN], vis[MAXN][MAXN];
int deg[MAXN];

int find(int u) {
	if (fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}

void solve() {
	n = read(), m = read();
	edges.clear();
	memset(vis, 0, sizeof vis);
	rep (i, 1, m) {
		int u = read(), v = read();
		if (u == v) continue;
		if (vis[u][v]) continue;
		vis[u][v] = vis[v][u] = 1;
		edges.emplace_back(u, v);
	}
	m = edges.size();
	bool ok = 0;
	rep (i, 1, (1 << m) - 1) {
		if (__builtin_popcount(i) != n - 1) continue;
		rep (j, 1, n) fa[j] = j;
		memset(deg, 0, sizeof deg);
		bool flg = 0;
		rep (j, 0, m - 1) {
			if (i >> j & 1) {
				int u = edges[j].ec, v = edges[j].fb;
				if (find(u) == find(v)) {
					flg = 1;
					break;
				}
				fa[find(v)] = find(u);
				deg[u]++, deg[v]++;
			}
		}
		rep (j, 2, n) if (find(j) != find(1)) {
			flg = 1;
			break;
		}
		if (flg) continue;
		int good = 0;
		rep (j, 1, n) if (deg[j] & 1) good++;
		if (good & 3) continue;
		puts("YES");
		ok = 1;
		break;
	}
	if (!ok) puts("NO");
}

signed main() {
#ifndef LOCAL
	ignore = freopen("spanning.in", "r", stdin);
	ignore = freopen("spanning.out", "w", stdout);
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
