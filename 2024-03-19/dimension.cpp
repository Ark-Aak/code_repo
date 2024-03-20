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

int n, k, p;

const int MAXN = 5e7 + 5;
int fac[MAXN], ifac[MAXN];

ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

void init_fac(int n) {
	fac[0] = 1;
	rep (i, 1, n) fac[i] = fac[i - 1] * i % p;
	ifac[n] = qpow(fac[n], p - 2);
	_rep (i, n - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % p;
}

int C(int n, int m) {
	if (n < m) return 0;
	return fac[n] * ifac[m] % p * ifac[n - m] % p;
}

int Lucas(int n, int m) {
	if (!m) return 1;
	return C(n % p, m % p) * Lucas(n / p, m / p) % p;
}

int lucas(int n, int m) {
	m = min(n, m);
	if (m < 0) return 0;
	int res = 0;
	if (n >= p && m >= p) {
		rep (i, 0, p - 1) res += C(n % p, i), res %= p;
		res *= lucas(n / p, m / p - 1); res %= p;
	}
	int tr = 0;
	rep (i, 0, m % p) tr += C(n % p, i), tr %= p;
	tr *= Lucas(n / p, m / p);
	tr %= p;
	return (res + tr) % p;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("dimension.in", "r", stdin);
	freopen("dimension.out", "w", stdout);
#endif
#endif
	n = read(), k = read(), p = read();
	init_fac(p - 1);
	print((lucas(n + 1, k + 1) + p - 1) % p);
	return 0;
}
