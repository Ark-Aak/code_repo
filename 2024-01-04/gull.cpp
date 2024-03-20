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

const int MAXN = 5e3 + 5;
int T, n, m, k, s[MAXN], now;

int qpow(int a, int b, int p) {
	int res = 1;
	for (a %= p; b; b >>= 1, a = a * a % p)
		if (b & 1) res = res * a % p;
	return res;
}

const int MOD = 998244353;

struct val {
	int fac_n, fac_m, inv, n, m, k, id, ans;
} q[MAXN];

void init() {
	int sum = 1, now = 1;
	sort(q + 1, q + T + 1, [](val a, val b) { return a.n < b.n; });
	rep (i, 1, 1e7 + 5e3) {
		sum = sum * i % MOD;
		while (now <= T && q[now].n == i) {
			q[now].fac_n = sum;
			now++;
		}
	}
	now = 1;
	sum = 1;
	sort(q + 1, q + T + 1, [](val a, val b) { return a.m < b.m; });
	while (now <= T && q[now].m - 1 == 0) q[now++].fac_m = sum;
	rep (i, 1, 1e7 + 5e3) {
		sum = sum * i % MOD;
		while (now <= T && q[now].m - 1 == i) {
			q[now].fac_m = sum;
			now++;
		}
	}
	sort(q + 1, q + T + 1, [](val a, val b) { return a.m + a.k > b.m + b.k; });
	sum = (int) (1e7 + 5e3 + 1) * sum % MOD;
	now = 1, sum = qpow(sum, MOD - 2, MOD);
	_rep (i, 1e7 + 5e3, 0) {
		sum = (i + 1) % MOD * sum % MOD;
		while (now <= T && q[now].m + q[now].k == i) {
			q[now].inv = sum;
			now++;
		}
	}
}

int inv[MAXN];

int solve(int n, int m, int k, int s1, int s2, int s3) {
	if (k == 0) return 1;
	int S1 = qpow(s1, MOD - 2, MOD);
	inv[k] = s3;
	_rep (i, k - 1, 0) inv[i] = inv[i + 1] * (m + i + 1) % MOD;
	int ans = 0;
	rep (i, 0, k) {
		if ((k - i) & 1) ans = (ans + MOD - s[i] * inv[i] % MOD * s1 % MOD * s2 % MOD) % MOD;
		else ans = (ans + s[i] * inv[i] % MOD * s1 % MOD * s2 % MOD) % MOD;
		s1 = s1 * (n + i + 1) % MOD;
		s2 = s2 * (m + i) % MOD;
	}
	return S1 * m % MOD * ans % MOD;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("gull.in", "r", stdin);
	freopen("gull.out", "w", stdout);
#endif
#endif
	s[0] = 1;
	T = read();
	rep (i, 1, T) {
		q[i].n = read(), q[i].m = read(), q[i].k = read();
		q[i].id = i;
	}
	init();
	sort(q + 1, q + T + 1, [](val a, val b) { return a.k < b.k; });
	rep (i, 1, T) {
		while (now < q[i].k) {
			now++;
			_rep (i, now, 1) s[i] = (s[i] * i % MOD + s[i - 1]) % MOD;
			s[0] = 0;
		}
		q[i].ans = solve(q[i].n, q[i].m, q[i].k, q[i].fac_n, q[i].fac_m, q[i].inv);
	}
	sort(q + 1, q + T + 1, [](val a, val b) { return a.id < b.id; });
	rep (i, 1, T) print(q[i].ans), putchar(10);
	return 0;
}
