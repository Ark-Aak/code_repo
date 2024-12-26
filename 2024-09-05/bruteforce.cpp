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

const int MAXN = 305;
int T, mod, n, a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];
int expected[MAXN][MAXN];

void solve() {
	mod = read();
	n = read();
	rep (i, 1, n) rep (j, 1, n) a[i][j] = read();
	rep (i, 1, n) rep (j, 1, n) b[i][j] = read();
	rep (i, 1, n) rep (j, 1, n) c[i][j] = read();
	rep (i, 1, n) {
		rep (j, 1, n) {
			expected[i][j] = 0;
			rep (k, 1, n) expected[i][j] = (1ll * expected[i][j] + 1ll * a[i][k] * b[k][j] % mod) % mod;
		}
	}
	bool flg = 1;
	rep (i, 1, n) rep (j, 1, n) {
		flg &= expected[i][j] == c[i][j];
	}
	if (flg) puts("Yes");
	else puts("No");
}

signed main() {
	T = read();
	while (T --> 0) solve();
	return 0;
}
