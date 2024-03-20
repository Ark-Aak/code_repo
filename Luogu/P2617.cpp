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
const int MAXN = 5e5 + 5, MAXM = MAXN << 5;

int H[MAXN];
int N;

void init() {
	sort(H + 1, H + 1 + N);
	N = unique(H + 1, H + N + 1) - H - 1;
}

int find(int x) {
	return lower_bound(H + 1, H + 1 + N, x) - H;
}

int n, m, cnt;
int a[MAXN];

struct node {
	node *ls, *rs;
	int sum;

	node() {ls = nullptr, rs = nullptr, sum = 0;}
};

node* null = new node();

node* newNode() {
    node* nd = new node();
    nd -> ls = null, nd -> rs = null, nd -> sum = 0;
	return nd;
}

node *root[MAXN];

node *ltr[MAXN], *rtr[MAXN];

#define mid ((L + R) >> 1)

void update(node* &cur, int L, int R, int k, int val) {
	if (!cur || cur == null) cur = newNode();
	if (L == R) return (void) (cur -> sum += val);
	if (k <= mid) update(cur -> ls, L, mid, k, val);
	else update(cur -> rs, mid + 1, R, k, val);
	cur -> sum = 0;
	cur -> sum += cur -> ls -> sum;
	cur -> sum += cur -> rs -> sum;
}

int _kth(int lcnt, int rcnt, int L, int R, int k) {
	if (L == R) return L;
	int x = 0;
	rep (i, 1, rcnt) x += rtr[i] -> ls -> sum;
	rep (i, 1, lcnt) x -= ltr[i] -> ls -> sum;
	if (k <= x) {
		rep (i, 1, lcnt) ltr[i] = ltr[i] -> ls;
		rep (i, 1, rcnt) rtr[i] = rtr[i] -> ls;
		return _kth(lcnt, rcnt, L, mid, k);
	}
	else {
		rep (i, 1, lcnt) ltr[i] = ltr[i] -> rs;
		rep (i, 1, rcnt) rtr[i] = rtr[i] -> rs;
		return _kth(lcnt, rcnt, mid + 1, R, k - x);
	}
}

int _rnk(int lcnt, int rcnt, int L, int R, int k) {
	if (L == R) return 0;
	int x = 0;
	if (k <= mid) {
		rep (i, 1, lcnt) ltr[i] = ltr[i] -> ls;
		rep (i, 1, rcnt) rtr[i] = rtr[i] -> ls;
		return _rnk(lcnt, rcnt, L, mid, k);
	}
	else {
		rep (i, 1, rcnt) x += rtr[i] -> ls -> sum, rtr[i] = rtr[i] -> rs;
		rep (i, 1, lcnt) x -= ltr[i] -> ls -> sum, ltr[i] = ltr[i] -> rs;
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

struct ops {
	int l, r, pos, k;
	char op;
} op[MAXN];

signed main() {
    null -> ls = null;
    null -> rs = null;
	read(n), read(m);
	rep (i, 1, n) {
		read(a[i]);
		H[++N] = a[i];
	}
	rep (i, 1, m) {
		char ch = getchar();
		while (!isalpha(ch)) ch = getchar();
		op[i].op = ch;
		if (ch == 'Q') read(op[i].l), read(op[i].r), read(op[i].k);
		else read(op[i].pos), read(op[i].k), H[++N] = op[i].k;
	}
	init();
	H[0] = (-2147483647);
	H[N + 1] = (2147483647);
	rep (i, 1, n) {
		a[i] = find(a[i]);
		add(i, 1);
	}
	rep (i, 1, m) if (op[i].op != 'Q') op[i].k = find(op[i].k);
	rep (i, 1, m) {
		int op, l, r, pos, k;
		op = ::op[i].op;
		switch (op) {
			case 'Q':
				l = ::op[i].l, r = ::op[i].r, k = ::op[i].k;
				print(H[kth(l, r, k)]), putchar(10);
				break;
			default:
				pos = ::op[i].pos, k = ::op[i].k;
				add(pos, -1);
				a[pos] = k;
				add(pos, 1);
				break;
		}
	}
	return 0;
}
