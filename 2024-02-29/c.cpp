#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

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

const int MAXN = 5e4 + 5;

int n, q, P;
int a[MAXN];

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

namespace segment_tree {
	int lazy[MAXN << 2], sum[MAXN << 2];

	void pushup(int x) { sum[x] = (sum[ls(x)] + sum[rs(x)]) % P; }

	void pushdown(int x, int L, int R) {
		if (L == R) return;
		sum[ls(x)] = lazy[x] * (mid - L + 1) % P;
		sum[rs(x)] = lazy[x] * (R - mid) % P;
		lazy[ls(x)] = lazy[rs(x)] = lazy[x];
		lazy[x] = 0;
	}

	void build(int x, int L, int R) {
		if (L == R) {
			sum[x] = a[L] % P;
			return;
		}
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
		pushup(x);
	}

	void modify(int x, int L, int R, int l, int r, int v) {
		if (l <= L && R <= r) {
			sum[x] = v * (R - L + 1) % P;
			lazy[x] = v;
			return;
		}
		if (lazy[x]) pushdown(x, L, R);
		if (l <= mid) modify(ls(x), L, mid, l, r, v);
		if (r > mid) modify(rs(x), mid + 1, R, l, r, v);
		pushup(x);
	}

	int query(int x, int L, int R, int l, int r) {
		if (l <= L && R <= r) return sum[x];
		if (lazy[x]) pushdown(x, L, R);
		int res = 0;
		if (l <= mid) res = (res + query(ls(x), L, mid, l, r)) % P;
		if (r > mid) res = (res + query(rs(x), mid + 1, R, l, r)) % P;
		return res;
	}
} // namespace segment_tree

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
#endif
#endif
	n = read(), q = read(), P = read();
	rep (i, 1, n) a[i] = read();
	segment_tree::build(1, 1, n);
	while (q --> 0) {
		int op = read();
		if (op == 1) {
			int l = read(), r = read(), k = read();
			segment_tree::modify(1, 1, n, l, r, k);
		}
		else {
			int l = read(), r = read();
			print(segment_tree::query(1, 1, n, l, r)), putchar('\n');
		}
	}
	return 0;
}
