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

const int MAXN = 2e5 + 5;

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
	void pushall(int x) { if (!isRoot(x)) pushall(fa[x]); pushdown(x); }
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
		if (find(y) == x && fa[y] == x && !ls(y))
			fa[y] = rs(x) = 0, pushup(x);
	}
#undef ls
#undef rs
#undef get
#undef isRoot
} // namespace LCT

struct operation {
	int k, u, v;
} Q[MAXN];

int n, m, q;
map <pair <int, int>, bool> vis;
map <pair <int, int>, int> id;
vector <tuple <int, int, int, int> > edges;
int u[MAXN], v[MAXN];
stack <int> stk;

int main() {
	freopen("P4172_2.in", "r", stdin);
	freopen("P4172_2.out", "w", stdout);
	n = read(), m = read(), q = read();
	rep (i, 1, m) {
		int u = read(), v = read(), t = read();
		edges.push_back(make_tuple(u, v, t, i));
		id[make_pair(u, v)] = i;
		id[make_pair(v, u)] = i;
		::u[n + i] = u, ::v[n + i] = v;
		LCT::val[n + i] = t;
	}
	rep (i, 1, q) {
		int k = read(), u = read(), v = read();
		if (k == 2) vis[make_pair(u, v)] = true;
		if (k == 2) vis[make_pair(v, u)] = true;
		Q[i] = (operation) {k, u, v};
	}
	sort(edges.begin(), edges.end(), [](tuple <int, int, int, int> a, tuple <int, int, int, int> b) {
		return get<2>(a) < get<2>(b);
	});
	for (auto [u, v, t, id] : edges) {
		if (vis[make_pair(u, v)]) continue;
		if (LCT::find(u) != LCT::find(v)) {
			LCT::link(u, n + id);
			LCT::link(v, n + id);
		}
	}
	_rep (i, q, 1) {
		int k = Q[i].k, u = Q[i].u, v = Q[i].v;
		if (k == 1) {
			cerr << i << endl;
			assert(LCT::find(u) == LCT::find(v));
			LCT::split(u, v);
			stk.push(LCT::val[LCT::mx[v]]);
		}
		else {
			int id = ::id[make_pair(u, v)];
			int t = get<2>(edges[id - 1]);
			if (LCT::find(u) != LCT::find(v)) {
				LCT::link(u, n + id);
				LCT::link(v, n + id);
			}
			else {
				int x = LCT::mx[v];
				if (LCT::val[x] > t) {
					LCT::cut(x, ::u[x]);
					LCT::cut(x, ::v[x]);
					LCT::link(u, n + id);
					LCT::link(v, n + id);
				}
			}
		}
	}
	while (!stk.empty()) {
		print(stk.top()), putchar(10);
		stk.pop();
	}
	cerr << system("fc P4172_2.out P4172_2.ans > nul");
	return 0;
}
