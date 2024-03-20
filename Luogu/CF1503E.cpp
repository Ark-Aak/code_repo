#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

ll read() {
	ll x = 0, f = 1; char c = getchar();
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

int n, m;
const int MOD = 998244353;
const int MAXN = 5e3 + 5;

ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD, b >>= 1;
	}
	return res;
}

int fac[MAXN], ifac[MAXN];

void init_fac(int n) {
	fac[0] = 1;
	rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[n] = qpow(fac[n], MOD - 2);
	_rep(i, n - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % MOD;
}

int C(int n, int m) {
	if (n < m) return 0;
	return 1ll * fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

int sum[MAXN][MAXN], g[MAXN][MAXN];
int pre1[MAXN], pre2[MAXN];

int solve(int n, int m, int flg) {
	rep (i, 1, n) {
		rep (j, 1, m) {
			g[i][j] = 1ll * sum[i - 1][j] * C(n - i + j - 1, n - i) % MOD;
		}
	}
	int res = 0;
	rep (i, 1, m - 1) {
		rep (j, 1, n) pre1[j] = g[j][i], pre2[j] = (g[j][m - i]) % MOD;
		rep (j, 1, n) pre2[j] = (1ll * pre2[j] + pre2[j - 1]) % MOD;
		rep (j, 1, n - flg - 1) res += 1ll * pre1[j] * pre2[n - j - flg] % MOD, res %= MOD;
	}
	res = (res + res) % MOD;
	return res;
}

signed main() {
	n = read(), m = read();
	init_fac(5000);
	rep (i, 1, max(n, m)) {
		sum[0][i] = 1;
		rep (j, 1, max(n, m)) {
			sum[j][i] = (1ll * sum[j - 1][i] + C(j + i - 1, j)) % MOD;
		}
	}
	cout << (1ll * solve(n, m, 0) % MOD + solve(m, n, 1)) % MOD << endl;
	return 0;
}
