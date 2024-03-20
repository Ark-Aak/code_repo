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
int n, m;
vector <pii> G[MAXN], pt[MAXN];
ll dep[MAXN];
int siz[MAXN], son[MAXN], ps[MAXN];
vector <ll> H;

void init() {
	sort(H.begin(), H.end());
	H.erase(unique(H.begin(), H.end()), H.end());
}

int h(ll x) { return lower_bound(H.begin(), H.end(), x) - H.begin() + 1;}

set <int> S;

void dfs1(int u, int fa) {
	siz[u] = 1;
	for (auto [v, w] : G[u]) {
		if (v == fa) continue;
		dep[v] = dep[u] + w;
		dfs1(v, u);
		siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}

int pre(int x) { auto it = S.lower_bound(x); return it == S.begin() ? 0 : *prev(it); }
int nxt(int x) { auto it = S.upper_bound(x); return it == S.end()   ? 0 : *it;       }

void insert(int u, int c) {
	int v = pre(u); if (v) pt[v].push_back(dl(u, c));
	v = nxt(u); if (v) pt[u].push_back(dl(v, c));
}

void dfs2(int u, int c, int fa) {
	insert(u, c);
	for (auto [v, w] : G[u]) {
		if (v == fa) continue;
		dfs2(v, c, u);
	}
}

void dfs3(int u, int fa) {
	S.insert(u);
	for (auto [v, w] : G[u]) {
		if (v == fa) continue;
		dfs3(v, u);
	}
}

void dfs4(int u, int fa, int f) {
	for (auto [v, w] : G[u]) {
		if (v == fa || v == son[u]) continue;
		dfs4(v, u, 1);
	}
	if (son[u]) dfs4(son[u], u, 0);
	insert(u, dep[u]);
	S.insert(u);
	for (auto [v, w] : G[u]) {
		if (v == fa || v == son[u]) continue;
		dfs2(v, dep[u], u), dfs3(v, u);
	}
	if (f) S.clear();
}

vector <pii> q[MAXN];

namespace BIT {
	int sum[MAXN];

	void add(int x, int v) {
		if (!x) return;
		for (int o = x; o <= n; o += o & -o)
			sum[o] += v;
	}

	int query(int x, int res = 0) {
		for (int o = x; o; o -= o & -o)
			res += sum[o];
		return res;
	}
} // namespace BIT

int ans[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read(), w = read();
		G[u].push_back(dl(v, w));
		G[v].push_back(dl(u, w));
	}
	dfs1(1, 0);
	rep (i, 1, n) H.push_back(dep[i]);
	/* cerr << "sb" << endl; */
	init();
	rep (i, 1, n) dep[i] = h(dep[i]);
	/* cerr << "sb" << endl; */
	dfs4(1, 0, 0);
	rep (i, 1, H.size()) ps[i] = n + 1;
	rep (i, 1, n) pt[i].push_back(dl(i, dep[i]));
	int l, r;
	rep (i, 1, m) l = read(), r = read(), q[l].push_back(dl(r, i));
	/* cerr << "read end" << endl; */
	_rep (i, n, 1) {
		for (auto [u, c] : pt[i]) {
			BIT::add(ps[c], -1);
			ps[c] = min(ps[c], u);
			BIT::add(ps[c], 1);
		}

		for (auto [u, c] : q[i]) ans[c] = BIT::query(u);
	}
	rep (i, 1, m) print(ans[i]), putchar(10);
	return 0;
}
