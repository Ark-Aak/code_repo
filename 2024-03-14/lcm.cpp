#include <bits/stdc++.h>

#define int __int128

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

const int MAXN = 1e7 + 5;
const int MOD = 998244353;
int mu[MAXN];
int sum[MAXN];
bool vis[MAXN];
vector <int> p;
int T, n, k;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

void Sieve(int n) {
	mu[1] = 1;
	rep (i, 2, n) {
		if (!vis[i]) {
			p.emplace_back(i);
			mu[i] = -1;
		}
		for (auto j : p) {
			if (i * j > n) break;
			vis[i * j] = 1;
			if (i % j == 0) {
				mu[i * j] = 0;
				break;
			}
			mu[i * j] = -mu[i];
		}
	}
}

void init(int n) {
	Sieve(n);
	rep (i, 1, n) {
		sum[i] = sum[i - 1] + mu[i] * i % MOD * i % MOD;
		sum[i] %= MOD;
	}
}

int inv;

int S(int n) {
	return n * (n + 1) % MOD * inv % MOD;
}

int f(int n, int m) {
	return S(n) * S(m) % MOD;
}

int g(int n, int m) {
	int ans = 0;
	for (int l = 1, r; l <= min(n, m); l = r + 1) {
		r = min(n / (n / l), m / (m / l));
		ans += (sum[r] - sum[l - 1]) % MOD * f(n / l, m / l) % MOD;
		ans %= MOD;
	}
	return ans;
}

int calc() {
	inv = qpow(2, MOD - 2);
	int ans = 0;
	for (int l = 1, r; l <= n; l = r + 1) {
		r = n / (n / l);
		ans += (S(r) - S(l - 1)) % MOD * g(n / l, n / l) % MOD;
		ans %= MOD;
	}
	return (ans + MOD) % MOD;
}

void solve() {
	n = read();
	if (n <= 1000) {
		int ans = 0;
		rep (i, 1, n) {
			rep (j, 1, n) {
				ans += qpow(i * j / __gcd(i, j), k);
				ans %= MOD;
			}
		}
		print(ans);
	}
	else {
		if (k == 1) print(calc());
	}
	/*
	int ans = 0;
	rep (d, 1, n) {
		rep (d2, 1, n / d) {
			int tans = 0;
			int sum = mu[d2];
			rep (i, 1, n / d / d2) {
				rep (j, 1, n / d / d2) {
					tans += qpow(i * j * d * d2 * d2, k);
				}
			}
			sum *= tans;
			ans += sum;
		}
	}
	print(ans);
	*/
	puts("");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("lcm.in", "r", stdin);
	freopen("lcm.out", "w", stdout);
#endif
#endif
	init(1e7);
	T = read(), k = read();
	while (T --> 0) solve();
	return 0;
}
