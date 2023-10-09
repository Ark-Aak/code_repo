#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

#define int __int128

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 1e7 + 5;
const int MOD = 20101009;
int n, m;

int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = (res * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return res;
}

namespace Mobius {
	vector <int> p;
	bitset <MAXN> vis;
	int mu[MAXN], sum[MAXN];

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

	void Inital(int n) {
		Sieve(n);
		rep (i, 1, n) {
			sum[i] = sum[i - 1] + mu[i] * i % MOD * i % MOD;
			sum[i] %= MOD;
		}
	}
}

using Mobius::mu;
using Mobius::sum;
using Mobius::Inital;

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

signed main() {
	inv = qpow(2, MOD - 2, MOD);
	read(n), read(m);
	Inital(max(n, m));
	int ans = 0;
	for (int l = 1, r; l <= min(n, m); l = r + 1) {
		r = min(n / (n / l), m / (m / l));
		ans += (S(r) - S(l - 1)) % MOD * g(n / l, m / l) % MOD;
		ans %= MOD;
	}
	print((ans + MOD) % MOD);
	return 0; 
}
