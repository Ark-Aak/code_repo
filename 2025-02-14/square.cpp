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
#define de(val) cerr << #val << " = " << (val) << endl

#define y1 __ysadkhi2y48124J

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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

int n;
vector <pii> p[3];
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) {
		int x = read(), y = read(), c = read();
		p[c].emplace_back(x, y);
	}
	ll ans = 1e10;
	for (auto [x1, y1] : p[0]) {
		for (auto [x2, y2] : p[1]) {
			for (auto [x3, y3] : p[2]) {
				int minx = min({ x1, x2, x3 });
				int maxx = max({ x1, x2, x3 });
				int miny = min({ y1, y2, y3 });
				int maxy = max({ y1, y2, y3 });
				ans = min(ans, 2ll * (1ll * maxx + maxy - minx - miny));
				if (clock() * 1.0 / CLOCKS_PER_SEC > 2.96) goto pans;
			}
		}
	}
pans:
	print(ans), puts("");
	return 0;
}
