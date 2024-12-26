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

bool stmer;

const int MAXN = 1e5 + 5;
const int MAXM = 6;
int n, m, q;
int c[MAXN], a[MAXN][MAXM];
int pre[MAXN][MAXM];

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

namespace seg {

	struct node {

		int left[MAXM];
		int right[MAXM];
		int dp1[MAXM];
		int dp2[MAXM];
		int val;

		void clean() {
			rep (i, 1, m) left[i] = right[i] = dp1[i] = dp2[i] = 0;
			val = 0;
		}

	} t[MAXN << 2];

	node merge(node a, node b) {
		if (!a.val) return b;
		if (!b.val) return a;
		node res;
		res.clean();
		rep (i, 1, m) res.left[i] = a.left[i] ? a.left[i] : b.left[i];
		rep (i, 1, m) res.right[i] = b.right[i] ? b.right[i] : a.right[i];
		res.val = a.val + b.val;
		rep (i, 1, m) {
			int pos = b.left[i];
			int prv = a.right[i];
			if (pos == 0 || prv == 0) continue;
			int cst = pre[pos][i] - pre[prv - 1][i];
			// cout << cst << " " << a.dp1[i] << " " << b.dp2[i] << endl;
			res.val = max(res.val, a.dp1[i] + b.dp2[i] + cst);
		}
		rep (i, 1, m) {
			res.dp1[i] = res.val - (b.val - b.dp1[i]);
			res.dp2[i] = res.val - (a.val - a.dp2[i]);
			if (!a.left[i]) res.dp2[i] = b.dp2[i];
			if (!b.right[i]) res.dp1[i] = a.dp1[i];
		}
		return res;
	}

	void build(int x, int L, int R) {
		if (L == R) {
			t[x].left[c[L]] = L;
			t[x].right[c[L]] = L;
			t[x].val = a[L][c[L]];
			return;
		}
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
		t[x] = merge(t[ls(x)], t[rs(x)]);
		// cout << L << ", " << R << ": " << t[x].val << endl;
	}

	void modify(int x, int L, int R, int p, int v) {
		if (L == R) {
			t[x].clean();
			t[x].left[c[L]] = L;
			t[x].right[c[L]] = L;
			t[x].val = a[L][c[L]];
			return;
		}
		if (p <= mid) modify(ls(x), L, mid, p, v);
		else modify(rs(x), mid + 1, R, p, v);
		t[x] = merge(t[ls(x)], t[rs(x)]);
	}

	node query(int x, int L, int R, int l, int r) {
		if (l <= L && R <= r) return t[x];
		node res;
		res.clean();
		if (l <= mid) res = merge(res, query(ls(x), L, mid, l, r));
		if (r > mid) res = merge(res, query(rs(x), mid + 1, R, l, r));
		return res;
	}

} // namespace seg

bool edmer;
int lstans = 0;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
#endif
#endif
	cerr << (&stmer - &edmer) / 1024.0 / 1024.0 << "MiB" << endl;
	n = read(), m = read(), q = read();
	rep (i, 1, n) c[i] = read();
	rep (i, 1, n) rep (j, 1, m) a[i][j] = read();
	rep (i, 1, n) rep (j, 1, m) pre[i][j] = pre[i - 1][j] + a[i][j];
	seg::build(1, 1, n);
	print(seg::t[1].val), puts("");
	lstans = seg::t[1].val;
	while (q --> 0) {
		int op = read();
		int x = read(), y = read();
		x ^= lstans, y ^= lstans;
		if (op == 1) seg::modify(1, 1, n, x, y);
		else {
			lstans = seg::query(1, 1, n, x, y).val;
			print(lstans), puts("");
		}
	}
	return 0;
}
