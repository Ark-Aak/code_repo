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

const int MOD = 998244353;
const int MAXN = 1e7 + 5;
int n, k;
int f[MAXN];
int fac[MAXN], ifac[MAXN];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

void init(int n) {
	fac[0] = 1;
	rep (i, 1, n) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[n] = qpow(fac[n], MOD - 2);
	_rep (i, n - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % MOD;
}

int A(int n, int m) {
	if (n < m || m < 0) return 0;
	return 1ll * fac[n] * ifac[n - m] % MOD;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
#endif
#endif
	init(1e7);
	n = read(), k = read();
	// if (k == 1) return puts("1"), 0;
	f[n] = 1;
	int pre = 1;
	_rep (i, n - 1, 0) {
		// rep (j, i + 1, min(n, i + k)) {
			// f[i] = (f[i] + f[j] * A(n - i - 1, j - i - 1) % MOD) % MOD;
			// cout << "de:" << j << " " << f[j] << " " << A(n - i - 1, j - i - 1) << endl;
		// }
		f[i] = (f[i] + pre) % MOD;
		pre = (pre * (n - i)) % MOD;
		pre = (pre + f[i]) % MOD;
		if (i + k <= n) {
			pre = (pre - f[i + k] * A(n - i, k) % MOD) % MOD;
			pre = (pre + MOD) % MOD;
		}
	}
	// rep (i, 0, n) cout << f[i] << " ";
	// cout << endl;
	print(f[0]), puts("");
	return 0;
}
