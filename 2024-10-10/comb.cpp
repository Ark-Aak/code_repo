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

const int MAXN = 2005;
const int MOD = 1e9 + 7;

int a, b, c, n, q;
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
	rep (i, 1, n) fac[i] = fac[i - 1] * i % MOD;
	ifac[n] = qpow(fac[n], MOD - 2);
	_rep (i, n - 1, 0) ifac[i] = ifac[i + 1] * (i + 1) % MOD;
}

int C(int n, int m) {
	if (n < m) return 0;
	return fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

int pre[MAXN][MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("comb.in", "r", stdin);
	freopen("comb.out", "w", stdout);
#endif
#endif
	init(2000);
	n = read(), q = read();
	rep (c, 1, n) {
		rep (i, 1, c) pre[c][i] = (pre[c][i - 1] + qpow(2, c - i) * i % MOD
				* i % MOD * (c - i) % MOD * C(c, i) % MOD) % MOD;
	}
	while (q --> 0) {
		a = read(), b = read(), c = read();
		print((pre[c][b] - pre[c][a - 1] + MOD) % MOD), puts("");
	}
	return 0;
}
