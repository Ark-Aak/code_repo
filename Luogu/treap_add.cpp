#include <bits/stdc++.h>

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

const int MAXN = 5e5 + 5;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define ls(x) p[x].ls
#define rs(x) p[x].rs

class Treap {

public:
	struct node { int val, key, siz, ls, rs, sum, lazy, rev, lmax, rmax, mx; } p[MAXN];
	int cnt = 0;

	stack <int> _R;

	inline int newNode(int val) {
		int x = 0;
		if (!_R.empty()) {
			x = _R.top(), _R.pop();
			if (ls(x)) _R.push(ls(x));
			if (rs(x)) _R.push(rs(x));
		}
		else x = ++cnt;
		/* x = ++cnt; */
		p[x].val = val, p[x].key = rnd(), p[x].siz = 1;
		p[x].ls = p[x].rs = p[x].lazy = p[x].rev = 0;
		p[x].lmax = p[x].rmax = max(val, 0);
		p[x].mx = val, p[x].sum = val;
		return x;
	}

	void reverse(int x) {
		if (!x) return;
		swap(ls(x), rs(x));
		swap(p[x].lmax, p[x].rmax);
		p[x].rev ^= 1;
	}

	void cover(int x, int val) {
		if (!x) return;
		p[x].val = val;
		p[x].lazy = 1;
		p[x].sum = p[x].siz * val;
		p[x].lmax = p[x].rmax = max(0, p[x].sum);
		p[x].mx = max(p[x].sum, val);
	}

	inline void pushup(int x) {
		if (!x) return;
		p[x].siz = p[ls(x)].siz + p[rs(x)].siz + 1;
		p[x].sum = p[ls(x)].sum + p[rs(x)].sum + p[x].val;
		p[x].lmax = max(0, max(p[ls(x)].lmax, p[ls(x)].sum + p[x].val + p[rs(x)].lmax));
		p[x].rmax = max(0, max(p[rs(x)].rmax, p[rs(x)].sum + p[x].val + p[ls(x)].rmax));
		p[x].mx = max(p[ls(x)].rmax + p[rs(x)].lmax, 0) + p[x].val;
		if (ls(x)) p[x].mx = max(p[x].mx, p[ls(x)].mx);
		if (rs(x)) p[x].mx = max(p[x].mx, p[rs(x)].mx);
	}

	inline void pushdown(int x) {
		if (p[x].rev) {
			if (ls(x)) reverse(ls(x));
			if (rs(x)) reverse(rs(x));
			p[x].rev ^= 1;
		}
		if (p[x].lazy) {
			if (ls(x)) cover(ls(x), p[x].val);
			if (rs(x)) cover(rs(x), p[x].val);
			p[x].lazy = 0;
		}
	}

	void split(int cur, int k, int &x, int &y) {
		if (!cur) return x = y = 0, void();
		pushdown(cur);
		if (p[ls(cur)].siz < k) x = cur, split(rs(cur), k - p[ls(cur)].siz - 1, rs(cur), y);
		else y = cur, split(ls(cur), k, x, ls(cur));
		pushup(cur);
	}

	int merge(int x, int y) {
		if (!x || !y) return x + y;
		if (p[x].key < p[y].key) {
			pushdown(x);
			rs(x) = merge(rs(x), y);
			pushup(x);
			return x;
		}
		else {
			pushdown(y);
			ls(y) = merge(x, ls(y));
			pushup(y);
			return y;
		}
	}

	int root = 0;

	void insert(int pos, vector <int> v) {
		int rt = 0;
		for (auto i : v) rt = merge(rt, newNode(i));
		int x, y;
		split(root, pos, x, y);
		root = merge(merge(x, rt), y);
	}

	void remove(int L, int R) {
		int x, y, z;
		split(root, L - 1, x, y);
		split(y, R - L + 1, y, z);
		_R.push(y);
		root = merge(x, z);
	}

	void set(int L, int R, int val) {
		int x, y, z;
		split(root, L - 1, x, y);
		split(y, R - L + 1, y, z);
		cover(y, val);
		root = merge(merge(x, y), z);
	}

	void reverse(int L, int R) {
		int x, y, z;
		split(root, L - 1, x, y);
		split(y, R - L + 1, y, z);
		reverse(y);
		root = merge(merge(x, y), z);
	}

	int querySum(int L, int R) {
		int x, y, z;
		split(root, L - 1, x, y);
		split(y, R - L + 1, y, z);
		int res = p[y].sum;
		root = merge(merge(x, y), z);
		return res;
	}

	int queryMax() {
		/* querySum(1, 1); */
		return p[root].mx;
	}
} T;

signed main() {
	/* freopen("treap.in", "r", stdin); */
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m, x;
	cin >> n >> m;
	rep (i, 1, n) cin >> x, T.insert(i - 1, { x });
	rep (i, 1, m) {
		string op;
		int l, r, c;
		cin >> op;
		if (op == "GET-SUM") {
			cin >> l >> r;
			print(T.querySum(l, l + r - 1)), puts("");
		}
		if (op == "MAX-SUM") {
			/* T.pushup(T.root); */
			print(T.queryMax()), puts("");
		}
		if (op == "MAKE-SAME") {
			cin >> l >> r >> c;
			T.set(l, l + r - 1, c);
		}
		if (op == "REVERSE") {
			cin >> l >> r;
			T.reverse(l, l + r - 1);
		}
		if (op == "INSERT") {
			int pos, k, tv;
			cin >> pos >> k;
			vector <int> v;
			rep (i, 1, k) cin >> tv, v.push_back(tv);
			T.insert(pos, v);
		}
		if (op == "DELETE") {
			cin >> l >> r;
			T.remove(l, l + r - 1);
		}
	}
	return 0;
}
