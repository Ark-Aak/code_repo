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

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
int n, k;
int fac[MAXN], pre[MAXN], suf[MAXN];

ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

signed main() {
	n = read(), k = read();
	fac[0] = 1;
	suf[k + 3] = pre[0] = 1;
	rep (i, 1, k + 2) fac[i] = 1ll * fac[i - 1] * i % MOD;
	rep (i, 1, k + 2) pre[i] = 1ll * pre[i - 1] * (n - i) % MOD;
	_rep (i, k + 2, 1) suf[i] = 1ll * suf[i + 1] * (n - i) % MOD;
	ll ans = 0, y = 0;
	rep (i, 1, k + 2) {
		y = (y + qpow(i, k)) % MOD;
		ll a = 1ll * pre[i - 1] * suf[i + 1] % MOD;
		/* cout << pre[i - 1] << " " << suf[i + 1] << endl; */
		ll b = fac[i - 1] * ((k - i) & 1 ? -1ll : 1ll) * fac[k + 2 - i] % MOD;
		/* cout << y << " " << a << " " << b << endl; */
		/* cout << b << " " << qpow(b, MOD - 2) << endl; */
		ans = (ans + 1ll * y * a % MOD * qpow(b, MOD - 2) % MOD) % MOD;
	}
	print((ans + MOD) % MOD), putchar(10);
	return 0;
}
