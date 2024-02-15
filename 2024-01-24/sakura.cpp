#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;

const int MAXN = 8e5 + 5;
const int MAXM = 2e6 + 5;

int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-')
			f = -1;
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
	if (x < 0)
		x = (~x + 1), putchar('-');
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}

namespace G {
	vector <int> G[MAXN];
	void add(int x, int y) { G[x].push_back(y); }
}

namespace T {
	vector <int> G[MAXN];
	void add(int x, int y) { G[x].push_back(y); }
}

namespace tarjan {
	int dfn[MAXN], low[MAXN];
	stack <int> stk;
	vector <pair<int, int> > edge;
	int tim, scc;

	void tarjan(int x) {
		tim++;
		dfn[x] = low[x] = tim;
		stk.push(x);
		for (auto v : G::G[x]) {
			if (!dfn[v]) {
				tarjan(v);
				low[x] = min(low[x], low[v]);
				if (low[v] < dfn[x]) continue;
				scc++;
				while (stk.top() != v) {
					edge.push_back(make_pair(stk.top(), scc));
					edge.push_back(make_pair(scc, stk.top()));
					stk.pop();
				}
				edge.push_back(make_pair(stk.top(), scc));
				edge.push_back(make_pair(scc, stk.top()));
				stk.pop();
				edge.push_back(make_pair(x, scc));
				edge.push_back(make_pair(scc, x));
			}
			else
				low[x] = min(low[x], dfn[v]);
		}
	}

}

int siz[MAXN], dep[MAXN], fa[MAXN], son[MAXN];

void dfs1(int x) {
	siz[x] = 1;
	for (auto v : T::G[x]) {
		if (v == fa[x]) continue;
		fa[v] = x;
		dep[v] = dep[x] + 1;
		dfs1(v);
		siz[x] += siz[v];
		if (siz[v] > siz[son[x]]) son[x] = v;
	}
}

int dfn[MAXN], idx[MAXN], top[MAXN];
int a[MAXN];
int cnt;

void dfs2(int x, int Mgn) {
	cnt++; dfn[x] = cnt;
	idx[cnt] = x; top[x] = Mgn;
	if (son[x]) dfs2(son[x], son[x]);
	for (auto v : T::G[x]) {
		if (v == fa[x] || v == son[x]) continue;
		dfs2(v, v);
	}
}

int LCA(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if (dfn[x] > dfn[y]) swap(x, y);
	return x;
}

bool check(int x, int y) {
	int fx = a[x], fy = a[y];
	int lca = LCA(fx, fy);
	if (LCA(fx, y) == y && LCA(lca, y) == lca) return true;
	if (LCA(fy, y) == y && LCA(lca, y) == lca) return true;
	return false;
}

bitset <MAXN> vis;
int dis[MAXN];
queue <int> q;

void bfs() {
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto v : G::G[u]) {
			if (vis[v]) continue;
			vis[v] = 1, dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
}

signed main() {
	int n = read(), m = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, m) {
		int x = read(), y = read();
		G::add(x, y), G::add(y, x);
	}
	tarjan::scc = n, tarjan::tarjan(1);
	for (auto [x, y] : tarjan::edge)
		T::add(x, y);
	dfs1(1), dfs2(1, 0);
	memset(dis, -1, sizeof(dis));
	rep(i, 1, n) {
		if (i == a[i]) {
			q.push(i), dis[i] = 0, vis[i] = 1;
			continue;
		}
		bool flg = 0;
		for (auto j : G::G[i]) if (check(i, j)) flg = 1;
		if (flg) q.push(i), dis[i] = 1, vis[i] = 1;
	}
	bfs();
	rep(i, 1, n) print(dis[i]), putchar(32);
	return 0;
}
