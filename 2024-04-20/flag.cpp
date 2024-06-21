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

const int MAXN = 1005;
int n, m, q;
int a[MAXN][MAXN];

#define id(x, y) (((x) - 1) * m + (y))

int fa[MAXN * MAXN];

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

vector <pii> e[MAXN][MAXN];
int cnt, vis[MAXN * MAXN], c[MAXN][MAXN];
int ans[MAXN][MAXN];

void merge(int l, int r, int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	cnt--;
	if (vis[x] && vis[y]) {
		e[r][l].push_back(dl(vis[x], vis[y]));
		c[l][r]--;
	}
	fa[x] = y;
	if (vis[x]) vis[y] = vis[x];
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("flag.in", "r", stdin);
	freopen("flag.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), q = read();
	rep (i, 1, n) rep (j, 1, m) a[i][j] = read();
	rep (r, 1, m) {
		cnt = n * 2, c[r][r] = n;
		rep (i, 1, n) {
			fa[id(i, r)] = id(i, r), fa[id(i, r - 1)] = id(i, r - 1);
			vis[id(i, r)] = id(i, r);
			if (a[i][r] == a[i - 1][r]) merge(r, r, id(i, r), id(i - 1, r));
		}
		ans[r][r] = c[r][r];
		rep (i, 1, n) {
			if (a[i][r] == a[i][r - 1]) merge(r - 1, r, id(i, r), id(i, r - 1));
		}
		_rep (i, r - 1, 1) {
			c[i][r] = c[i + 1][r];
			for (auto v : e[r - 1][i]) merge(i, r, v.ec, v.fb);
			ans[i][r] = ans[i][r - 1] + cnt - c[i][r - 1];
		}
		rep (i, 1, n) vis[id(i, r)] = vis[id(i, r - 1)] = 0;
	}
	while (q --> 0) {
		int x = read(), y = read();
		print(ans[x][y]), puts("");
	}
	return 0;
}
