#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define int ll

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

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

signed main() {
	read(n), read(m);
	rep (i, 1, n) read(a[i]);
	build(1, 1, n);
	rep (i, 1, m) {
		int op;
		read(op);
		int x, y, k;
		read(x), read(y);
		if (op == 1) {
			read(k);
			modify(1, 1, n, x, y, k);
		}
		else print(query(1, 1, n, x, y)), putchar(10);
	}
	return 0;
}
