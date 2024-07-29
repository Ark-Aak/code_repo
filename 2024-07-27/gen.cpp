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

mt19937 _rnd(time(0));

int rnd(int l, int r) { return abs((int) _rnd()) % (r - l + 1) + l; }
int p[2000000];

signed main() {
	ignore = freopen("test.in", "w", stdout);
	const int n = 7.5e4, m = 1.5e5;
	cout << n << " " << m << endl;
	rep (i, 1, n - 1) p[i] = i;
	shuffle(p + 1, p + n, _rnd);
	rep (i, 1, n - 1) cout << p[i] << " ";
	cout << endl;
	set <pii> s;
	rep (i, 2, n) {
		int fa = rnd(1, i);
		s.insert(dl(fa, i));
	}
	while (s.size() < m) {
		int u = rnd(1, n), v = rnd(1, n);
		if (u == v) continue;
		if (u > v) swap(u, v);
		s.insert(dl(u, v));
	}
	for (auto [u, v] : s) cout << u << " " << v << endl;
	return 0;
}
