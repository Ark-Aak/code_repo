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

const int MAXN = 3005;
int s[MAXN], d[MAXN], f[MAXN];
mt19937 rnd(time(0));
int o[MAXN], tag[MAXN];
int n;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("physics.in", "r", stdin);
	freopen("physics.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 2, n) s[i] = read(), s[i] += s[i - 1];
	rep (i, 1, n) d[i] = read();
	rep (i, 0, n) f[i] = read();
	rep (i, 1, n) o[i] = i;
	tag[0] = tag[n + 1] = 1;
	int ans = 1e18;
	do {
		shuffle(o + 1, o + 1 + n, rnd);
		rep (i, 1, n) tag[i] = 0;
		int tot = 0;
		int mx = 0;
		int nw = 0;
		rep (i, 1, n) {
			tot = tot + abs(s[nw] - s[o[i]]) + d[o[i]];
			tag[o[i]] = 1;
			if (tag[o[i] - 1]) mx = max(mx, f[o[i] - 1] + tot);
			if (tag[o[i] + 1]) mx = max(mx, f[o[i]] + tot);
			nw = o[i];
		}
		ans = min(ans, mx);
	} while (clock() * 1.0 / CLOCKS_PER_SEC < 0.95);
	print(ans), puts("");
	return 0;
}
