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

const int MAXN = 3e5 + 5;
const int MOD = 998244353;
int n, k, q, p[MAXN];
int sum[MAXN];

void add(int p, int v) { for (int x = p; x <= n; x += x & -x) sum[x] += v; }
int query(int p, int v = 0) { for (int x = p; x; x -= x & -x) v += sum[x]; return v; }

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("random.in", "r", stdin);
	freopen("random.out", "w", stdout);
#endif
#endif
	n = read(), k = read(), q = read();
	rep (i, 1, n) p[i] = read();
	if (k == 0) {
		int res = 0;
		rep (i, 1, n) {
			res = (res + query(n) - query(p[i] - 1)) % MOD;
			add(p[i], 1);
		}
		print(res);
		return 0;
	}
	return 0;
}
