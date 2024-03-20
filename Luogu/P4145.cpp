#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

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

#define int ll
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

const int MAXN = 1e6 + 5;
int sum[MAXN], mx[MAXN];

void pushup(int x) {
	mx[x] = max(mx[ls(x)], mx[rs(x)]);
	sum[x] = sum[ls(x)] + sum[rs(x)];
}

#define ts sum[x]
#define tm mx[x]

void modify(int x, int L, int R, int l, int r) {
	if (l > R || r < L) return;
	if (L == R) return (void) (ts = sqrt(ts), tm = ts);
	if (l <= mid && mx[ls(x)] > 1) modify(ls(x), L, mid, l, r);
	if (r > mid && mx[rs(x)] > 1) modify(rs(x), mid + 1, R, l, r);
	pushup(x);
}

int query(int x, int L, int R, int l, int r) {
	if (l <= L && R <= r) return ts;
	int res = 0;
	if (l <= mid) res += query(ls(x), L, mid, l, r);
	if (r > mid) res += query(rs(x), mid + 1, R, l, r);
	return res;
}

int a[MAXN];

void build(int x, int L, int R) {
	if (L == R) return (void) (tm = ts = a[L]);
	build(ls(x), L, mid);
	build(rs(x), mid + 1, R);
	pushup(x);
}

int n, m;

signed main() {
	read(n);
	rep (i, 1, n) read(a[i]);
	build(1, 1, n);
	read(m);
	while (m --> 0) {
		int k, l, r;
		read(k), read(l), read(r);
		if (l > r) swap(l, r);
		if (k) print(query(1, 1, n, l, r)), putchar(10);
		else modify(1, 1, n, l, r);
	}
	return 0;
}
