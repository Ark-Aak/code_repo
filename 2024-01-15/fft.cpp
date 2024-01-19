#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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
const int MOD = 998244353;

int T, n, m, k;
int ans = 0, minn = 1e9;
int fac[MAXN], f[MAXN], g[MAXN];

int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % p;
		a = 1ll * a * a % p;
		b >>= 1;
	}
	return res;
}

#define inv(x) qpow(x, MOD - 2, MOD)

int F(int n, int m, int k) {
	f[0] = 1;
	rep (i, 1, k) f[i] = f[i - 1] * (m + i) % MOD;
	g[k] = inv(f[k]);
	_rep (i, k, 1) g[i - 1] = g[i] * (m + i) % MOD;
	int resa = 1, resb = 1;
	rep (i, 1, k) {
		if (i <= n) resa = 1ll * resa * fac[i - 1] % MOD;
		else resa = 1ll * resa * f[i - 1] % MOD * fac[i - n - 1] % MOD * g[i - n - 1] % MOD;
	}
	rep (i, 1, k) resb = 1ll * resb * fac[i - 1] % MOD;
	cout << resa << " ? " << resb << endl;
	return 1ll * resa * inv(resb) % MOD;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("fft.in", "r", stdin);
	freopen("fft.out", "w", stdout);
#endif
#endif
	T = read();
	fac[0] = 1;
	rep (i, 1, 1e6) fac[i] = fac[i - 1] * i % MOD;
	while (T --> 0) {
		int n = read(), m = read(), k = read();
		int p = n % m;
		if (p <= m - k) print(F(k, n / m, m - p)), putchar(10);
		else print(F(k - m + p, n / m + 1, p)), putchar(10);
	}
	return 0;
}
