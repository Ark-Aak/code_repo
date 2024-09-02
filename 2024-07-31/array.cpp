#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep (i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define ec first
#define fb second
#define de(x) cerr << #x << " = " << (x) << endl

using namespace std;

#define int ll

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, w = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + (ch ^ 48);
		ch = getchar();
	}
	return x * w;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

const int MAXN = 3e5 + 5;
int n, a[MAXN];

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

namespace seg {
	int mx[MAXN << 2], lazy[MAXN << 2];

	void pushup(int x) { mx[x] = max(mx[ls(x)], mx[rs(x)]); }

	void pushdown(int x) {
		if (!lazy[x]) return;
		mx[ls(x)] = max(mx[ls(x)], lazy[x]);
		mx[rs(x)] = max(mx[rs(x)], lazy[x]);
		lazy[ls(x)] = max(lazy[ls(x)], lazy[x]);
		lazy[rs(x)] = max(lazy[rs(x)], lazy[x]);
		lazy[x] = 0;
	}

	void update(int x, int L, int R, int l, int r, int val) {
		if (l <= L && R <= r) {
			mx[x] = max(mx[x], val);
			lazy[x] = max(lazy[x], val);
			return;
		}
		if (L != R) pushdown(x);
		if (l <= mid) update(ls(x), L, mid, l, r, val);
		if (r > mid) update(rs(x), mid + 1, R, l, r, val);
		pushup(x);
	}

	int query(int x, int L, int R, int pos) {
		if (L == R) return mx[x];
		pushdown(x);
		if (pos <= mid) return query(ls(x), L, mid, pos);
		else return query(rs(x), mid + 1, R, pos);
	}
}

signed main() {
#ifndef LOCAL
	freopen("array.in", "r", stdin);
	freopen("array.out", "w", stdout);
#endif
	n = read();
	n *= 2;
	rep (i, 1, n) a[i] = read();
	int tn = n / 2, ans = 0;
	rep (i, 1, n) {
		ans = max(ans, a[i] + a[i + tn > n ? i + tn - n : i + tn]);
	}
	print(ans);
	return 0;
}
