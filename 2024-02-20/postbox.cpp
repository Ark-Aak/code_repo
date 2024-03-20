#include <bits/stdc++.h>

#define int __int128

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

const int MOD = 998244353;
int ans = 0;
int n, m;


int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("postbox.in", "r", stdin);
	freopen("postbox.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	if (m > n) {
		puts("0");
		return 0;
	}
	int ans = qpow(2 * n + 2, m);
	ans *= (1 - m % MOD * qpow(n + 1, MOD - 2) % MOD + MOD) % MOD;
	print(ans % MOD);
}
