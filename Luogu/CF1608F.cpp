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

const int MAXN = 2e3 + 5;
const int MOD = 998244353;
int n, k, a[MAXN], l[MAXN], r[MAXN];
int dp[2][MAXN][MAXN], sum[2][MAXN][MAXN];
int fac[MAXN], ifac[MAXN];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % MOD;
		a = 1ll * a * a % MOD;
		b >>= 1;
	}
	return res;
}

void init(int n) {
	fac[0] = 1;
	rep (i, 1, n) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[n] = qpow(fac[n], MOD - 2);
	_rep (i, n - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % MOD;
}

int A(int n, int m) {
	if (n < m) return 0;
	return 1ll * fac[n] * ifac[n - m] % MOD;
}

signed main() {
	init(2000);
	n = read(), k = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n) l[i] = max(0, a[i] - k);
	rep (i, 1, n) r[i] = min(i, a[i] + k);
	dp[0][0][0] = 1;
	sum[0][0][0] = 1;
	rep (i, 1, n) {
		int ni = (i & 1), pi = ni ^ 1;
		rep (j, 0, i) {
			rep (k, l[i], r[i]) {
				int m = j + k - 1;
				dp[ni][j][k] = (1ll * dp[ni][j][k] + 1ll * (j + k) * dp[pi][j][k]) % MOD;
				if (j) dp[ni][j][k] = (1ll * dp[ni][j][k] + dp[pi][j - 1][k]) % MOD;
				int L = max(j + k - i, l[i - 1]), R = min(k - 1, r[i - 1]);
				if (k && L <= R) {
					ll tmp = sum[pi][m][R];
					if (L) tmp = (1ll * tmp - 1ll * sum[pi][m][L - 1] + MOD) % MOD;
					dp[ni][j][k] = (dp[ni][j][k] + tmp * ifac[j]) % MOD;
				}
				if (j + k <= n) sum[ni][j + k][k] = 1ll * dp[ni][j][k] * fac[j] % MOD;
			}
		}
		rep (j, 0, i + r[i + 1]) {
			if (j > n) break;
			int L = max(j - i, l[i]), R = min(j, r[i]);
			if (L > 0) sum[ni][j][L - 1] = 0;
			rep (k, L, R) if (k) sum[ni][j][k] = (1ll * sum[ni][j][k] + 1ll * sum[ni][j][k - 1]) % MOD;
		}
		rep (j, 0, i - 1) {
			rep (k, l[i - 1], r[i - 1]) dp[pi][j][k] = 0;
		}
	}
	ll ans = 0;
	rep (i, 0, n) {
		rep (k, l[n], r[n]) {
			ans = (ans + 1ll * dp[n & 1][i][k] * A(n - k, i)) % MOD;
		}
	}
	print(ans);
	return 0;
}
