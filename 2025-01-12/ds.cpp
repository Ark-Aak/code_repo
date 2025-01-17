#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>
#include <bits/extc++.h>

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

int n, m, P;
int dp[1000005];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % P;
		a = a * a % P;
		b >>= 1;
	}
	return res;
}

__gnu_pbds::cc_hash_table <int, int> mp;

int a[10][10], ans;

int check() {
	int flg = 1;
	rep (i, 1, n) rep (j, 1, m) if (a[i][j] == -1) flg = 0;
	return flg;
}

int encode() {
	int res = 0;
	rep (i, 1, n) rep (j, 1, m) res *= 3, res += a[i][j] + 1;
	return res;
}

void dfs() {
	if (mp[encode()]) return;
	mp[encode()] = 1;
	if (check()) {
		ans++;
		ans %= P;
		return;
	}
	rep (i, 1, n) {
		rep (j, 1, m) {
			if (i < n) {
				if (a[i][j] == -1 && a[i + 1][j] == -1) {
					a[i][j] = 1, a[i + 1][j] = 0;
					dfs();
					a[i][j] = 0, a[i + 1][j] = 1;
					dfs();
					a[i][j] = -1, a[i + 1][j] = -1;
				}
			}
			if (j < m) {
				if (a[i][j] == -1 && a[i][j + 1] == -1) {
					a[i][j] = 1, a[i][j + 1] = 0;
					dfs();
					a[i][j] = 0, a[i][j + 1] = 1;
					dfs();
					a[i][j] = -1, a[i][j + 1] = -1;
				}
			}
		}
	}
}

signed main() {
	memset(a, -1, sizeof a);
	n = read(), m = read(), P = read();
	if ((n * m) & 1) return puts("0"), 0;
	if (n == 1) {
		if (m & 1) return puts("0"), 0;
		else return print(qpow(2, m / 2)), 0;
	}
	else if (n == 2) {
		dp[0] = 1;
		dp[1] = 2;
		rep (i, 2, m) {
			dp[i] = (dp[i - 1] + dp[i - 2]) * 2 % P;
		}
		print(dp[m]), puts("");
	}
	else {
		dfs();
		print(ans), puts("");
	}
	return 0;
}
