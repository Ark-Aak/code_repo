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

const int MAXN = 1e5 + 5;
#define ls(x) p[x].ls
#define rs(x) p[x].rs
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

class Treap {

	struct node { int key, ls, rs, siz; ll val, sum, lazy; } p[MAXN];
	int cnt = 0;

	int newNode(ll val) {
		/* cout << val << endl; */
		p[++cnt].key = rnd();
		p[cnt].val = p[cnt].sum = val;
		p[cnt].siz = 1;
		p[cnt].ls = p[cnt].rs = p[cnt].lazy = 0;
		return cnt;
	}

	void pushup(int x) {
		p[x].sum = p[ls(x)].sum + p[rs(x)].sum + p[x].val;
		p[x].siz = p[ls(x)].siz + p[rs(x)].siz + 1;
	}

	void add(int x, ll val) {
		p[x].val += val;
		p[x].sum += val * p[x].siz;
		p[x].lazy += val;
	}

	void pushdown(int x) {
		if (!x) return;
		if (p[x].lazy) {
			if (ls(x)) add(ls(x), p[x].lazy);
			if (rs(x)) add(rs(x), p[x].lazy);
			p[x].lazy = 0;
		}
	}

public:

	int root = 0;

	void split(int cur, int k, int &x, int &y) {
		if (!cur) return x = y = 0, void();
		pushdown(cur);
		if (p[ls(cur)].siz < k) x = cur, split(rs(cur), k - p[ls(cur)].siz - 1, rs(cur), y);
		else y = cur, split(ls(cur), k, x, ls(cur));
		pushup(cur);
	}

	int merge(int x, int y) {
		if (!x || !y) return x + y;
		if (p[x].key < p[y].key) return pushdown(x), rs(x) = merge(rs(x), y), pushup(x), x;
		else return pushdown(y), ls(y) = merge(x, ls(y)), pushup(y), y;
	}

	void insert(int pos, vector <ll> v) {
		int x = 0, y = 0, rt = 0;
		for (auto i : v) rt = merge(rt, newNode(i));
		split(root, pos, x, y);
		root = merge(merge(x, rt), y);
	}

	void modify(int L, int R, ll val) {
		int x = 0, y = 0, z = 0;
		split(root, L - 1, x, y);
		split(y, R - L + 1, y, z);
		add(y, val);
		root = merge(merge(x, y), z);
	}

	ll query(int L, int R) {
		int x = 0, y = 0, z = 0;
		split(root, L - 1, x, y);
		split(y, R - L + 1, y, z);
		ll res = p[y].sum;
		root = merge(merge(x, y), z);
		return res;
	}
} T;

signed main() {
	int n = read(), m = read();
	vector <ll> v(n);
	rep (i, 1, n) {
		ll t = read();
		v[i - 1] = t;
	}
	T.insert(0, v);
	while (m --> 0) {
		int op = read();
		if (op == 1) {
			int x = read(), y = read();
			ll k = read();
			T.modify(x, y, k);
		}
		else {
			int x = read(), y = read();
			print(T.query(x, y)), puts("");
		}
	}
	return 0;
}
