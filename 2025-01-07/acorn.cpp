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

const int MAXN = 1e6 + 5;
int n, k, t, c[MAXN], diff[MAXN];
int ans[MAXN];
vector <int> G[MAXN];

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

int val[MAXN << 2], lazy[MAXN << 2];

void pushdown(int x, int L, int R) {
	if (!lazy[x]) return;
	lazy[ls(x)] += lazy[x];
	lazy[rs(x)] += lazy[x];
	val[ls(x)] += lazy[x];
	val[rs(x)] += lazy[x];
	lazy[x] = 0;
}

void build(int x, int L, int R) {
	if (L == R) {
		val[x] = c[L];
		return;
	}
	build(ls(x), L, mid);
	build(rs(x), mid + 1, R);
	val[x] = min(val[ls(x)], val[rs(x)]);
}

void modify(int x, int L, int R, int l, int r, int v) {
	if (l <= L && R <= r) {
		val[x] += v;
		lazy[x] += v;
		return;
	}
	pushdown(x, L, R);
	if (l <= mid) modify(ls(x), L, mid, l, r, v);
	if (r > mid) modify(rs(x), mid + 1, R, l, r, v);
	val[x] = min(val[ls(x)], val[rs(x)]);
}

int query(int x, int L, int R, int l, int r) {
	if (l <= L && R <= r) return val[x];
	pushdown(x, L, R);
	int res = 1e18;
	if (l <= mid) res = min(res, query(ls(x), L, mid, l, r));
	if (r > mid) res = min(res, query(rs(x), mid + 1, R, l, r));
	return res;
}

void color(int u, int col) {
	if (~ans[u]) {
		if (ans[u] != col) {
			puts("No");
			exit(0);
		}
		return;
	}
	ans[u] = col;
	// u - t + 1 ~ u
	if (u - t + 1 >= 0) modify(1, 0, n - 1, u - t + 1, u, -col);
	else {
		modify(1, 0, n - 1, u - t + 1 + n, n - 1, -col);
		modify(1, 0, n - 1, 0, u, -col);
	}
	for (auto v : G[u]) {
		color(v, col);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("acorn.in", "r", stdin);
	freopen("acorn.out", "w", stdout);
#endif
#endif
	n = read(), k = read(), t = read();
	rep (i, 0, n - 1) c[i] = read();
	int offset = 0;
	rep (i, 0, n - 1) {
		int j = (i + 1) % n;
		if (c[j] == (c[i] + 1) % k) diff[i] = 1;
		else if (c[j] == (c[i] + k - 1) % k) diff[i] = -1;
		else if (c[j] == c[i]) diff[i] = 0;
		else return puts("No"), 0;
	}
	c[0] = t * k + c[0];
	rep (i, 0, n - 1) c[(i + 1) % n] = c[i] + diff[i];
	int mn = t * k;
	rep (i, 0, n - 1) mn = min(mn, c[i] / k);
	rep (i, 0, n - 1) {
		c[i] -= mn * k;
		if (c[i] > t) return puts("No"), 0;
	}
	build(1, 0, n - 1);
	memset(ans, -1, sizeof ans);
	rep (i, 0, n - 1) {
		if (diff[i] == 0) {
			G[i].push_back((i + t) % n);
			G[(i + t) % n].push_back(i);
		}
	}
	rep (i, 0, n - 1) {
		if (diff[i] == 0) continue;
		if (diff[i] == 1) color(i, 0), color((i + t) % n, 1);
		if (diff[i] == -1) color(i, 1), color((i + t) % n, 0);
	}
	rep (i, 0, n - 1) {
		if (~ans[i]) continue;
		/*
		rep (_j, i - t + 1, i) {
			int j = (_j + n) % n;
			int tot = 0;
			rep (_k, j, j + t - 1) {
				int k = (_k + n) % n;
				tot += ans[k] == 1;
			}
			if (tot == c[j]) {
				color(i, 0);
				break;
			}
		}
		*/
		int mn = 1e18;
		if (i - t + 1 >= 0) mn = query(1, 0, n - 1, i - t + 1, i);
		else {
			mn = min(mn, query(1, 0, n - 1, i - t + 1 + n, n - 1));
			mn = min(mn, query(1, 0, n - 1, 0, i));
		}
		if (mn > 0) color(i, 1);
		else color(i, 0);
	}
	rep (i, 0, n - 1)
		if (query(1, 0, n - 1, i, i) != 0) return puts("No"), 0;
	puts("Yes");
	rep (i, 0, n - 1) print(ans[i]), putchar(32);
	puts("");
	return 0;
}
