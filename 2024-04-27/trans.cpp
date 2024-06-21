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

const int MAXN = 7;
const int MOD = 998244353;
int n;
int a[MAXN], b[MAXN];
int f[205][205][205];

int dfs(int A, int B, int C) {
	if (A < a[1] || B < a[2] || C < a[3]) return 0;
	if (f[A][B][C] != -1) return f[A][B][C];
	f[A][B][C] = 0;
	f[A][B][C] += dfs(A - 1, B - 1, C);
	f[A][B][C] %= MOD;
	f[A][B][C] += dfs(A - 1, B, C - 1);
	f[A][B][C] %= MOD;
	f[A][B][C] += dfs(A, B - 1, C - 1);
	f[A][B][C] %= MOD;
	return f[A][B][C];
}

void solve() {
	n = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n) b[i] = read();
	if (n <= 3) {
		if (n == 2) {
			if (b[1] - a[1] == b[2] - a[2]) return puts("1"), void();
			else return puts("0"), void();
		}
		else {
			memset(f, -1, sizeof f);
			f[a[1]][a[2]][a[3]] = 1;
			print(dfs(b[1], b[2], b[3])), puts("");
		}
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("trans.in", "r", stdin);
	freopen("trans.out", "w", stdout);
#endif
#endif
	int T = read();
	while (T --> 0) solve();
	return 0;
}
