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

#define int __int128

const int MOD = 1e9 + 7;

int qpow(int a, int b, int p) {
	a %= MOD;
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

int inv(int a) {
	while (a < 0) a += MOD;
	return qpow(a, MOD - 2, MOD);
}

int n, m, q, ans;
signed main() {
#ifdef ONLINE_JUDGE
	freopen("dnspring.in", "r", stdin);
	freopen("dnspring.out", "w", stdout);
#endif
	read(n), read(m), read(q);
	for(int i = 1; i <= n; i++) {
		int p = i * (n - i + 1) % MOD * inv((n + 1) * n / 2 % MOD) % MOD;
		int P = (1 - p * inv(2) % MOD + MOD) % MOD;
		int z = (2 * m % MOD * P % MOD + 1) % MOD * inv(2 * m + 1) % MOD;
		int S = (qpow(z, q, MOD) - 1 + MOD) % MOD * inv(z - 1) % MOD;
		ans = (ans + p * inv(2 * m + 1) % MOD * (m - 1) % MOD * inv(2) % MOD * ((q - S + MOD) % MOD) % MOD) % MOD;
	}
	print(ans * qpow((2 * m + 1) % MOD * n % MOD * (n + 1) % MOD * inv(2) % MOD, q, MOD) % MOD);
	return 0;
}
