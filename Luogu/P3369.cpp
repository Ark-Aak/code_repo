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
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

#define ls(x) p[x].ls
#define rs(x) p[x].rs

class Treap {

	struct node { int val, key, siz, ls, rs; } p[MAXN];
	int cnt = 0;

	inline int newNode(int val) {
		p[++cnt].key = rnd();
		p[cnt].val = val;
		p[cnt].siz = 1;
		return cnt;
	}

	inline void pushup(int x) {
		p[x].siz = p[ls(x)].siz + p[rs(x)].siz + 1;
	}

public:
	int root = 0;

	void split(int cur, int k, int &x, int &y) {
		if (!cur) return x = y = 0, void();
		if (p[cur].val <= k) x = cur, split(rs(x), k, rs(x), y);
		else y = cur, split(ls(y), k, x, ls(y));
		pushup(cur);
	}

	int merge(int u, int v) {
		if (!u || !v) return u + v;
		if (p[u].key < p[v].key) return rs(u) = merge(rs(u), v), pushup(u), u;
		else return ls(v) = merge(u, ls(v)), pushup(v), v;
	}

	inline void insert(int val, int lt = 0, int rt = 0) {
		split(root, val, lt, rt);
		root = merge(merge(lt, newNode(val)), rt);
	}

	inline void remove(int val, int lt = 0, int mt = 0, int rt = 0) {
		split(root, val, lt, rt);
		split(lt, val - 1, lt, mt);
		mt = merge(ls(mt), rs(mt));
		root = merge(merge(lt, mt), rt);
	}

	inline int rnk(int val, int lt = 0, int rt = 0) {
		split(root, val - 1, lt, rt);
		int res = p[lt].siz + 1;
		root = merge(lt, rt);
		return res;
	}

	inline int kth(int cur, int val) {
		while (cur) {
			if (p[ls(cur)].siz + 1 == val) return p[cur].val;
			if (p[ls(cur)].siz >= val) cur = ls(cur);
			else val -= p[ls(cur)].siz + 1, cur = rs(cur);
		}
		return 0;
	}

	inline int pre(int val, int lt = 0, int rt = 0, int res = 0) {
		split(root, val - 1, lt, rt);
		if (lt) res = kth(lt, p[lt].siz);
		root = merge(lt, rt);
		return res;
	}

	inline int nxt(int val, int lt = 0, int rt = 0, int res = 0) {
		split(root, val, lt, rt);
		if (rt) res = kth(rt, 1);
		root = merge(lt, rt);
		return res;
	}
} T;

signed main() {
	int n = read();
	rep (i, 1, n) {
		int op = read();
		if (op == 1) T.insert(read());
		if (op == 2) T.remove(read());
		if (op == 3) print(T.rnk(read())), puts("");
		if (op == 4) print(T.kth(T.root, read())), puts("");
		if (op == 5) print(T.pre(read())), puts("");
		if (op == 6) print(T.nxt(read())), puts("");
	}
	return 0;
}
