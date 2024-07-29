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

const int MAXN = 1e5 + 5;
const int INF = 1e9;
int n, m, k;
vector <int> G[MAXN], W[MAXN];
int dis[MAXN][105];
int deg[MAXN];

void bfs() {
	memset(dis, -1, sizeof dis);
	queue <pii> q;
	rep (i, 0, k) q.push(dl(n, i)), dis[n][i] = 0;
	while (q.size()) {
		auto [x, y] = q.front();
		q.pop();
		if (y == 0) {
			for (auto v : W[x]) {
				deg[v]--;
				if (!deg[v]) {
					rep (i, 0, k) {
						if (dis[v][i] != -1) continue;
						dis[v][i] = dis[x][y] + 1;
						q.push(dl(v, i));
					}
				}
			}
			if (!deg[x]) {
				rep (i, 1, k) {
					if (dis[x][i] != -1) continue;
					dis[x][i] = dis[x][y] + 1;
					q.push(dl(x, i));
				}
			}
		}
		else {
			for (auto v : G[x]) {
				if (dis[v][y - 1] != -1) continue;
				dis[v][y - 1] = dis[x][y] + 1;
				q.push(dl(v, y - 1));
			}
		}
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	ignore = freopen("boat.in", "r", stdin);
	ignore = freopen("boat.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), k = read();
	rep (i, 1, m) {
		int u = read(), v = read();
		G[u].push_back(v);
		W[v].push_back(u);
		G[v].push_back(u);
		deg[u]++;
	}
	bfs();
	rep (i, 1, n) print(dis[i][0]), puts("");
	return 0;
}
