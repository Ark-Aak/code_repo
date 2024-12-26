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

const int MAXN = 1e6 + 5;
const int MOD = 3;
int n, a[MAXN];
int f[MAXN][MOD][MOD];
int pre[MOD][MOD];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) a[i] = read() % MOD;
	f[1][0][a[1]] = pre[0][a[1]] = 1;
	rep (i, 2, n) {
		rep (k1, 0, 2) {
			rep (k2, 0, 2) {
				int nxt1 = (a[i] - k2 + MOD) % MOD;
				if (nxt1 < k1) continue;
				int nxt2 = a[i];
				f[i][nxt1][nxt2] = max(f[i][nxt1][nxt2], pre[k1][k2] + 1);
			}
		}
		rep (k1, 0, 2) {
			rep (k2, 0, 2) {
				pre[k1][k2] = max(pre[k1][k2], f[i][k1][k2]);
			}
		}
	}
	int ans = 0;
	rep (i, 0, 2) rep (j, 0, 2) ans = max(ans, pre[i][j]);
	print(ans), puts("");
	return 0;
}
