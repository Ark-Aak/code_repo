#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

int n, m, k;
const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = (res * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return res;
}

int fac[MAXN], inv[MAXN];

int C(int m, int n) {
	if (n == m || n == 0) return 1;
	return fac[m] * inv[n] % MOD * inv[m - n] % MOD;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("dice.in", "r", stdin);
	freopen("dice.out", "w", stdout);
#endif
#endif
	read(n), read(m), read(k);
	const int INV = qpow(2, MOD - 2, MOD);
	fac[1] = 1; inv[1] = qpow(1, MOD - 2, MOD);
	rep (i, 2, n) fac[i] = fac[i - 1] * i % MOD, inv[i] = qpow(fac[i], MOD - 2, MOD);
	if (n == m) {
		cout << (n * k) % MOD;
		return 0;
	}
	else {
		int ans = 0;
		rep (i, 1, m) ans = (ans + qpow(INV, n - i, MOD) * i % MOD * C(n - i - 1, m - i) % MOD) % MOD;
		cout << ans * k % MOD << endl;
	}
	return 0;
}
