#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

#define int ll

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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 1e5 + 5;
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

int isUp[MAXN << 2], isDown[MAXN << 2];
int lazy[MAXN << 2], mx[MAXN << 2], mn[MAXN << 2];
int a[MAXN];

void pushup(int x) {
	isUp[x] = (isUp[ls(x)] && isUp[rs(x)]) && (mx[ls(x)] < mn[rs(x)]);
	isDown[x] = (isDown[ls(x)] && isDown[rs(x)]) && (mn[ls(x)] > mx[rs(x)]);
	mx[x] = max(mx[ls(x)], mx[rs(x)]);
	mn[x] = min(mn[ls(x)], mn[rs(x)]);
}

void pushdown(int x, int L, int R) {
	if (!lazy[x] || L == R) return;
	mx[ls(x)] += lazy[x];
	mx[rs(x)] += lazy[x];
	mn[ls(x)] += lazy[x];
	mn[rs(x)] += lazy[x];
	lazy[ls(x)] += lazy[x];
	lazy[rs(x)] += lazy[x];
	lazy[x] = 0;
}

void build(int x, int L, int R) {
	if (L == R) {
		mx[x] = mn[x] = a[L];
		isUp[x] = isDown[x] = 1;
		return;
	}
	build(ls(x), L, mid);
	build(rs(x), mid + 1, R);
	pushup(x);
}

void op1(int x, int L, int R, int l, int r, int val) {
	if (l <= L && R <= r) {
		lazy[x] += val;
		mx[x] += val, mn[x] += val;
		return;
	}
	pushdown(x, L, R);
	if (l <= mid) op1(ls(x), L, mid, l, r, val);
	if (r > mid) op1(rs(x), mid + 1, R, l, r, val);
	pushup(x);
}

tuple <int, int> op2(int x, int L, int R, int l, int r) {
	if (l <= L && R <= r) return dk(mn[x] == mx[x], mn[x]);
	pushdown(x, L, R);
	tuple <int, int> res1 = dk(1e18, 1e18), res2 = dk(1e18, 1e18);
	if (l <= mid) res1 = op2(ls(x), L, mid, l, r);
	if (r > mid) res2 = op2(rs(x), mid + 1, R, l, r);
	int ok1 = get<0>(res1), ok2 = get<0>(res2);
	if (!ok1 || !ok2) return dk(0, 0);
	if (res1 == dk(1e18, 1e18)) return res2;
	if (res2 == dk(1e18, 1e18)) return res1;
	if (ok1 && ok2) return (get<1>(res1) == get<1>(res2)) ? (dk(1ll, get<1>(res1))) : dk(0ll, 0ll);
	assert(0);
	return dk(0, 0);
}

tuple <int, int, int> op3(int x, int L, int R, int l, int r) {
	if (l <= L && R <= r) return dk(isUp[x], mn[x], mx[x]);
	pushdown(x, L, R);
	tuple <int, int, int> res1 = dk(-1, 0, 0), res2 = dk(-1, 0, 0);
	if (l <= mid) res1 = op3(ls(x), L, mid, l, r);
	if (r > mid) res2 = op3(rs(x), mid + 1, R, l, r);
	if (res1 == dk(-1, 0, 0)) return res2;
	if (res2 == dk(-1, 0, 0)) return res1;
	tuple <int, int, int> res;
	int mn = min(get<1>(res1), get<1>(res2));
	int mx = max(get<2>(res1), get<2>(res2));
	int ok = get<0>(res1) && get<0>(res2) && (get<2>(res1) < get<1>(res2));
	return dk(ok, mn, mx);
}

void print(tuple <int, int, int> tp) {
	cout << "tuple:" << get<0>(tp) << " " << get<1>(tp) << " " << get<2>(tp) << endl;
}

tuple <int, int, int> op4(int x, int L, int R, int l, int r) {
	/* cout << "seg:" << x << " " << L << " " << R << endl; */
	if (l <= L && R <= r) return dk(isDown[x], mn[x], mx[x]);
	pushdown(x, L, R);
	tuple <int, int, int> res1 = dk(-1, 0, 0), res2 = dk(-1, 0, 0);
	if (l <= mid) res1 = op4(ls(x), L, mid, l, r);
	if (r > mid) res2 = op4(rs(x), mid + 1, R, l, r);
	/* print(res1), print(res2); */
	if (res1 == dk(-1, 0, 0)) return res2;
	if (res2 == dk(-1, 0, 0)) return res1;
	tuple <int, int, int> res;
	int mn = min(get<1>(res1), get<1>(res2));
	int mx = max(get<2>(res1), get<2>(res2));
	int ok = get<0>(res1) && get<0>(res2) && (get<1>(res1) > get<2>(res2));
	return dk(ok, mn, mx);
}

#undef mid

int n, q;

int op5(int l, int r) {
	const int L = l;
	const int R = r;
	l++, r--;
	while (l <= r) {
		int mid = l + ((r - l) >> 1);
		auto res1 = op3(1, 1, n, L, mid);
		auto res2 = op4(1, 1, n, mid, R);
		int ok1 = get<0>(res1);
		int ok2 = get<0>(res2);
		if (ok1 && ok2) {
			return 1;
		}
		if (!ok1) r = mid - 1;
		else l = mid + 1;
	}
	return 0;
}

signed main() {
	n = read();
	rep (i, 1, n) a[i] = read();
	build(1, 1, n);
	q = read();
	rep (i, 1, q) {
		int op = read();
		if (op == 1) {
			int l = read(), r = read(), x = read();
			op1(1, 1, n, l, r, x);
		}
		if (op == 2) {
			int l = read(), r = read();
			print(get<0>(op2(1, 1, n, l, r))), puts("");
		}
		if (op == 3) {
			int l = read(), r = read();
			print(get<0>(op3(1, 1, n, l, r))), puts("");
		}
		if (op == 4) {
			int l = read(), r = read();
			print(get<0>(op4(1, 1, n, l, r))), puts("");
		}
		if (op == 5) {
			int l = read(), r = read();
			print(op5(l, r)), puts("");
		}
	}
	return 0;
}
