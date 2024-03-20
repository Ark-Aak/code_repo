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

const int MOD = 998244353;

int n, k, l;

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
	n = read(), k = read(), l = read();
	if (n <= k) {
		print(qpow(l, n));
		return 0;
	}
	if (l < n - k - 1) {
		puts("0");
		return 0;
	}
	int ans = 1;
	rep (i, 1, n - k + 1) {
		ans *= (l - i + 1);
		ans %= MOD;
	}
	rep (i, n - k + 2, n) {
		ans *= l - (n - k);
		ans %= MOD;
	}
	print(ans);
	return 0;
}
