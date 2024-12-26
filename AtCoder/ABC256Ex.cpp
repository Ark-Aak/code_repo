#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#include <bits/stdc++.h>

#define getchar()                                                            \
	(p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) \
		? EOF                                                                \
		: *p1++)

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

char buf[1 << 20], *p1, *p2;

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

const int MAXN = 5e5 + 5;
int n, q, a[MAXN];

namespace seg {

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

	ll sum[MAXN << 2];
	int lazy[MAXN << 2], minn[MAXN << 2], maxn[MAXN << 2];

	inline void pushup(int x) {
		sum[x] = sum[ls(x)] + sum[rs(x)];
		maxn[x] = max(maxn[ls(x)], maxn[rs(x)]);
		minn[x] = min(minn[ls(x)], minn[rs(x)]);
	}

	void build(int x, int L, int R) {
		lazy[x] = -1;
		if (L == R) {
			maxn[x] = minn[x] = sum[x] = a[L];
			return;
		}
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
		pushup(x);
	}

	inline void pushdown(int x, int L, int R) {
		if (lazy[x] == -1) return;
		maxn[ls(x)] = minn[ls(x)] = lazy[x];
		maxn[rs(x)] = minn[rs(x)] = lazy[x];
		lazy[ls(x)] = lazy[rs(x)] = lazy[x];
		sum[ls(x)] = 1ll * minn[ls(x)] * (mid - L + 1);
		sum[rs(x)] = 1ll * minn[rs(x)] * (R - mid);
		lazy[x] = -1;
	}

	void div(int x, int L, int R, int l, int r, int v) {
		if (l <= L && R <= r && minn[x] == maxn[x]) {
			minn[x] /= v;
			maxn[x] /= v;
			sum[x] = 1ll * maxn[x] * (R - L + 1);
			lazy[x] = maxn[x];
			return;
		}
		pushdown(x, L, R);
		if (l <= mid) div(ls(x), L, mid, l, r, v);
		if (r > mid) div(rs(x), mid + 1, R, l, r, v);
		pushup(x);
	}

	void assign(int x, int L, int R, int l, int r, int v) {
		if (l <= L && R <= r) {
			minn[x] = maxn[x] = v;
			sum[x] = 1ll * maxn[x] * (R - L + 1);
			lazy[x] = maxn[x];
			return;
		}
		pushdown(x, L, R);
		if (l <= mid) assign(ls(x), L, mid, l, r, v);
		if (r > mid) assign(rs(x), mid + 1, R, l, r, v);
		pushup(x);
	}

	ll query(int x, int L, int R, int l, int r) {
		if (l <= L && R <= r) return sum[x];
		pushdown(x, L, R);
		ll res = 0;
		if (l <= mid) res += query(ls(x), L, mid, l, r);
		if (r > mid) res += query(rs(x), mid + 1, R, l, r);
		return res;
	}
} // namespace seg

signed main() {
	n = read(), q = read();
	rep (i, 1, n) a[i] = read();
	seg::build(1, 1, n);
	while (q --> 0) {
		int op = read();
		int l = read(), r = read();
		if (op == 1) {
			int x = read();
			seg::div(1, 1, n, l, r, x);
		}
		else if (op == 2) {
			int y = read();
			seg::assign(1, 1, n, l, r, y);
		}
		else {
			print(seg::query(1, 1, n, l, r)), puts("");
		}
	}
	return 0;
}
