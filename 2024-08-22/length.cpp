#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

#define int ll

using namespace std;

typedef long long ll;
typedef __int128 i128;
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
int n, k;
int fac[MAXN], ifac[MAXN];
bool vis[MAXN];
int pw[MAXN];
vector <int> primes;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % MOD;
		a = 1ll * a * a % MOD;
		b >>= 1;
	}
	return res;
}

const int ppp = 1e7;

signed main() {
	n = read(), k = read();
	fac[0] = 1;
	rep (i, 1, ppp) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[ppp] = qpow(fac[ppp], MOD - 2);
	_rep (i, ppp, 1) ifac[i - 1] = 1ll * ifac[i] * i % MOD;
	pw[1] = 1;
	rep (i, 2, n) {
		if (!vis[i]) {
			primes.push_back(i);
			pw[i] = qpow(i, k % (MOD - 1));
		}
		for (auto j : primes) {
			if (1ll * i * j > n) break;
			vis[i * j] = 1;
			pw[i * j] = 1ll * pw[i] * pw[j] % MOD;
		}
	}
	int res = 0, p = 1;
	_rep (i, n, 1) {
		res = (1ll * res + 1ll * fac[n] * ifac[i] % MOD * ifac[n - i] % MOD * fac[i - 1] % MOD * p % MOD * pw[i] % MOD) % MOD;
		p = 1ll * p * n % MOD;
	}
	print(res), puts("");
	return 0;
}
