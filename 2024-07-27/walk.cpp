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

const int MAXN = 7.5e4 + 5;
vector <int> G[MAXN];
int n, m, dis[MAXN];

void bfs0() {
	queue <int> q;
	memset(dis, 0x3f, sizeof dis);
	dis[n] = -1;
	q.push(n);
	while (q.size()) {
		int tp = q.front();
		q.pop();
		for (auto v : G[tp]) {
			if (dis[tp] + 1 < dis[v]) {
				dis[v] = dis[tp] + 1;
				q.push(v);
			}
		}
	}
}

int ans = 0;
bool mk[MAXN];

void bfs1(int st) {
	/* dis[st]--; */
	queue <int> q;
	q.push(st);
	while (q.size()) {
		int tp = q.front();
		q.pop();
		for (auto v : G[tp]) {
			if (dis[tp] + (!mk[tp]) < dis[v]) {
				dis[v] = dis[tp] + (!mk[tp]);
				q.push(v);
			}
		}
	}
}

int p[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	ignore = freopen("walk.in", "r", stdin);
	ignore = freopen("walk.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, n - 1) p[i] = read();
	rep (i, 1, m) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bfs0();
	rep (i, 1, n - 1) {
		int p = ::p[i];
		mk[p] = 1;
		ans += dis[p];
		bfs1(p);
	}
	print(ans);
	return 0;
}
