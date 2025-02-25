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
int a[MAXN][MAXN];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int n, m;

int det() {
	int det = 1;
	rep (i, 0, n - 1) {
		int k = i;
		rep (j, i + 1, n - 1) {
			if (a[j][i] > a[k][i]) k = j;
		}
		if (!a[k][i]) {
			det = 0;
			break;
		}
		swap(a[i], a[k]);
		if (i != k) det = MOD - det;
		det *= a[i][i];
		det %= MOD;
		rep (j, i + 1, n - 1) a[i][j] = a[i][j] * qpow(a[i][i], MOD - 2) % MOD;
		rep (j, 0, n - 1) {
			if (j != i && a[j][i]) {
				rep (k, i + 1, n) {
					a[j][k] -= a[i][k] * a[j][i] % MOD;
					a[j][k] = (a[j][k] + MOD) % MOD;
				}
			}
		}
	}
	return det;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("det.in", "r", stdin);
	freopen("det.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	while (m --> 0) {
		int x = read(), y = read();
		x--, y--;
		rep (i, x, y) rep (j, x, y) a[i][j]++;
	}
	print(det()), puts("");
	return 0;
}
