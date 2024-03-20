#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

#define int ll

typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 2e5 + 5;
int n, m;
vector <pair <int, int> > G[MAXN];
int f[MAXN];

int find(int x) {
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}

void merge(int x, int y) {
	f[find(y)] = find(x);
}

#define mp make_pair
#define mt make_tuple

priority_queue <tuple <int, int, int> , vector <tuple <int, int, int> >, greater <tuple <int, int, int> > > q;

void kruskal() {
	int cnt = 0;
	while (q.size() && cnt < n - 1) {
		int w, u, v;
		tie(w, u, v) = q.top();
		q.pop();
		if (find(u) == find(v)) continue;
		G[u].emplace_back(mp(v, w));
		G[v].emplace_back(mp(u, w));
		merge(u, v); ++cnt;
	}
}

int flg[MAXN], sum[MAXN], dep[MAXN];

void dfs(int u, int fa) {
	for (auto x : G[u]) {
		int v = x.first;
		if (v == fa) continue;
		int w = x.second;
		sum[v] = sum[u] + w;
		dfs(v, u);
	}
}

int wSon[MAXN], fa[MAXN], hSon[MAXN], top[MAXN], cnt, dfn[MAXN];

void getSize(int step, int u, int f) {
	wSon[u] = 1; fa[u] = f; dep[u] = step;
	for (auto [v, w] : G[u]) {
		if (v == f) continue;
		getSize(step + 1, v, u);
		wSon[u] += wSon[v];
		if (wSon[v] > wSon[hSon[u]]) hSon[u] = v;
	}
}

void getDFN(int u, int header) {
	dfn[u] = ++cnt, top[u] = header;
	if (!hSon[u]) return;
	getDFN(hSon[u], header);
	for (auto [v, w] : G[u]) {
		if (v == fa[u] || v == hSon[u]) continue;
		getDFN(v, v);
	}
}

int LCA(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	return x;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("steiner.in", "r", stdin);
	freopen("steiner.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	rep (i, 1, m) {
		int u, v, w;
		read(u), read(v), read(w);
		q.push(mt(w, u, v));
	}
	rep (i, 1, n) f[i] = i;
	kruskal(); dfs(1, 1);
	getSize(1, 1, 1);
	getDFN(1, 1);
	rep (i, 3, n) {
		print(sum[i] + sum[2] - sum[LCA(i, 2)]), putchar(32);
	}
	return 0;
}
