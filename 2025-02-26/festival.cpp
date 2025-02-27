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

const int MAXN = 500;
int c, T;
int n, k, a[MAXN], b[MAXN];
int na[MAXN];

void solve() {
	memset(na, 0, sizeof na);
	n = read(), k = read();
	rep (i, 1, n - 1) a[i] = read();
	rep (i, 1, k) b[i] = read();
	int fans = 0;
	rep (v, 0, a[1]) {
		na[1] = v;
		rep (i, 1, n - 1) na[i + 1] = a[i] - na[i];
		bool flg = 0;
		rep (i, 1, n) if (na[i] < 0) flg = 1;
		if (flg) continue;
		int ans = 0;
		rep (i, 1, k) {
			rep (j, i, n - k + i) {
				ans += na[j] * b[i];
			}
		}
		fans = max(fans, ans);
	}
	print(fans), puts("");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("festival.in", "r", stdin);
	freopen("festival.out", "w", stdout);
#endif
#endif
	c = read(), T = read();
	while (T --> 0) solve();
	return 0;
}
