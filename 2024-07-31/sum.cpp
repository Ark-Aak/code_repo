#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep (i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define ec first
#define fb second
#define de(x) cerr << #x << " = " << (x) << endl

#define int ll

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, w = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + (ch ^ 48);
		ch = getchar();
	}
	return x * w;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

int n, m;
int f[405][405];

signed main() {
#ifndef LOCAL
	ignore = freopen("sum.in", "r", stdin);
	ignore = freopen("sum.out", "w", stdout);
#endif
	n = read(), m = read();
	const int MOD = read();
	int sum0 = 1, sum1 = 1;
	rep (i, n - m + 1, n + m - 1) {
		sum0 = sum0 * i % MOD;
	}
	auto qpow = [&](int a, int b) {
		int res = 1;
		while (b) {
			if (b & 1) res = res * a % MOD;
			a = a * a % MOD;
			b >>= 1;
		}
		return res;
	};
	rep (i, 1, 2 * m - 1) {
		sum1 = sum1 * i % MOD;
	}
	print(sum0 * qpow(sum1, MOD - 2) % MOD), puts("");
	return 0;
}
