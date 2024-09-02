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

#define int ll

const int MOD = 998244353;
int f[2][10005], w[4005];
int n, V;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
#endif
#endif
	n = read(), V = read();
	rep (i, 1, n) w[i] = read();
	f[1][0] = 1;
	rep (i, 1, n) {
		const int op = !(i & 1);
		memset(f[op], 0, sizeof f[op]);
		for (int j = V; ~j; j--) {
			f[op][j] = f[!op][j] * 2 % MOD;
			if (j >= w[i]) f[op][j] = (f[op][j] + f[!op][j - w[i]] % MOD) % MOD;
		}
	}
	print(f[!(n & 1)][V]), puts("");
	return 0;
}