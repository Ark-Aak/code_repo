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

const int MAXN = 25;
int n, m, d;
vector <int> G[MAXN];
int dis[MAXN];
bitset <MAXN> to[MAXN];

void bfs(int st) {
	memset(dis, 0x3f, sizeof dis);
	dis[st] = 0;
	queue <int> q;
	q.push(st);
	bitset <MAXN> res;
	to[st][st] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : G[u]) if (dis[v] > dis[u] + 1) {
			dis[v] = dis[u] + 1;
			to[st][v] = 1;
			if (dis[v] < d) q.push(v);
		}
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tower.in", "r", stdin);
	freopen("tower.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), d = read();
	if (n > 20) return print(n), 0;
	rep (i, 2, n) {
		int f = read();
		G[f].push_back(i);
		G[i].push_back(f);
	}
	int ans = 0;
	rep (i, 1, n) bfs(i);
	rep (i, 0, (1 << n) - 1) {
		if (__builtin_popcount(i) != m) continue;
		bitset <MAXN> tmp;
		tmp.set();
		rep (j, 1, n) if (i >> (j - 1) & 1) {
			tmp &= to[j];
		}
		ans = max(ans, (int) tmp.count());
	}
	print(ans);
	return 0;
}
