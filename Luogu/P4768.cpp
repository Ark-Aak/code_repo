#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
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

const int MAXN = 2e6 + 5;
int T, n, m;
vector <tuple <int, int, int> > G[MAXN];
vector <int> kt[MAXN];
vector <tuple <int, int, int, int> > edges;

int dis[MAXN];
bool vis[MAXN];
priority_queue <pii, vector <pii>, greater <pii> > q;

void dijkstra(int s) {
	memset(vis, 0, sizeof vis);
	memset(dis, 0x3f, sizeof dis);
	q.push({0, s});
	dis[s] = 0;
	while (q.size()) {
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto [v, l, a] : G[u]) {
			if (dis[v] > dis[u] + l) {
				dis[v] = dis[u] + l;
				if (!vis[v]) q.push({dis[v], v});
			}
		}
	}
}

int fa[MAXN];
int val[MAXN], minn[MAXN];
int cnt, st[MAXN][23];

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void kruskal() {
	sort(edges.begin(), edges.end(), [](auto a, auto b) {
		int u1, v1, l1, a1, u2, v2, l2, a2;
		tie(u1, v1, l1, a1) = a;
		tie(u2, v2, l2, a2) = b;
		return a1 > a2;
	});
	rep (i, 1, n) fa[i] = i;
	for (auto [u, v, l, a] : edges) {
		int fu = find(u);
		int fv = find(v);
		if (fu == fv) continue;
		val[++cnt] = a;
		fa[fu] = fa[fv] = fa[cnt] = cnt;
		kt[cnt].push_back(fu), kt[cnt].push_back(fv);
	}
}

void getMinn(int u) {
	if (u <= n) minn[u] = dis[u];
	for (auto v : kt[u]) {
		st[v][0] = u;
		getMinn(v);
		minn[u] = min(minn[u], minn[v]);
	}
}

int main() {
	read(T);
	while (T --> 0) {
		memset(st, 0, sizeof st);
		memset(minn, 0x3f, sizeof minn);
		memset(val, 0, sizeof val);
		rep (i, 1, n) G[i].clear();
		rep (i, 1, n << 1) kt[i].clear();
		edges.clear();
		int lastans = 0;
		read(n), read(m);
		cnt = n;
		rep (i, 1, m) {
			int u, v, l, a;
			read(u), read(v), read(l), read(a);
			G[u].push_back({v, l, a});
			G[v].push_back({u, l, a});
			edges.push_back({u, v, l, a});
		}
		dijkstra(1);
		kruskal();
		getMinn(cnt);
		for (int j = 1; (1 << j) <= cnt; j++) {
			rep (i, 1, cnt) st[i][j] = st[st[i][j - 1]][j - 1];
		}
		int Q = 0, K = 0, S = 0;
		read(Q), read(K), read(S);
		while (Q --> 0) {
			int v, p;
			read(v), read(p);
			v = (v + K * lastans - 1) % n + 1;
			p = (p + K * lastans) % (S + 1);
			for (int j = 22; ~j; j--) {
				if (st[v][j] && val[st[v][j]] > p) v = st[v][j];
			}
			print(lastans = minn[v]), putchar(10);
		}
	}
	return 0;
}
