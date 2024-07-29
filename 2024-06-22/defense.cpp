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
int n, m;
int x[MAXN], y[MAXN];
int a[MAXN], e[105][105];
vector <int> G[MAXN];
map <pii, int> val;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	ignore = freopen("defense.in", "r", stdin);
	ignore = freopen("defense.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, n) x[i] = read(), y[i] = read();
	if (m == n - 1) {
		rep (i, 1, m) {
			int u = read(), v = read();
			G[u].push_back(v);
			G[v].push_back(u);
			a[i] = read();
			val[dl(u, v)] = val[dl(v, u)] = a[i];
		}
		int mx = 0;
		rep (i, 1, n) {
			for (auto v : G[i]) mx = max(val[dl(i, v)], mx);
		}
		print(mx), puts("");
		return 0;
	}
	rep (i, 1, m) {
		int u = read(), v = read();
		e[u][v] = e[v][u] = i;
		a[i] = read();
	}
	ll maxp = 0;
	rep (i, 0, (1 << n) - 1) {
		vector <int> ch;
		rep (j, 1, n) if (i >> (j - 1) & 1) ch.push_back(j);
		ll p = 0, cnt = 0;
		for (auto a : ch) {
			for (auto b : ch) {
				if (a >= b) continue;
				if (e[a][b]) p += ::a[e[a][b]];
				else cnt++;
			}
		}
		p -= 1000000ll * cnt * cnt;
		maxp = max(maxp, p);
	}
	print(maxp);
	return 0;
}
