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

const int MAXN = 6e5 + 5;

namespace LCT {
	int rt, tot, fa[MAXN], ch[MAXN][2], val[MAXN], cnt[MAXN];
	int XOR[MAXN], tag[MAXN];

#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
#define get(x) ((x) == ch[fa[x]][1])
#define isRoot(x) (ch[fa[x]][0] != x && ch[fa[x]][1] != x)

	inline void pushup(int x) {
		XOR[x] = XOR[ls(x)] ^ XOR[rs(x)] ^ val[x];
	}

	inline void reverse(int x) { swap(ls(x), rs(x)), tag[x] ^= 1; }

	inline void pushdown(int x) {
		if (tag[x]) {
			if (ls(x)) reverse(ls(x));
			if (rs(x)) reverse(rs(x));
			tag[x] = 0;
		}
	}

	void rotate(int x) {
		int y = fa[x], z = fa[y], k = ch[y][1] == x, w = ch[x][!k];
		if (!isRoot(y)) ch[z][ch[z][1] == y] = x;
		ch[x][!k] = y, ch[y][k] = w;
		if (w) fa[w] = y;
		fa[y] = x, fa[x] = z;
		pushup(y), pushup(x);
	}

	void pushall(int x) {
		if (!isRoot(x)) pushall(fa[x]);
		pushdown(x);
	}

	void splay(int x) {
		int y = x, z = 0;
		pushall(x);
		while (!isRoot(x)) {
			y = fa[x], z = fa[y];
			if (!isRoot(y))
				rotate((ls(y) == x) ^ (ls(z) == y) ? x : y);
			rotate(x);
		}
		pushup(x);
	}

	void access(int x) { for (int y = 0; x; x = fa[y = x]) splay(x), rs(x) = y, pushup(x); }
	inline void makeRoot(int x) { access(x), splay(x), reverse(x); }

	inline int find(int x) {
		access(x), splay(x);
		while (ls(x)) pushdown(x), x = ls(x);
		splay(x);
		return x;
	}

	inline void split(int x, int y) { makeRoot(x), access(y), splay(y); }
	inline void link(int x, int y) { makeRoot(x); if (find(y) != x) fa[x] = y; }

	inline void cut(int x, int y) {
		split(x, y);
		if (find(y) == x && fa[y] == x && !ls(y)) {
			fa[y] = rs(x) = 0;
			pushup(x);
		}
	}
#undef ls
#undef rs
#undef get
#undef isRoot
} // namespace LCT

int n, m, q;
int cnt = 0;

struct edge {
	int u, v;
};

int lst[MAXN];
unordered_map <int, int> mp[200005], it[200005];
int pt[MAXN];

struct Basis {
	vector <int> B;

	Basis() { B.clear(); }

	void insert(int x) {
		for (auto v : B) x = min(x, x ^ v);
		if (!x) return;
		for (auto &v : B) v = min(v , v ^ x);
		B.push_back(x);
	}

	int query(int x) {
		for (auto v : B) x = min(x, x ^ v);
		return x;
	}
};

namespace seg {
	vector <int> v[MAXN << 2];
	edge e[MAXN];
	pii q[MAXN];
	bool vis[MAXN];
	int ans[MAXN];
	stack <pii> stk;

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

	void insert(int x, int L, int R, int l, int r, int id) {
		if (l > r) return;
		if (l <= L && R <= r) return v[x].push_back(id), void();
		if (l <= mid) insert(ls(x), L, mid, l, r, id);
		if (r > mid) insert(rs(x), mid + 1, R, l, r, id);
	}

	void solve(int x, int L, int R, Basis basis, int siz = 0) {
		siz = stk.size();
		for (auto id : v[x]) {
			int u = e[id].u, v = e[id].v;
			if (LCT::find(u) == LCT::find(v)) {
				LCT::split(u, v);
				int val = LCT::XOR[v];
				val ^= LCT::val[id];
				basis.insert(val);
				continue;
			}
			LCT::link(u, id), LCT::link(v, id);
			stk.push(dl(u, id)), stk.push(dl(v, id));
		}
		if (L == R && vis[L]) {
			LCT::split(q[L].ec, q[L].fb);
			/* ans[L] = LCT::XOR[q[L].fb]; */
			ans[L] = basis.query(LCT::XOR[q[L].fb]);
		}
		if (L != R) {
			solve(ls(x), L, mid, basis);
			solve(rs(x), mid + 1, R, basis);
		}
		while ((int) stk.size() > siz) {
			int u = stk.top().ec, v = stk.top().fb;
			stk.pop();
			LCT::cut(u, v);
		}
	}
}

int main() {
	n = read(), m = read();
	rep (i, 1, m) {
		int u = read(), v = read(), w = read();
		lst[i] = 1;
		LCT::val[i + n] = w;
		seg::e[i + n].u = u, seg::e[i + n].v = v;
		mp[u][v] = mp[v][u] = i;
		it[u][v] = it[v][u] = i + n;
		pt[i] = i + n;
	}
	q = read();
	rep (i, 1, q) {
		int op = read(), x = read(), y = read(), d;
		if (op == 1) {
			d = read();
			LCT::val[i + n + m] = d;
			seg::e[i + n + m].u = x;
			seg::e[i + n + m].v = y;
			lst[i + m] = i;
			mp[x][y] = mp[y][x] = i + m;
			it[x][y] = it[y][x] = i + n + m;
			pt[i + m] = i + n + m;
		}
		else if (op == 2) {
			seg::insert(1, 1, m, lst[mp[x][y]], i - 1, it[x][y]);
			lst[mp[x][y]] = 0;
		}
		else {
			seg::vis[i] = 1;
			seg::q[i].ec = x, seg::q[i].fb = y;
		}
	}
	rep (i, 1, n + m + q) if (lst[i]) seg::insert(1, 1, m, lst[i], m, pt[i]);
	seg::solve(1, 1, m, Basis());
	rep (i, 1, m) if (seg::vis[i]) print(seg::ans[i]), putchar(10);
	return 0;
}
