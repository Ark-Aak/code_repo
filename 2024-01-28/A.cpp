#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

const int MAXN = 1e5 + 5;
int n, q, a[MAXN], l[MAXN], r[MAXN];

namespace seg {

#define mid ((L + R) >> 1)
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)

	struct node {
		int l, r, val;
		bool tag;
	} t[MAXN << 2];

	void pushup(int x) {
		t[x].val = t[ls(x)].val + t[rs(x)].val;
	}

	void pushdown(int x) {
		if (t[x].tag) {
			t[x].tag = 0;
			t[ls(x)].tag ^= 1;
			t[rs(x)].tag ^= 1;
			t[ls(x)].val = t[ls(x)].r - t[ls(x)].l + 1 - t[ls(x)].val;
			t[rs(x)].val = t[rs(x)].r - t[rs(x)].l + 1 - t[rs(x)].val;
		}
	}

	void build(int x, int L, int R) {
		t[x].l = L, t[x].r = R;
		if (L == R) {
			t[x].val = a[L];
			return;
		}
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
		pushup(x);
	}

	void modify(int x, int L, int R, int l, int r) {
		if (l <= L && R <= r) {
			t[x].tag ^= 1;
			t[x].val = R - L + 1 - t[x].val;
			return;
		}
		pushdown(x);
		if (l <= mid) modify(ls(x), L, mid, l, r);
		if (r > mid) modify(rs(x), mid + 1, R, l, r);
		pushup(x);
	}

	int query(int x, int L, int R, int l, int r) {
		if (l <= L && R <= r) return t[x].val;
		pushdown(x);
		int res = 0;
		if (l <= mid) res += query(ls(x), L, mid, l, r);
		if (r > mid) res += query(rs(x), mid + 1, R, l, r);
		return res;
	}
} // namespace seg

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
#endif
#endif
	n = read(), q = read();
	rep (i, 1, n) a[i] = read();
	seg::build(1, 1, n);
	while (q --> 0) {
		int op, x, y, k;
		op = read();
		if (op == 1) {
			x = read(), y = read();
			seg::modify(1, 1, n, x, y);
		}
		else {
			k = read();
			rep (i, 1, k) l[i] = read(), r[i] = read();
			int cnt = 0;
			rep (i, 1, k) cnt += seg::query(1, 1, n, l[i], r[i]);
			if (cnt & 1) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
