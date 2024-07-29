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

const int MAXN = 2e5 + 5;
int n, q;
int a[MAXN];

namespace subtask1 {

	void solve() {
		while (q --> 0) {
			int x = read(), l = read(), r = read();
			rep (i, l, r) x = max(x, a[i] - x);
			print(x), puts("");
		}
	}
} // namespace subtask1

namespace subtask2 {

	void solve() {

	}
}

signed main() {
#ifndef LOCAL
	ignore = freopen("optimization.in", "r", stdin);
	ignore = freopen("optimization.out", "w", stdout);
#endif
	n = read(), q = read();
	rep (i, 1, n) a[i] = read();
	if (n <= 1000 && q <= 1000) {
		return subtask1::solve(), 0;
	}
	else subtask2::solve();
	return 0;
}
