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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 2e5 + 5;
int n, a[MAXN], b[MAXN], ans[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("min.in", "r", stdin);
	freopen("min.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n) b[i] = read();
	rep (i, 1, n) ans[i] = 2e9;
	rep (k, 1, n) {
		rep (l, 1, n - k + 1) {
			int r = l + k - 1;
			int mina = 1e9, minb = 1e9;
			rep (j, l, r) mina = min(mina, a[j]);
			rep (j, l, r) minb = min(minb, b[j]);
			ans[k] = min(ans[k], abs(mina - minb));
		}
	}
	rep (i, 1, n) print(ans[i]), puts("");
	return 0;
}
