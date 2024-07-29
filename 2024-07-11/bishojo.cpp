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

const int MAXN = 3e3 + 5;
int T;
int n, m;
int f[MAXN << 1][MAXN];
int A[MAXN], B[MAXN];
const int INF = 1e18;

void solve() {
	n = read(), m = read();
	rep (i, 1, n) A[i] = read();
	rep (i, 1, m) B[i] = read();
	const int N = n + m;
	memset(f, 0, sizeof f);
	rep (i, 1, N) {
		rep (j, 0, n) {
			if (i & 1) f[i][j] = -1e18;
			else f[i][j] = 1e18;
		}
	}
	f[N][n - 1] = ((N & 1) ? A[n] : -A[n]);
	f[N][n] = ((N & 1) ? B[m] : -B[m]);
	_rep (i, N - 1, 1) {
		rep (a, 0, min(i - 1, n)) {
			const int b = i - 1 - a;
			if (b > m) continue;
			if (i & 1) {
				f[i][a] = max((b == m ? -INF: f[i + 1][a] + B[b + 1]), f[i][a]);
				f[i][a] = max((a == n ? -INF: f[i + 1][a + 1] + A[a + 1]), f[i][a]);
			}
			else {
				f[i][a] = min((b == m ? INF: f[i + 1][a] - B[b + 1]), f[i][a]);
				f[i][a] = min((a == n ? INF: f[i + 1][a + 1] - A[a + 1]), f[i][a]);
			}
		}
	}
	print(f[1][0]), puts("");
}

signed main() {
#ifndef LOCAL
	ignore = freopen("bishojo.in", "r", stdin);
	ignore = freopen("bishojo.out", "w", stdout);
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
