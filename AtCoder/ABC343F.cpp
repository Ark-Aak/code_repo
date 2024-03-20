#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <immintrin.h>
#include <emmintrin.h>

#include <bits/stdc++.h>

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

const int MAXN = 5e5 + 5;

int H[MAXN];
int N, n, m, cnt, a[MAXN];

void init() {
	sort(H + 1, H + 1 + N);
	N = unique(H + 1, H + N + 1) - H - 1;
}

int find(int x) {
	return lower_bound(H + 1, H + 1 + N, x) - H;
}

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)

namespace TIT {

struct node {
	int ls, rs;
	int sum;

	node() {ls = 0, rs = 0, sum = 0;}
} mem[65000000];

void pushup(int x) {
	mem[x].sum = mem[mem[x].ls].sum + mem[mem[x].rs].sum;
}

int cnt = 0;

int newNode() {
	return ++cnt;
}

int root[MAXN];

int ltr[MAXN], rtr[MAXN];

#define mid ((L + R) >> 1)

void update(int &cur, int L, int R, int k, int val) {
	if (!cur) cur = newNode();
	if (L == R) return (void) (mem[cur].sum += val);
	if (k <= mid) update(mem[cur].ls, L, mid, k, val);
	else update(mem[cur].rs, mid + 1, R, k, val);
	pushup(cur);
}

int _query(int &cur, int L, int R, int k) {
	if (!cur) cur = newNode();
	if (L == R) return mem[cur].sum;
	if (k <= mid) return _query(mem[cur].ls, L, mid, k);
	else return _query(mem[cur].rs, mid + 1, R, k);
}

int _kth(int lcnt, int rcnt, int L, int R, int k) {
	if (L == R) return L;
	int x = 0;
	rep (i, 1, rcnt) x += mem[mem[rtr[i]].ls].sum;
	rep (i, 1, lcnt) x -= mem[mem[ltr[i]].ls].sum;
	if (k <= x) {
		rep (i, 1, lcnt) ltr[i] = mem[ltr[i]].ls;
		rep (i, 1, rcnt) rtr[i] = mem[rtr[i]].ls;
		return _kth(lcnt, rcnt, L, mid, k);
	}
	else {
		rep (i, 1, lcnt) ltr[i] = mem[ltr[i]].rs;
		rep (i, 1, rcnt) rtr[i] = mem[rtr[i]].rs;
		return _kth(lcnt, rcnt, mid + 1, R, k - x);
	}
}

int _rnk(int lcnt, int rcnt, int L, int R, int k) {
	if (L == R) return 0;
	int x = 0;
	if (k <= mid) {
		rep (i, 1, lcnt) ltr[i] = mem[ltr[i]].ls;
		rep (i, 1, rcnt) rtr[i] = mem[rtr[i]].ls;
		return _rnk(lcnt, rcnt, L, mid, k);
	}
	else {
		rep (i, 1, rcnt) x += mem[mem[rtr[i]].ls].sum, rtr[i] = mem[rtr[i]].rs;
		rep (i, 1, lcnt) x -= mem[mem[ltr[i]].ls].sum, ltr[i] = mem[ltr[i]].rs;
		return x + _rnk(lcnt, rcnt, mid + 1, R, k);
	}
}

int lowbit(int x) {
	return x & (-x);
}

void add(int x, int val) {
	if (!x) return;
	for (int v = x; v <= n; v += lowbit(v)) {
		update(root[v], 1, N, a[x], val);
	}
}

int kth(int L, int R, int k) {
	int lcnt = 0, rcnt = 0;
	for (int v = R; v; v -= lowbit(v)) {
		rtr[++rcnt] = root[v];
	}
	for (int v = L - 1; v; v -= lowbit(v)) {
		ltr[++lcnt] = root[v];
	}
	return _kth(lcnt, rcnt, 1, N, k);
}

int rnk(int L, int R, int k) {
	int lcnt = 0, rcnt = 0;
	for (int v = R; v; v -= lowbit(v)) {
		rtr[++rcnt] = root[v];
	}
	for (int v = L - 1; v; v -= lowbit(v)) {
		ltr[++lcnt] = root[v];
	}
	return _rnk(lcnt, rcnt, 1, N, k) + 1;
}

int query(int L, int R, int k) {
	int res = 0;
	for (int v = R; v; v -= lowbit(v)) {
		res += _query(root[v], 1, N, k);
	}
	for (int v = L - 1; v; v -= lowbit(v)) {
		res -= _query(root[v], 1, N, k);
	}
	return res;
}

int prev(int L, int R, int k) {
	int rk = rnk(L, R, k) - 1;
	if (rk == 0) return 0;
	else return kth(L, R, rk);
}

int nxt(int L, int R, int k) {
	if (k >= N) return N + 1;
	int rk = rnk(L, R, k + 1);
	if (rk == R - L + 2) return N + 1;
	return kth(L, R, rk);
}

}

struct ops {
	int tp, p, x, l, r;
} op[MAXN];

signed main() {
	n = read(), m = read();
	rep (i, 1, n) {
		a[i] = -read();
		H[++N] = a[i];
	}
	rep (i, 1, m) {
		op[i].tp = read();
		if (op[i].tp == 1) {
			op[i].p = read(), op[i].x = -read();
			H[++N] = op[i].x;
		}
		else {
			op[i].l = read(), op[i].r = read();
		}
	}
	init();
	rep (i, 1, n) a[i] = find(a[i]);
	rep (i, 1, m) if (op[i].tp == 1) op[i].x = find(op[i].x);
	rep (i, 1, n) TIT::add(i, 1);
	rep (i, 1, m) {
		if (op[i].tp == 1) {
			TIT::add(op[i].p, -1);
			a[op[i].p] = op[i].x;
			TIT::add(op[i].p, 1);
		}
		else {
			int vkth = TIT::nxt(op[i].l, op[i].r, TIT::kth(op[i].l, op[i].r, 1));
			if (vkth == N + 1) puts("0");
			else print(TIT::query(op[i].l, op[i].r, vkth)), putchar(10);
		}
	}
	return 0;
}
