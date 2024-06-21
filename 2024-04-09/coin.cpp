#include <bits/stdc++.h>

/* #define int ll */

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

const int MAXN = 5.5e5 + 5;
const int MOD = 998244353;
int n, m, vis[MAXN], sum[900][MAXN];
int pre[MAXN], pos[MAXN], inv[MAXN];
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

inline void init(int n) {
	fac[0] = 1;
	rep (i, 1, n) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[n] = qpow(fac[n], MOD - 2);
	_rep (i, n - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % MOD;
}

inline int C(int n, int m) {
	if (n < m) return 0;
	return 1ll * fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

int ans = 0;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("coin.in", "r", stdin);
	freopen("coin.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	init(5e5);
	rep (i, 0, n << 1) inv[i] = qpow(qpow(2, MOD - 2), i);
	rep (i, 0, n << 1) pre[i] = (i > 0 ? pre[i - 1] + 1ll * C(i, n - 1) * inv[i] % MOD : 1ll * C(i, n - 1) * inv[i] % MOD) % MOD;
	int cnt = 0;
	rep (_, 1, m) {
		ans = 0;
		int K = read();
		if (!vis[K]) {
			vis[K] = ++cnt;
			rep (i, 0, n << 1) sum[cnt][i] = ((i > 0 ? sum[cnt][i - 1] : 0) + 1ll * C(i - K - 1, n - K - 1) * inv[i] % MOD) % MOD;
		}
		int ch = vis[K];
		rep (i, 1, K) pos[i] = read();
		pos[K + 1] = 2 * n + 1;
		if (pos[K] < 2 * n) ans = (ans + ((sum[ch][2 * n - 1] - sum[ch][pos[K]]) % MOD + MOD) % MOD) % MOD;
		rep (i, 0, K) {
			if (pos[i + 1] - pos[i] > 1) {
				int lp = (pos[i] + 1) - i - 1, rp = min(2 * n - i - 2, pos[i + 1] - 2 - i);
				if (lp <= rp) ans = (ans + (1ll * ((pre[rp] - pre[lp - 1]) % MOD + MOD) % MOD * inv[pos[i] + 1 - lp] % MOD) % MOD) % MOD;
			}
			if (i == K && pos[i] != 2 * n) ans = (ans + 1ll * C(pos[i] - i, n - i) * inv[pos[i]] % MOD) % MOD;
		}
		/* print(), puts(""); */
		print((2ll * ans % MOD + MOD) % MOD), puts("");
	}
	return 0;
}
