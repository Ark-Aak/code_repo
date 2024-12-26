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

const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
int m, q, lst = 0, ans;
// int dp[MAXN][505][2];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % MOD;
		a = 1ll * a * a % MOD;
		b >>= 1;
	}
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
#endif
#endif
	m = read(), q = read();
	rep (i, 1, q) {
		int n = read();
		if ((n <= 10 && m <= 10)) {
			int ff[20];
			rep (i, 1, n) ff[i] = i;
			do {
				int st[20];
				rep (i, 1, n) st[i] = 1;
				int cnt = 1;
				bool flg = 1;
				rep (i, 1, n) {
					if (st[ff[i] - 1] == 1 && st[ff[i] + 1] == 1) cnt++;
					if (st[ff[i] - 1] == 0 && st[ff[i] + 1] == 0) cnt--;
					if (cnt > m) flg = 0;
					st[ff[i]] = 0;
				}
				ans = (ans + flg) % MOD;
			} while(next_permutation(ff + 1, ff + 1 + n));
			print(ans), puts("");
		}
		else if (m == 1) {
			print(qpow(2, n - 1)), puts("");
		}
		else if (m == 2) {
			int ans = 0;
			rep (i, 2, n - 1) {
				ans = ans + (qpow(2, i - 1 - 1) * qpow(2, n - i - 1) % MOD * m % MOD);
				ans %= MOD;
			}
			print(ans), puts("");
		}
	}
	/*
	dp[0][1][0] = 1;
	rep (i, 1, q) {
		int n = read();
		if (n > lst) {
			rep (i, lst + 1, n) {
				rep (j, 1, m) {
					dp[i][j][1] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
					dp[i][j][0] = (dp[i - 1][j][0]);
					if (j > 1) dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j - 1][1]) % MOD;
				}
			}
			lst = n;
		}
		int ans = 0;
		rep (i, 1, m) {
			ans = (ans + dp[n][i][0]) % MOD;
			ans = (ans + dp[n][i][1]) % MOD;
		}
		print(ans), puts("");
	}
	*/
	return 0;
}
