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
int n, a[MAXN], b[MAXN], l, r;

namespace sol {

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

	int iw[MAXN], ia[MAXN];
	int val[MAXN << 2], minn[MAXN << 2], stmin[MAXN << 2];
	int lazy[MAXN << 2], cover[MAXN << 2];
	int ans[MAXN];

	void pushup(int x) {
		minn[x] = min(minn[ls(x)], minn[rs(x)]);
		stmin[x] = min(stmin[ls(x)], stmin[rs(x)]);
		val[x] = val[ls(x)] + val[rs(x)];
	}

	void build(int x, int L, int R) {
		if (L == R) {
			if (ia[L]) minn[x] = 1e18, val[x] = b[L];
			else minn[x] = a[L] - iw[L], val[x] = 0;
			stmin[x] = a[L];
			return;
		}
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
		pushup(x);
	}

	void pushdown(int x, int L, int R) {
		if (cover[x]) {
			minn[ls(x)] = stmin[ls(x)];
			minn[rs(x)] = stmin[rs(x)];
			cover[ls(x)] = 1, cover[rs(x)] = 1;
			lazy[ls(x)] = 0, lazy[rs(x)] = 0;
			val[ls(x)] = 0, val[rs(x)] = 0;
			cover[x] = 0;
		}
		if (lazy[x]) {
			minn[ls(x)] -= lazy[x];
			minn[rs(x)] -= lazy[x];
			lazy[ls(x)] += lazy[x], lazy[rs(x)] += lazy[x];
			lazy[x] = 0;
		}
	}

	int query(int x, int L, int R) {
		if (L == R) return L;
		pushdown(x, L, R);
		if (minn[ls(x)] == 0) return query(ls(x), L, mid);
		else return query(rs(x), mid + 1, R);
	}

	void init(int x, int L, int R, int l, int r) {
		if (l <= L && R <= r) {
			minn[x] = stmin[x];
			lazy[x] = 0;
			cover[x] = 1;
			val[x] = 0;
			return;
		}
		pushdown(x, L, R);
		if (l <= mid) init(ls(x), L, mid, l, r);
		if (r > mid) init(rs(x), mid + 1, R, l, r);
		pushup(x);
	}

	void active(int x, int L, int R, int p, int v) {
		if (L == R) {
			val[x] = v;
			minn[x] = 1e18;
			return;
		}
		pushdown(x, L, R);
		if (p <= mid) active(ls(x), L, mid, p, v);
		else active(rs(x), mid + 1, R, p, v);
		pushup(x);
	}

	void solve() {
		int k = l;
		rep (i, 1, n) {
			if (k >= a[i]) k -= a[i], ia[i] = 1;
			iw[i] = k;
		}
		build(1, 1, n);
		ans[1] = val[1];
		rep (i, l + 1, r) {
			int pos = i - l + 1;
			minn[1] -= 1;
			lazy[1] += 1;
			if (minn[1] == 0) {
				int zpos = query(1, 1, n);
				if (zpos != n) init(1, 1, n, zpos + 1, n);
				active(1, 1, n, zpos, b[zpos]);
				ans[pos] = val[1];
			}
			else ans[pos] = ans[pos - 1];
		}
		rep (i, 1, r - l + 1) print(ans[i]), putchar(32);
		puts("");
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("simu.in", "r", stdin);
	freopen("simu.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n) b[i] = read();
	l = read(), r = read();
	sol::solve();
	return 0;
}
