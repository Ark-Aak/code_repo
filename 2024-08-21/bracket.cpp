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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

string str;
int n;

const int MAXN = 1e6 + 5;
const int MOD = 998244353;
int fac[MAXN], ifac[MAXN];

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
	rep (i, 1, n) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[n] = qpow(fac[n], MOD - 2);
	_rep (i, n - 1, 0) ifac[i] = (1ll * ifac[i + 1] * (i + 1)) % MOD;
}

int C(int n, int m) {
	if (n < 0 || m < 0 || n < m) return 0;
	return 1ll * fac[n] * ifac[n - m] % MOD * ifac[m] % MOD;
}

int l[MAXN], r[MAXN], x[MAXN], y[MAXN];

signed main() {
	init(1e6);
	cin >> str;
	n = str.size();
	str = ' ' + str;
	rep (i, 1, n) l[i] = l[i - 1] + (str[i] == '(');
	_rep (i, n, 1) r[i] = r[i + 1] + (str[i] == ')');
	rep (i, 1, n) x[i] = x[i - 1] + (str[i] == '?');
	_rep (i, n, 1) y[i] = y[i + 1] + (str[i] == '?');
	int ans = 0;
	rep (i, 1, n - 1) {
		ans = (ans + 1ll * l[i] * C(x[i] + y[i + 1], y[i + 1] + r[i + 1] - l[i]) % MOD) % MOD;
		ans = (ans + 1ll * x[i] * C(x[i] + y[i + 1] - 1, y[i + 1] + r[i + 1] - l[i] - 1) % MOD) % MOD;
	}
	print(ans), puts("");
	return 0;
}
