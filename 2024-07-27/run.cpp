#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
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

const int MAXN = 1e3 + 5;
int n, m;
int b[MAXN][MAXN], dis[MAXN * MAXN], vis[MAXN * MAXN];
vector <pii> G[MAXN * MAXN];
#define id(x, y) (((x) - 1) * m + (y))

void dijkstra(int s) {
	priority_queue <pii, vector <pii>, greater <pii> > q;
	memset(dis, 0x3f, sizeof dis);
	dis[s] = 0; q.push(make_pair(0, s));
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto v : G[u]) {
			int t = v.first, val = v.second;
			if (dis[t] > dis[u] + val) {
				dis[t] = dis[u] + val;
				if (!vis[t]) q.push(make_pair(dis[t], t));
			}
		}
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	ignore = freopen("run.in", "r", stdin);
	ignore = freopen("run.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, n) rep (j, 1, m) b[i][j] = read();
	int ans = 0;
	if (b[1][1] == 1 && b[n][m] == 1) {
		ans++;
		rep (i, 1, n) rep (j, 1, m) b[i][j] = 1 - b[i][j];
	}
	rep (i, 1, n) {
		rep (j, 1, m) {
			if (i + 1 <= n) {
				G[id(i, j)].push_back(dl(id(i + 1, j), b[i][j] != b[i + 1][j]));
			}
			if (j + 1 <= m) {
				G[id(i, j)].push_back(dl(id(i, j + 1), b[i][j] != b[i][j + 1]));
			}
		}
	}
	dijkstra(1);
	ans += (dis[n * m] + 1) / 2;
	print(ans), puts("");
	return 0;
}
