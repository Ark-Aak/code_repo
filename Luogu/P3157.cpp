#include <bits/stdc++.h>

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

#define int ll
const int MAXN = 5e5 + 5, MAXM = MAXN << 5;

int n, m, cnt;
int a[MAXN];

struct node {
	node *ls, *rs;
	int sum;
	node() { ls = nullptr, rs = nullptr, sum = 0; }
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

int lowbit(int x) { return x & (-x); }

void add(int x, int val) {
	if (!x) return;
	for (int v = x; v <= n; v += lowbit(v))
		update(root[v], 1, n, a[x], val);
}

int rnk(int L, int R, int k) {
	int lcnt = 0, rcnt = 0;
	for (int v = R; v; v -= lowbit(v)) rtr[++rcnt] = root[v];
	for (int v = L - 1; v; v -= lowbit(v)) ltr[++lcnt] = root[v];
	return _rnk(lcnt, rcnt, 1, n, k) + 1;
}

signed main() {
    null -> ls = null;
    null -> rs = null;
	n = read(), m = read();
	rep (i, 1, n) a[i] = read(), add(i, a[i]);

	return 0;
}
