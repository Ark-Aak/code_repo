#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define int ll

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

const int MAXN = 505;
const int MOD = 1e9 + 7;
int n, k, tp;

namespace subtask1 {

	int f[MAXN][MAXN];

	void solve() {
		f[1][0] = 1;
		rep (i, 2, n) {
			rep (j, 0, i - 2) {
				int tp = f[i - 1][j];
				f[i][j] = (f[i][j] + tp) % MOD;
				f[i][j + 1] = (f[i][j + 1] + tp * (i - 1) % MOD) % MOD;
			}
		}
		print(f[n][k]), puts("");
	}
} // namespace subtask1

namespace subtask2 {

	int fac[MAXN], ifac[MAXN];
	int sum[MAXN][MAXN], f[MAXN][MAXN];

	int qpow(int a, int b) {
		int res = 1;
		while (b) {
			if (b & 1) res = res * a % MOD;
			a = a * a % MOD;
			b >>= 1;
		}
		return res;
	}

	void init() {
		fac[0] = 1;
		rep (i, 1, n) fac[i] = fac[i - 1] * i % MOD;
		ifac[n] = qpow(fac[n], MOD - 2);
		_rep (i, n - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % MOD;
	}

	int C(int n, int m) {
		if (n < m) return 0;
		return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
	}

	void solve() {
		init();
		f[0][0] = f[1][1] = sum[0][0] = 1;
		rep (i, 1, n) sum[0][i] = sum[1][i] = 1;
		rep (i, 2, n) {
			rep (j, 0, i - 1) {
				rep (k, 1, i) sum[i][k] = (sum[i][k] + C(i - 1, j) * sum[j][k - 1] % MOD * sum[i - j - 1][k]) % MOD;
			}
			rep (j, i + 1, n) sum[i][j] = sum[i][j - 1];
			rep (j, 1, i) f[i][j] = sum[i][j] - sum[i][j - 1];
		}
		if (n - k - 1 < 0) puts("0");
		else print((f[n - 1][n - k - 1] + MOD) % MOD), puts("");
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("bubble.in", "r", stdin);
	freopen("bubble.out", "w", stdout);
#endif
#endif
	n = read(), k = read(), tp = read();
	if (tp == 1) return subtask1::solve(), 0;
	subtask2::solve();
	return 0;
}
