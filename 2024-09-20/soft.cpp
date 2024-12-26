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

const int MAXN = 200005;
const int MOD = 998244353;
vector <int> G[MAXN];
int n, k, fac[MAXN], ifac[MAXN];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % MOD;
		a = 1ll * a * a % MOD;
		b >>= 1;
	}
	return res;
}

void init() {
	fac[0] = 1;
	rep (i, 1, 2e5) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[200000] = qpow(fac[200000], MOD - 2);
	_rep (i, 2e5 - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % MOD;
}

int C(int n, int m) {
	if (n < m || m < 0) return 0;
	return 1ll * fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

int fl[105][105];
bool vis[105];

void check(int u, int l, int r) {
	if (!(l <= u && u <= r)) return;
	vis[u] = 1;
	for (auto v : G[u]) {
		if (!vis[v]) check(v, l, r);
	}
}

int f[105][105];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("soft.in", "r", stdin);
	freopen("soft.out", "w", stdout);
#endif
#endif
	init();
	n = read(), k = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	if (n > 100) {
		rep (i, 1, k) print(C(n - 1, i - 1)), puts("");
		return 0;
	}
	rep (l, 1, n) {
		rep (r, l, n) {
			memset(vis, 0, sizeof vis);
			check(l, l, r);
			bool flg = 1;
			rep (i, l, r) flg &= vis[i];
			fl[l][r] = flg;
		}
	}
	f[0][0] = 1;
	rep (i, 1, n) {
		rep (j, 0, i - 1) {
			rep (l, 1, k) {
				// 考虑到前 i 个，最后的区间右端点是 j，在分第 l 个区间，i 必选
				if (fl[j + 1][i]) {
					f[i][l] = (f[i][l] + f[j][l - 1]) % MOD;
				}
				else f[j][l] = 0;
			}
		}
	}
	rep (i, 1, k) {
		print(f[n][i]), puts("");
	}
	return 0;
}