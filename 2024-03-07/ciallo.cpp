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

const int MAXN = 1e5 + 5, MAXM = 33;
int n, q, a[MAXN];
vector <int> G[MAXN];

struct basis {

	int ops = 0;
	int p[MAXM], d[MAXM];

	void init() {
		for (int i = 0; i < MAXM; i++)
			p[i] = d[i] = 0;
		return;
	}

	void insert(int x, int y) {
		for (int i = MAXM - 1; i >= 0; i--) if ((x >> i) & 1) {
			if (!p[i]) return p[i] = x, d[i] = y, void();
			if ((ops == 0 && y < d[i]) || (ops == 1 && y > d[i]))
				swap(p[i], x), swap(d[i], y);
			x ^= p[i];
		}
	}
} cls[MAXN], far[MAXN], f, g;

vector <int> son[MAXN];

void add(basis &a, int s) {
	for (int i = 0; i < MAXM; i++)
		if (a.p[i]) a.d[i] += s;
}

void add(basis &a, const basis b, int s = 0) {
	for (int i = 0; i < MAXM; i++)
		if (b.p[i]) a.insert(b.p[i], b.d[i] + s);
}

void dfs1(int u, int fa) {
	cls[u].insert(a[u], 0);
	far[u].insert(a[u], 0);
	for (auto v : G[u]) if (v != fa) {
		son[u].push_back(v);
		dfs1(v, u);
		add(cls[u], cls[v], 1);
		add(far[u], far[v], 1);
	}
}

void dfs2(int u, int fa) {
	add(f, 1);
	add(cls[u], cls[fa], 1);
	add(far[u], f);
	f.insert(a[u], 0);
	if (!son[u].size()) return;
	basis tmp = f, last[son[u].size() + 1], pre[son[u].size() + 1];
	/* last[son[u].size()].init(); */
	g.init();
	_rep (i, son[u].size() - 1, 0)
		add(g, far[son[u][i]], 1), last[i] = g;
	g.init();
	/* pre[0].init(); */
	rep (i, 0, son[u].size() - 1)
		add(g, far[son[u][i]], 1), pre[i + 1] = g;
	rep (i, 0, son[u].size() - 1) {
		f = tmp;
		add(f, pre[i]), add(f, last[i + 1]);
		dfs2(son[u][i], u);
	}
}

void solve(int x, int y, int l, int r) {
	basis ans;
	ans.init();
	rep (i, 0, MAXM - 1) {
		if (cls[x].d[i] < l) ans.insert(cls[x].p[i], 0);
		if (far[x].d[i] > r) ans.insert(far[x].p[i], 0);
	}
	_rep (i, MAXM - 1, 0) {
		if ((y >> i) & 1) y ^= ans.p[i];
	}
	if (y) puts("NO");
	else puts("ciallo");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("ciallo.in", "r", stdin);
	freopen("ciallo.out", "w", stdout);
#endif
#endif
	n = read(), q = read();
	f.ops = g.ops = 1;
	rep (i, 0, MAXN - 1) far[i].ops = 1;
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	rep (i, 1, q) {
		int x = read(), y = read(), l = read(), r = read();
		solve(x, y, l, r);
	}
	return 0;
}
