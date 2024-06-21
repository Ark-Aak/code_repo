#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <immintrin.h>
#include <emmintrin.h>
#include <bits/stdc++.h>

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

const int MAXN = 1e5 + 5;
const int MOD = 998244353;
int ans = 0, fac[MAXN], ifac[MAXN];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % MOD;
		a = 1ll * a * a % MOD;
		b >>= 1;
	}
	return res;
}

void init(int n) {
	fac[0] = 1;
	rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[n] = qpow(fac[n], MOD - 2);
	_rep(i, n - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % MOD;
}

int C(int n, int m) {
	if (n < m) return 0;
	return 1ll * fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

int n, a[MAXN];
bitset <30000> vis;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
#endif
#endif
	n = read();
	if (n == 1) return puts("0"), 0;
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n) vis[a[i]] = 1;
	init(1e5);
	int res = 0;
	rep (i, 0, n) {
		if (i > 1) ans = (1ll * ans + 1ll * C(n, i) * res % MOD) % MOD;
		res = (1ll * res + C(n, i)) % MOD;
	}
	rep (i, 1, a[n]) {
		bitset <30000> tmp = vis;
		for (int j = i; j <= a[n]; j += i) {
			if (!vis[j] || !tmp.count()) break;
			tmp &= (tmp << i);
			ans = (ans - tmp.count() + MOD) % MOD;
		}
	}
	rep (i, 1, a[n]) {
		int presum = 0, sufsum = 0;
		int cnt = 0, flg = 1;
		for (int j = i; j <= a[n]; j += i) {
			if (!vis[j]) flg = 0, sufsum = 0;
			else presum += flg, sufsum++, cnt++;
			if (!vis[j + i] || !vis[j]) continue;
			ans = (ans - 1ll * C(2 * cnt - 1, cnt - 1) % MOD + MOD) % MOD;
			ans = (ans + 1ll * C(2 * cnt - 1, cnt - 2) % MOD) % MOD;
			ans = (ans + min(presum, sufsum)) % MOD;
		}
	}
	print((ans + MOD) % MOD);
	return 0;
}
