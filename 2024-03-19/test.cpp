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

int n, k;

const int MAXN = 1e3 + 5;
int MOD;
int fac[MAXN], pre[MAXN], suf[MAXN], f[MAXN][MAXN];

ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

void solve() {
	fac[0] = 1;
	suf[k + 3] = pre[0] = 1;
	rep (i, 1, k + 2) fac[i] = 1ll * fac[i - 1] * i % MOD;
	rep (i, 1, k + 2) pre[i] = 1ll * pre[i - 1] * (n - i) % MOD;
	_rep (i, k + 2, 1) suf[i] = 1ll * suf[i + 1] * (n - i) % MOD;
	ll ans = 0, y = 0;
	rep (i, 1, k + 2) {
		y = (y + f[i][k]) % MOD;
		ll a = 1ll * pre[i - 1] * suf[i + 1] % MOD;
		ll b = fac[i - 1] * ((k - i) & 1 ? -1ll : 1ll) * fac[k + 2 - i] % MOD;
		ans = (ans + 1ll * y * a % MOD * qpow(b, MOD - 2) % MOD) % MOD;
	}
	print((ans + MOD) % MOD), putchar(10);
}


signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("dimension.in", "r", stdin);
	freopen("dimension.out", "w", stdout);
#endif
#endif
	n = read(), k = read(), MOD = read();
	n++;
	rep (i, 1, k + 2) f[i][0] = 1;
	rep (i, 1, k) {
		f[1][i] = 1;
		rep (j, 2, k + 2) f[j][i] = (f[j - 1][i] + f[j - 1][i - 1]) % MOD;
		/* rep (j, 1, k + 2) cout << f[j][i] << " \n"[j == k + 2]; */
	}
	solve();
	return 0;
}
