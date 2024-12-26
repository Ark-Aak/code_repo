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

const int MAXN = 505;
const int MOD = 998244353;
int n, m;
int a[MAXN], pos[MAXN], f[MAXN][MAXN][MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, m) a[i] = read();
	rep (i, 1, m) pos[a[i]] = i;
	if (!pos[0]) rep (i, 1, m + 1) f[i][i][0] = 1;
	else f[pos[0]][pos[0] + 1][0] = 1;
	rep (i, 1, n - 1) {
		if (!pos[i]) {
			rep (r, 1, m + 1) {
				int res = 0;
				_rep (l, r, 1) {
					res = (res + f[l][r][i - 1]) % MOD;
					f[l][r][i] = (f[l][r][i] + res) % MOD;
				}
			}
			rep (l, 1, m + 1) {
				int res = 0;
				rep (r, l, m + 1) {
					res = (res + f[l][r][i - 1]) % MOD;
					f[l][r][i] = (f[l][r][i] + res) % MOD;
				}
			}
		}
		else {
			rep (l, 1, m + 1) {
				rep (r, l, m + 1) {
					int res = f[min(pos[i], l)][max(pos[i] + 1, r)][i] + f[l][r][i - 1];
					f[min(pos[i], l)][max(pos[i] + 1, r)][i] = res % MOD;
				}
			}
		}
	}
	print(f[1][m + 1][n - 1]), puts("");
	return 0;
}
