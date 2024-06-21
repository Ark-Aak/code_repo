#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

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

const int MAXN = 5e5 + 5;

struct node {
	int sum, ls, rs;
} p[MAXN << 5];

int _cnt, root[MAXN];
inline int newNode() { return ++_cnt; }

#define ls(x) p[x].ls
#define rs(x) p[x].rs
#define mid ((L + R) >> 1)

void pushup(int x) {
	p[x].sum = p[ls(x)].sum + p[rs(x)].sum;
}

void update(int &cur, int L, int R, int k, int val) {
	if (!cur) cur = newNode();
	if (L == R) return void(p[cur].sum += val);
	if (k <= mid) update(ls(cur), L, mid, k, val);
	else update(rs(cur), mid + 1, R, k, val);
	pushup(cur);
}

int ltr[MAXN], rtr[MAXN];

int kth(int lc, int rc, int L, int R, int k) {
	if (L == R) return L;
	int x = 0;
	rep (i, 1, rc) x += p[ls(rtr[i])].sum;
	rep (i, 1, lc) x -= p[ls(ltr[i])].sum;
	if (k <= x) {
		rep (i, 1, lc) ltr[i] = p[ltr[i]].ls;
		rep (i, 1, rc) rtr[i] = p[rtr[i]].ls;
		return kth(lc, rc, L, mid, k);
	}
	else {
		rep (i, 1, lc) ltr[i] = p[ltr[i]].rs;
		rep (i, 1, rc) rtr[i] = p[rtr[i]].rs;
		return kth(lc, rc, mid + 1, R, k - x);
	}
}

int rnk(int lc, int rc, int L, int R, int k) {
	if (L == R) return 0;
	if (k <= mid) {
		rep (i, 1, lc) ltr[i] = p[ltr[i]].ls;
		rep (i, 1, rc) rtr[i] = p[rtr[i]].ls;
		return rnk(lc, rc, L, mid, k);
	}
	else {
		int x = 0;
		rep (i, 1, rc) x += p[ls(rtr[i])].sum;
		rep (i, 1, lc) x -= p[ls(ltr[i])].sum;
		rep (i, 1, lc) ltr[i] = p[ltr[i]].rs;
		rep (i, 1, rc) rtr[i] = p[rtr[i]].rs;
		return x + rnk(lc, rc, mid + 1, R, k);
	}
}

const int N = 1e8;

int n, m, a[MAXN];

inline int lowbit(int x) { return x & -x; }

void add(int x, int val) {
	if (!x) return;
	for (int v = x; v <= n; v += lowbit(v)) {
		update(root[v], 0, N, a[x], val);
	}
}

int kth(int L, int R, int k) {
	int lc = 0, rc = 0;
	for (int v = R; v; v -= lowbit(v)) {
		rtr[++rc] = root[v];
	}
	for (int v = L - 1; v; v -= lowbit(v)) {
		ltr[++lc] = root[v];
	}
	return kth(lc, rc, 0, N, k);
}

int rnk(int L, int R, int k) {
	int lc = 0, rc = 0;
	for (int v = R; v; v -= lowbit(v)) {
		rtr[++rc] = root[v];
	}
	for (int v = L - 1; v; v -= lowbit(v)) {
		ltr[++lc] = root[v];
	}
	return rnk(lc, rc, 0, N, k) + 1;
}

int prev(int L, int R, int k) {
	int rk = rnk(L, R, k) - 1;
	if (rk == 0) return -2147483647;
	return kth(L, R, rk);
}

int nxt(int L, int R, int k) {
	if (k >= N) return 2147483647;
	int rk = rnk(L, R, k + 1);
	if (rk == R - L + 2) return 2147483647;
	return kth(L, R, rk);
}

signed main() {
	n = read(), m = read();
	rep (i, 1, n) a[i] = read(), add(i, 1);
	rep (i, 1, m) {
		int op = read();
		int l = 0, r = 0, k = 0, pos = 0;
		if (op == 1) {
			l = read(), r = read(), k = read();
			print(rnk(l, r, k)), puts("");
		}
		else if (op == 2) {
			l = read(), r = read(), k = read();
			print(kth(l, r, k)), puts("");
		}
		else if (op == 3) {
			pos = read(), k = read();
			add(pos, -1);
			a[pos] = k;
			add(pos, 1);
		}
		else if (op == 4) {
			l = read(), r = read(), k = read();
			print(prev(l, r, k)), puts("");
		}
		else {
			l = read(), r = read(), k = read();
			print(nxt(l, r, k)), puts("");
		}
	}
	return 0;
}
