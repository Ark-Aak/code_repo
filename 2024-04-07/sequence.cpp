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

const int MOD = 1e9 + 7;
inline void inc(int &x, int y) { x = ((ll) x + y >= MOD ? ((ll) x + y - MOD) : (ll) x + y < 0 ? (ll) x + y + MOD : (ll) x + y); }

const int MAXN = 1e5 + 5;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct node { int key, ls, rs, siz, val, sum, lazy, len; } p[MAXN << 4];
int cnt = 0, bst[MAXN];

namespace Treap {

#define ls(x) p[x].ls
#define rs(x) p[x].rs

	int newNode(int val, int len) {
		p[++cnt].key = rnd();
		p[cnt].val = val;
		p[cnt].sum = val * len % MOD;
		p[cnt].len = len;
		p[cnt].siz = len;
		p[cnt].ls = p[cnt].rs = p[cnt].lazy = 0;
		return cnt;
	}

	void pushup(int x) {
		p[x].siz = p[ls(x)].siz + p[rs(x)].siz + p[x].len, p[x].sum = 0;
		inc(p[x].sum, p[ls(x)].sum), inc(p[x].sum, p[rs(x)].sum);
		inc(p[x].sum, p[x].val * p[x].len % MOD);
	}

	void add(int x, int val) {
		inc(p[x].val, val);
		inc(p[x].sum, val * p[x].siz % MOD);
		inc(p[x].lazy, val);
	}

	void pushdown(int x) {
		if (!x) return;
		if (p[x].lazy) {
			if (ls(x)) add(ls(x), p[x].lazy);
			if (rs(x)) add(rs(x), p[x].lazy);
			p[x].lazy = 0;
		}
	}

	int merge(int x, int y) {
		if (!x || !y) return x + y;
		if (p[x].key < p[y].key) return pushdown(x), rs(x) = merge(rs(x), y), pushup(x), x;
		else return pushdown(y), ls(y) = merge(x, ls(y)), pushup(y), y;
	}

	void cut(int cur, int k, int &x, int &y) {
		assert(p[cur].len >= k);
		int lt = ls(cur), rt = rs(cur);
		ls(cur) = rs(cur) = 0;
		int part0 = newNode(p[cur].val, k);
		p[cur].len -= k;
		int part1 = cur;
		pushup(part0), pushup(part1);
		x = merge(lt, part0), y = merge(part1, rt);
	}

	void split(int cur, int k, int &x, int &y) {
		if (!cur) return x = y = 0, void();
		pushdown(cur);
		if (p[ls(cur)].siz + p[cur].len <= k)
			x = cur, split(rs(cur), k - p[ls(cur)].siz - p[cur].len, rs(cur), y);
		else if (p[ls(cur)].siz >= k)
			y  = cur, split(ls(cur), k, x, ls(cur));
		else cut(cur, k - p[ls(cur)].siz, x, y);
		pushup(cur);
	}

	void modify(int &root, int val) { add(root, val); }

	void modify(int &root, int L, int R, int val) {
		int x = 0, y = 0, z = 0;
		split(root, L - 1, x, y);
		split(y, R - L + 1, y, z);
		add(y, val);
		root = merge(merge(x, y), z);
	}

	int query(int &root, int L, int R) {
		int x = 0, y = 0, z = 0;
		split(root, L - 1, x, y);
		split(y, R - L + 1, y, z);
		int res = p[y].sum;
		root = merge(merge(x, y), z);
		return res;
	}

#undef ls
#undef rs

};

int n, m, k;

namespace Seg {

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

	int addr[MAXN << 2], sum[MAXN << 2], lazy[MAXN << 2], len[MAXN << 2];

	void pushup(int x) {
		len[x] = len[ls(x)] + len[rs(x)];
		addr[x] = 0, inc(addr[x], addr[ls(x)]), inc(addr[x], addr[rs(x)]);
		sum[x] = 0, inc(sum[x], sum[ls(x)]), inc(sum[x], sum[rs(x)]);
	}

	void pushdown(int x, int L, int R) {
		if (lazy[x]) {
			inc(addr[ls(x)], lazy[x] % MOD);
			inc(addr[rs(x)], lazy[x] % MOD);
			inc(sum[ls(x)], lazy[x] * len[ls(x)] % MOD);
			inc(sum[rs(x)], lazy[x] * len[rs(x)] % MOD);
			inc(lazy[ls(x)], lazy[x]), inc(lazy[rs(x)], lazy[x]);
			lazy[x] = 0;
		}
	}

	void build(int x, int L, int R) {
		addr[x] = 0, lazy[x] = 0, sum[x] = 0, len[x] = n;
		if (L == R) return;
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
		pushup(x);
	}

	void modify(int x, int L, int R, int l, int r, int val) {
		if (l <= L && R <= r) {
			inc(addr[x], val);
			inc(sum[x], val * len[x] % MOD);
			inc(lazy[x], val);
			return;
		}
		pushdown(x, L, R);
		if (l <= mid) modify(ls(x), L, mid, l, r, val);
		if (r > mid) modify(rs(x), mid + 1, R, l, r, val);
		pushup(x);
	}

	void modifyps(int x, int L, int R, int pos, int val, int op) {
		if (L == R) return op ? inc(sum[x], val), 0 : len[x] += val, void();
		pushdown(x, L, R);
		if (pos <= mid) modifyps(ls(x), L, mid, pos, val, op);
		else modifyps(rs(x), mid + 1, R, pos, val, op);
		pushup(x);
	}

	int query(int x, int L, int R, int l, int r) {
		if (l <= L && R <= r) return sum[x];
		pushdown(x, L, R);
		int res = 0;
		if (l <= mid) inc(res, query(ls(x), L, mid, l, r));
		if (r > mid) inc(res, query(rs(x), mid + 1, R, l, r));
		pushup(x);
		return res;
	}

	int queryps(int x, int L, int R, int pos, int op) {
		if (L == R) return op ? len[x] : addr[x];
		pushdown(x, L, R);
		int res = 0;
		if (pos <= mid) res = queryps(ls(x), L, mid, pos, op);
		else res = queryps(rs(x), mid + 1, R, pos, op);
		pushup(x);
		return res;
	}

#undef ls
#undef rs
#undef mid

} // namespace Seg

void ops1(int i, int L, int R, int val) {
	Seg::modifyps(1, 1, m, i, val * (R - L + 1) % MOD, 1);
	Treap::modify(bst[i], L, R, val);
}

int ops2(int i, int L, int R) {
	int res = Treap::query(bst[i], L, R);
	inc(res, Seg::queryps(1, 1, m, i, 0) * (R - L + 1) % MOD);
	return res;
}

int ops3(int L, int R) { return Seg::query(1, 1, m, L, R); }
void ops4(int L, int R, int val) { Seg::modify(1, 1, m, L, R, val); }

void ops5(int i, int L, int R, int j, int t) {
	int x = 0, y = 0, z = 0;
	Treap::split(bst[i], L - 1, x, y);
	Treap::split(y, R - L + 1, y, z);
	bst[i] = Treap::merge(x, z);
	int x2 = 0, y2 = 0;
	Treap::modify(y, Seg::queryps(1, 1, m, i, 0));
	int sum = p[y].sum;
	Treap::modify(y, -Seg::queryps(1, 1, m, j, 0));
	Treap::split(bst[j], t, x2, y2);
	bst[j] = Treap::merge(Treap::merge(x2, y), y2);
	Seg::modifyps(1, 1, m, i, -(R - L + 1), 0);
	Seg::modifyps(1, 1, m, j, R - L + 1, 0);
	Seg::modifyps(1, 1, m, i, -sum, 1);
	Seg::modifyps(1, 1, m, j, sum, 1);
}

signed main() {
#ifdef LOCAL
	freopen("test.in", "r", stdin);
#endif
	n = read(), m = read(), k = read();
	Seg::build(1, 1, m);
	rep (i, 1, m) bst[i] = Treap::newNode(0, n);
	while (k --> 0) {
		int op = read();
		if (op == 1) {
			int i = read(), L = read(), R = read(), val = read();
			ops1(i, L, R, val);
		}
		else if (op == 2) {
			int i = read(), L = read(), R = read();
			print(ops2(i, L, R)), puts("");
		}
		else if (op == 3) {
			int L = read(), R = read();
			print(ops3(L, R)), puts("");
		}
		else if (op == 4) {
			int L = read(), R = read(), val = read();
			ops4(L, R, val);
		}
		else if (op == 5) {
			int i = read(), L = read(), R = read(), j = read(), t = read();
			ops5(i, L, R, j, t);
		}
	}
	return 0;
}
