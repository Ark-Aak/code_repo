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

int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = (res * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return res;
}

int f[1000005], qz[1000005];
const int MOD = 998244353;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
#endif
#endif
	int n, m;
	cin >> n >> m;
	f[1] = f[2] = m % MOD;
	qz[1] = m % MOD, qz[2] = 2 * m % MOD;
	rep (i, 3, 1e6) f[i] = f[i - 2] * m % MOD, f[i] %= MOD, qz[i] = qz[i - 1] + f[i], qz[i] %= MOD;
	int ans = 0;
	rep (i, 1, n - 1) {
		ans += f[i] * qz[n - i] % MOD;
		ans %= MOD;
	}
	rep (i, 1, n) ans += f[i], ans %= MOD;
	ans %= MOD;
	rep (i, 1, n) ans -= (i - 1) * m % MOD, ans %= MOD;
	print((ans + MOD) % MOD);
	return 0;
}
