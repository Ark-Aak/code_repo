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

const int MAXN = 1e6 + 5;
int n, m, q;
int a[MAXN], fa[MAXN];
int dep[MAXN];
vector <int> G[MAXN];

struct Query {
	int l, r, x;
} Q[MAXN];

namespace ANC {

	int f[MAXN][21];

	void dfs(int u, int fa) {
		for (auto v : G[u]) {
			if (v == fa) continue;
			dep[v] = dep[u] + 1;
			dfs(v, u);
		}
	}

	void init() {
		rep (i, 1, n) f[i][0] = fa[i];
		rep (j, 1, 20) {
			rep (i, 1, n) {
				f[i][j] = f[f[i][j - 1]][j - 1];
			}
		}
		dep[1] = 1;
		dfs(1, 0);
	}

	int kth_anc(int x, int k) {
		int u = x;
		int cnt = 0;
		while (k) {
			if (k & 1) u = f[u][cnt];
			k >>= 1;
			cnt++;
		}
		return u;
	}

	int move(int x, int u) {
		if (dep[x] > dep[u]) return fa[x];
		if (x == u) return x;
		if (kth_anc(u, dep[u] - dep[x]) != x) return fa[x];
		return kth_anc(u, dep[u] - dep[x] - 1);
	}
} // namespace TCS



signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	ignore = freopen("fall.in", "r", stdin);
	ignore = freopen("fall.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), q = read();
	rep (i, 2, n) {
		fa[i] = read();
		G[i].push_back(fa[i]);
		G[fa[i]].push_back(i);
	}
	rep (i, 1, m) a[i] = read();
	rep (i, 1, q) Q[i].l = read(), Q[i].r = read(), Q[i].x = read();
	ANC::init();
	if (q <= 2000) {
		rep (i, 1, q) {
			rep (j, Q[i].l, Q[i].r) {
				Q[i].x = ANC::move(Q[i].x, a[j]);
			}
		}
		rep (i, 1, q) print(Q[i].x), puts("");
	}
	return 0;
}
