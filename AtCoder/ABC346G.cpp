#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

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

const int MAXN = 2e5 + 5;

namespace seg {
const int MAXN = 1e5 + 5;
int lazy[MAXN << 2], sum[MAXN << 2], a[MAXN];
int n, m;

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

void pushup(int x) {
	sum[x] = sum[ls(x)] + sum[rs(x)];
}

void pushdown(int x, int L, int R) {
	sum[ls(x)] += (mid - L + 1) * lazy[x];
	sum[rs(x)] += (R - mid) * lazy[x];
	lazy[ls(x)] += lazy[x];
	lazy[rs(x)] += lazy[x];
	lazy[x] = 0;
}

void build(int x, int L, int R) {
	if (L == R) return (void) (sum[x] = a[L]);
	build(ls(x), L, mid);
	build(rs(x), mid + 1, R);
	pushup(x);
}

void modify(int x, int L, int R, int l, int r, int val) {
	if (l > r) return;
	if (l <= L && R <= r) return (void) (sum[x] += (R - L + 1) * val, lazy[x] += val);
	if (L != R) pushdown(x, L, R);
	if (l <= mid) modify(ls(x), L, mid, l, r, val);
	if (r > mid) modify(rs(x), mid + 1, R, l, r, val);
	pushup(x);
}

int query(int x, int L, int R, int l, int r) {
	if (l <= L && R <= r) return sum[x];
	int res = 0;
	if (L != R) pushdown(x, L, R);
	if (l <= mid) res += query(ls(x), L, mid, l, r);
	if (r > mid) res += query(rs(x), mid + 1, R, l, r);
	pushup(x);
	return res;
}
} // namespace seg

int lst1[MAXN], lst2[MAXN];
int n, a[MAXN];

signed main() {
	n = read();
	rep (i, 1, n) a[i] = read();
	ll ans = 0;
	rep (i, 1, n) {
		ans += i - (lst1[a[i]]);
		lst1[a[i]] = i;
	}
	print(ans);
	return 0;
}
