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

const int MOD = 1e9 + 7;
const int MAXN = 505 + 5;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % MOD;
		a = 1ll * a * a % MOD;
		b >>= 1;
	}
	return res;
}

int n, m;
int fac[MAXN << 1], ifac[MAXN << 1];

void init(int n) {
	fac[0] = 1;
	rep (i, 1, n) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[n] = qpow(fac[n], MOD - 2);
	_rep (i, n - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % MOD;
}

int C(int n, int m) {
	if (n < m || m < 0) return 0;
	return 1ll * fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

int f[MAXN][MAXN][MAXN]; // 第 i 次操作，上一次 2 操作是 j，k 次 2 操作
int g[MAXN][MAXN][MAXN]; // 方案数

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("battle.in", "r", stdin);
	freopen("battle.out", "w", stdout);
#endif
#endif
	init(1000);
	n = read(), m = read();
	const int M = min(m, n - 1);
	const int N = n + M;
	g[0][0][0] = 1;
	f[0][0][0] = 1;
	const int inv = qpow(qpow(m, n), MOD - 2);
	// cout << "tot:" << qpow(m, n) << endl;
	rep (i, 1, N) {
		rep (k, 0, M) {
			// if (i - k > n) continue;
			rep (j, 0, i - 1) {
				f[i][j][k] = f[i - 1][j][k];
				g[i][j][k] = g[i - 1][j][k];
			}
		}
		rep (k, 0, M - 1) {
			if (i - k - 1 > n) continue;
			rep (j, k * 2, i - 2) {
				int ch = i - j - 1;
				int bb = j - k;
				g[i][i][k + 1] = (1ll * g[i][i][k + 1] + 1ll * C(bb + ch, ch) * g[i - 1][j][k] % MOD) % MOD;
				f[i][i][k + 1] = max(f[i][i][k + 1], max(f[i - 1][j][k], ch));
			}
		}
	}
	int ans = 0;
	rep (i, 1, N) {
		rep (k, 0, M) {
			rep (j, k * 2, i - 1) {
				if (i - k > n) continue;
				int pln = g[i][j][k];
				pln = (1ll * pln * C(N - k - 1, j - k) % MOD * C(m, k + 1)) % MOD;
				ans = (1ll * ans + 1ll * pln * f[i][j][k] % MOD * inv) % MOD;
				// cerr << i << " " << j << " " << k << " = " << f[i][j][k] << " " << pln << endl;
			}
		}
	}
	print(ans), puts("");
	return 0;
}
