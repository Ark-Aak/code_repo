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

mt19937 _rnd(time(0));
int rnd(int l, int r) {
	return abs((int) _rnd()) % (r - l + 1) + l;
}

signed main() {
	freopen("flag3.in", "w", stdout);
	const int n = 1e3, m = 1e3, q = 2e5;
	print(n), putchar(32), print(m), putchar(32), print(q), puts("");
	rep (i, 1, n) {
		rep (j, 1, m) print(1), putchar(32);
		puts("");
	}
	rep (i, 1, q) {
		int L = rnd(1, m), R = rnd(1, m);
		if (L > R) swap(L, R);
		print(L), putchar(32), print(R);
		puts("");
	}
	freopen("flag3.ans", "w", stdout);
	rep (i, 1, q) print(1), puts("");
	return 0;
}
