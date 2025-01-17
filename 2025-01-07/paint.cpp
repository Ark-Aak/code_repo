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

#define y1 __federico

const int MAXN = 2e5 + 5;
int n, m, q;
int x1[MAXN], x2[MAXN], y1[MAXN], y2[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), q = read();
	rep (i, 1, n) x1[i] = read(), y1[i] = read(), x2[i] = read(), y2[i] = read();
	assert(m == 0);
	rep (i, 1, q) {
		int x = read(), y = read();
		int cnt = 0;
		rep (j, 1, n) {
			if (x1[j] <= x && x <= x2[j]) {
				if (y1[j] <= y && y <= y2[j]) ++cnt;
			}
		}
		print(cnt), puts("");
	}
	return 0;
}
