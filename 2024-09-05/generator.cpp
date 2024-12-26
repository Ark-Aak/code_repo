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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int get(int l, int r) {
	uniform_int_distribution <int> d(l, r);
	return d(rnd);
}

void solve() {
	mod = get(1, 1e9);
	n = get(300, 300);
	cout << mod << endl << n << endl;
	rep (i, 1, n) rep (j, 1, n) a[i][j] = get(0, mod - 1);
	rep (i, 1, n) rep (j, 1, n) b[i][j] = get(0, mod - 1);
	rep (i, 1, n) {
		rep (j, 1, n) cout << a[i][j] << " ";
		cout << endl;
	}
	rep (i, 1, n) {
		rep (j, 1, n) cout << b[i][j] << " ";
		cout << endl;
	}
	rep (i, 1, n) {
		rep (j, 1, n) {
			expected[i][j] = 0;
			rep (k, 1, n) expected[i][j] = (1ll * expected[i][j] + 1ll * a[i][k] * b[k][j] % mod) % mod;
		}
	}
	int row = get(1, n);
	int sa = get(1, n), sb = get(1, n);
	if (get(0, 1)) swap(expected[row][sa], expected[row][sb]);
	rep (i, 1, n) {
		rep (j, 1, n) cout << expected[i][j] << " ";
		cout << endl;
	}
}

signed main() {
	T = get(1, 1);
	cout << T << endl;
	while (T --> 0) solve();
	return 0;
}
