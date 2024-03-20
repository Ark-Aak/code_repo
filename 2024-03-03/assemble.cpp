#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

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

const int MAXN = 1e5 + 5;
const int MOD = 998244353;
int n, m, x[MAXN], y[MAXN];
int ans;

int qpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = a * a % MOD)
		if (b & 1) res = res * a % MOD;
	return res;
}

int ifac[MAXN], fac[MAXN];

void init(int n) {
	fac[0] = 1;
	rep (i, 1, n) fac[i] = fac[i - 1] * i % MOD;
	ifac[n] = qpow(fac[n], MOD - 2);
	_rep (i, n, 1) ifac[i - 1] = ifac[i] * (i) % MOD;
}

int C(int n, int m) {
	if (n < m || m < 0) return 0;
	return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

int c[MAXN];

int solve(int *a) {
	int ans = 0;
	sort(a + 1, a + n + 1);
	if (a[n] - a[1] > 2 * m) return 0;
	rep (i, 2, n) if ((a[i] - a[1]) & 1) return 0;
	for (int i = a[n] - m; i <= a[1] + m; i += 2) {
		int res = 1;
		rep (j, 1, n) {
			int d = abs(a[j] - i);
			res = (res * c[(m - d) / 2]) % MOD;
		}
		ans = (ans + res) % MOD;
	}
	return ans;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("assemble.in", "r", stdin);
	freopen("assemble.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	init(m);
	rep (i, 1, n) {
		x[i] = read(), y[i] = read();
		tie(x[i], y[i]) = make_pair(x[i] + y[i], x[i] - y[i]);
	}
	rep (i, 0, m) c[i] = fac[m] * ifac[i] % MOD * ifac[m - i] % MOD;
	ans = solve(x) * solve(y) % MOD;
	print(ans);
	return 0;
}
