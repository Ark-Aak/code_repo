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

int n, q, z, a[40], sum[40];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("cry.in", "r", stdin);
	freopen("cry.out", "w", stdout);
#endif
#endif
	n = read(), q = read();
	rep (i, 0, 2 * n) a[i] = i + 1;
	do {
		bool flg = 0;
		rep (i, 0, n - 1) {
			if (a[i * 2 + 1] >= a[i * 2 + 2]) {
				flg = 1;
				break;
			}
		}
		if (flg) continue;
		int x = a[0];
		for (int i = 0; i < n; i++) {
			int u = a[i * 2 + 1], v = a[i * 2 + 2];
			x = max(x, u);
			x = min(x, v);
		}
		sum[x]++;
	} while (next_permutation(a, a + 2 * n + 1));
	rep (i, 1, q) {
		int id = read();
		print(sum[id + 1]), putchar(32);
	}
	return 0;
}
