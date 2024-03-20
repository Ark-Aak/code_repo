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

const int MAXN = 2e5 + 5;
int n, m;

namespace LCT {
	int rt, tot, fa[MAXN], ch[MAXN][2], val[MAXN], cnt[MAXN];
	int mx[MAXN], tag[MAXN];

#define ls(x) ch[x][0]
#define rs(x) ch[x][1]
#define get(x) ((x) == ch[fa[x]][1])
#define isRoot(x) (ch[fa[x]][0] != x && ch[fa[x]][1] != x)

	inline void pushup(int x) {
		mx[x] = val[mx[ls(x)]] > val[mx[rs(x)]] ? mx[ls(x)] : mx[rs(x)];
		mx[x] = val[x] > val[mx[x]] ? x : mx[x];
	}

	inline void reverse(int x) {swap(ls(x), rs(x)), tag[x] ^= 1;}

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

	void access(int x) {
		for (int y = 0; x; x = fa[y = x])
			splay(x), rs(x) = y, pushup(x);
	}

	inline void makeRoot(int x) {
		access(x), splay(x), reverse(x);
	}

	inline int find(int x) {
		access(x), splay(x);
		while (ls(x)) pushdown(x), x = ls(x);
		splay(x);
		return x;
	}

	inline void split(int x, int y) {
		makeRoot(x), access(y), splay(y);
	}

	inline void link(int x, int y) {
		//cout << "link " << x << " and " << y << endl;
		makeRoot(x);
		if (find(y) != x) fa[x] = y;
	}

	inline void cut(int x, int y) {
		//cout << "cut " << x << " and " << y << endl;
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

using LCT::val, LCT::mx;

int Sum;

namespace seg {
	struct edge {int u, v;};
	vector <int> edges[MAXN << 2];
	stack <pii> stk;
	edge e[MAXN];
	int ans[MAXN];

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

	void insert(int x, int L, int R, int l, int r, int eid) {
		if (l == 0 || r == 0) return;
		/* if (x == 1) { */
			/* cout << "insert:" << l << " " << r << " " << eid << " " << val[eid] << endl; */
		/* } */
		if (l <= L && R <= r) return (void) edges[x].push_back(eid);
		if (l <= mid) insert(ls(x), L, mid, l, r, eid);
		if (r > mid) insert(rs(x), mid + 1, R, l, r, eid);
	}

	void solve(int x, int L, int R, int sz = 0) {
		sz = stk.size();
		for (auto _e : edges[x]) {
			int u = e[_e].u, v = e[_e].v;
			if (LCT::find(u) == LCT::find(v)) {
				LCT::split(u, v);
				/*
				cout << "Value:" << endl;
				rep (i, 1, n + m) {
					cout << mx[i] << " " << val[mx[i]] << endl;
				}
				*/
				if (val[mx[v]] <= val[_e]) continue;
				stk.push(make_pair(_e, mx[v]));
				int _mx = mx[v];
				//cout << "cut1: " << e[_mx].u << " <-> " << e[_mx].v << " val_e = " << val[_e] << " mx = " << val[mx[v]] << endl;
				LCT::cut(e[_mx].u, _mx), LCT::cut(e[_mx].v, _mx);
				Sum -= val[_mx];
				LCT::link(u, _e), LCT::link(v, _e);
				Sum += val[_e];
			}
			else {
				Sum += val[_e];
				stk.push(make_pair((LCT::link(u, _e), _e), (LCT::link(v, _e), -1)));
			}
		}
		if (L == R) {
			ans[L] = Sum;
		}
		if (L != R) {
			solve(ls(x), L, mid);
			solve(rs(x), mid + 1, R);
		}
		while ((int) stk.size() > sz) {
			auto modify = stk.top(); stk.pop();
			int u = modify.first, v = modify.second;
			LCT::cut(e[u].u, u), LCT::cut(e[u].v, u);
			Sum -= val[u];
			if (~v) LCT::link(e[v].u, v), LCT::link(e[v].v, v), Sum += val[v];
			//if (~v) cout << "cut2: " << u << " <-> " << v << endl;
		}
	}
} // namespace seg

int q;
int last[MAXN], lastval[MAXN];

signed main() {
	n = read(), m = read(), q = read();
	rep (i, 1, m) {
		int u = read(), v = read(), w = read();
		val[n + i] = w;
		lastval[i] = w;
		last[i] = 1;
		seg::e[n + i].u = u, seg::e[n + i].v = v;
		/* seg::insert(1, 1, 50000, t, t + y, n + i); */
	}
	rep (i, 1, q) {
		int k = read(), d = read();
		val[n + m + i] = lastval[k];
		seg::e[n + m + i] = seg::e[n + k];
		seg::insert(1, 1, 50000, last[k], i - 1, n + m + i);
		last[k] = i;
		lastval[k] = d;
	}
	rep (i, 1, m) {
		val[n + m + q + i] = lastval[i];
		seg::e[n + m + q + i] = seg::e[n + i];
		seg::insert(1, 1, 50000, last[i], q, n + m + q + i);
	}
	seg::solve(1, 1, 50000);
	rep (i, 1, q) print(seg::ans[i]), putchar(10);
	return 0;
}
