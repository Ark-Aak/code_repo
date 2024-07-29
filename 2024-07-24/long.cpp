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

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

#define int ll

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

const int MOD = 998244353;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

const int inv2 = qpow(2, MOD - 2);
const int inv3 = qpow(3, MOD - 2);
const int inv6 = qpow(6, MOD - 2);

int calc(int x) {
	x--;
	return (
		x * x % MOD * x % MOD * inv3 % MOD +
		x * x % MOD * inv2 % MOD +
		x * inv6 % MOD + 1
	) % MOD;
}

int calcRg(int siz, int x, int y) {
	int s = max(x - 1, y - 1);
	int tot = siz * siz % MOD;
	int sum = (1 + tot) * tot % MOD * inv2 % MOD;
	int ts = s;
	s = s * s % MOD;
	sum -= (1 + s) * s % MOD * inv2 % MOD;
	int rx = (x - 1) % MOD;
	int ry = (y - 1) % MOD;
	sum = (sum + MOD) % MOD;
	if (rx) {
		sum -= rx * ((calc(siz) - calc(ts) + MOD) % MOD) % MOD;
		sum %= MOD;
		sum = (sum + MOD) % MOD;
		sum -= (siz - ts) * (1 + rx) % MOD * rx % MOD * inv2 % MOD;
		sum %= MOD;
		sum = (sum + MOD) % MOD;
	}
	if (ry) {
		sum -= ry * ((calc(siz + 1) - calc(ts + 1) + MOD) % MOD) % MOD;
		sum %= MOD;
		sum = (sum + MOD) % MOD;
		sum += (siz - ts) * ry % MOD * (ry - 1) % MOD * inv2 % MOD;
		sum %= MOD;
		sum = (sum + MOD) % MOD;
	}
	return sum;
}

int T;

namespace solution {

int x1, x2, y1, y2;

void solve() {
	x1 = read(), y1 = read(), x2 = read(), y2 = read();
	if (y2 >= x2) {
		int siz = max(max(x1, x2), max(y1, y2));
		print((calcRg(siz, x1, y1) - calcRg(siz, x2 + 1, y1) + MOD) % MOD);
		puts("");
	}
	else {
		int siz = max(max(x1, x2), max(y1, y2));
		print((calcRg(siz, x1, y1) - calcRg(siz, x1, y2 + 1) + MOD) % MOD);
		puts("");
	}
}

} // namespace solution

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	ignore = freopen("long.in", "r", stdin);
	ignore = freopen("long.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) solution::solve();
	return 0;
}
