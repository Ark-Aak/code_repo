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

const int MAXN = 1505;
int n, m;
vector <int> G[MAXN];

int cnt;
int tp, tot;
int scc[MAXN], siz[MAXN];
int dfn[MAXN], s[MAXN], ins[MAXN], low[MAXN];
bitset <MAXN> e[MAXN], vis;

void tarjan(int u) {
	low[u] = dfn[u] = ++cnt;
	s[++tp] = u, ins[u] = 1;
	for (auto v : G[u]) {
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (ins[v]) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		++tot;
		while (s[tp] != u) {
			scc[s[tp]] = tot;
			siz[tot]++;
			ins[s[tp]] = 0;
			--tp;
		}
		scc[s[tp]] = tot;
		siz[tot]++;
		ins[s[tp]] = 0;
		--tp;
	}
}

vector <pii> edges;

void bfs(int s, int x) {
	queue <int> q;
	vis[s] = 1;
	q.push(s);
	while (q.size()) {
		int tp = q.front(); q.pop();
		bitset <MAXN> g = (~vis) & e[tp];
		for (int v = g._Find_first(); v <= n; v = g._Find_next(v)) {
			if (v == x) continue;
			vis[v] ? 0 : vis[v] = 1, q.push(v);
		}
	}
}

int ans[MAXN][MAXN];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("scc.in", "r", stdin);
	freopen("scc.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	for (int i = 1, u, v; i <= m; i++) {
		u = read(), v = read();
		e[u][v] = 1;
		G[u].push_back(v);
		edges.push_back({u, v});
	}
	rep (i, 1, n) if (!dfn[i]) tarjan(i);
	rep (i, 1, n) {
		vis.reset();
		for (auto v : G[i]) {
			if (vis[v]) ans[i][v] = 1;
			else bfs(v, i);
		}
		reverse(G[i].begin(), G[i].end());
		vis.reset();
		for (auto v : G[i]) {
			if (vis[v]) ans[i][v] = 1;
			else bfs(v, i);
		}
		reverse(G[i].begin(), G[i].end());
	}
	for (auto [u, v] : edges) {
		print(scc[u] != scc[v] ? ans[u][v] ? 1 : 0 : ans[u][v] ? 0 : 1);
		putchar(10);
	}
	return 0;
}
