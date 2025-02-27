#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
int k, n, a[MAXN];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int fac[MAXN], ifac[MAXN];

void init(int n) {
	fac[0] = 1;
	rep (i, 1, n) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[n] = qpow(fac[n], MOD - 2);
	_rep (i, n - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % MOD;
}

int C(int n, int m) {
	if (n < m) return 0;
	return 1ll * fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
#endif
#endif
	init(1e6);
	n = read(), k = read();
	rep (i, 1, n) a[i] = read();
	int ans = a[1] * C(n - 1, k) % MOD;
	rep (i, 2, n) {
		int dbg = 0;
		_rep (j, i, 2) {
			int dis = i - j + 1;
			if (dis > k) break;
			int sgn = (dis & 1) ? -1 : 1;
			int certain = dis + 1;
			int cnt = C(n - certain - (j > 2), k - dis);
			dbg = (dbg + cnt) % MOD;
			ans = (ans + sgn * ((cnt * a[i]) % MOD)) % MOD;
			ans = (ans + MOD) % MOD;
			// cerr << "i = " << i << " j = " << j << " sgn = " << sgn << " count = " << cnt << " a[i] = " << a[i] << endl;
		}
		ans = (ans + C(n - 2, k) * a[i] % MOD) % MOD;
		// cerr << "i = " << i << " extra = " << C(n - 2, k) << endl;
		dbg = (dbg + C(n - 2, k)) % MOD;
		// cerr << "dbg: " << dbg << " " << C(n - 1, k) << endl;
		assert(dbg == C(n - 1, k));
		// cerr << "dbg = " << dbg << endl;
	}
	print(ans * qpow(C(n - 1, k), MOD - 2) % MOD), puts("");
	return 0;
}
