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

const int MAXN = 3e5 + 5;
const int MAXM = 30;
const int INF = (1 << 30);
const int B = 29;

int p[B + 10], d[B + 10], cnt, zero;

inline int get(int x, int y) { return ((x >> y) & 1); }

inline void insert(int x) {
	_rep (i, B, 0) {
		if ((x >> i) & 1) {
			if (!p[i]) return p[i] = x, cnt++, void();
			x ^= p[i];
		}
	}
	if (!x) zero = true;
	return;
}

inline void init() {
	cnt = 0;
	_rep (i, B, 0) _rep (j, i - 1, 0) if ((p[i] >> j) & 1) p[i] ^= p[j];
	rep (i, 0, B) if (p[i]) d[cnt++] = p[i];
}

inline int querymax(int x) {
	int ans = x;
	_rep (i, B, 0) ans = max(ans, ans ^ p[i]);
	return ans;
}

int f[MAXM + 1][2];

int query(int x, int y) {
	rep (i, 0, MAXM) f[i][0] = f[i][1] = INF;
	f[MAXM][1] = x;
	_rep (i, MAXM - 1, 0) {
		f[i][0] = min(f[i + 1][0], f[i + 1][0] ^ p[i]);
		if (!get(f[i + 1][1], i)) {
			if (p[i]) f[i][get(y, i)] = f[i + 1][1] ^ p[i];
			if (!get(y, i)) f[i][1] = f[i + 1][1];
		}
		else {
			f[i][get(y, i)] = f[i + 1][1];
			if (!get(y, i) && p[i]) f[i][1] = f[i + 1][1] ^ p[i];
		}
	}
	return min(f[0][0], f[0][1]);
}

int n, ans = 0, a[MAXN], g[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) a[i] = read();
	fill(g + 1, g + 1 + n, INF);
	g[0] = -1;
	rep (i, 1, n) {
		_rep (j, i, 1) {
			if (querymax(a[i]) > g[j - 1]) {
				g[j] = min(g[j], query(a[i], g[j - 1] + 1));
			}
		}
		insert(a[i]);
		init();
	}
	_rep (i, n, 1) if (g[i] < INF) { ans = i; break; }
	print(ans), puts("");
	return 0;
}
