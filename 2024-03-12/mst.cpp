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

const int MAXN = 3505;
int n, m;
vector <pair <int, int> > G[MAXN];
int dep[MAXN], fa[MAXN], f[MAXN], ecnt;

struct edge {
	int u, v, l, r, id;
} e[MAXN * MAXN];

int id[MAXN], vis[MAXN], p[MAXN];

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	::fa[u] = fa;
	for (auto [v, _id] : G[u]) if (v != fa) {
		id[v] = _id;
		dfs(v, u);
	}
}

int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}

bool check(int now) {
	rep (i, 1, m) f[i] = i - vis[i];
	_rep (i, m, 1) {
		int x = p[i];
		if (x >= now) {
			int fy = find(e[x].r);
			if (fy < e[x].l) return 0;
			f[fy] = fy - 1;
		}
	}
	return 1;
}

int res[MAXN];

signed main() {
	n = read(), m = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read(), l = read(), r = read();
		e[i] = (edge) {u, v, l, r, i};
		G[u].push_back({v, i});
		G[v].push_back({u, i});
	}
	dfs(1, 0);
	rep (i, n, m) {
		int u = read(), v = read(), l = read(), r = read();
		e[i] = (edge) {u, v, l, r, i};
	}
	rep (i, n, m) {
		int u = e[i].u, v = e[i].v;
		while (u ^ v) {
			if (dep[u] < dep[v]) swap(u, v);
			int j = id[u];
			e[j].r = min(e[j].r, e[i].r - 1);
			e[i].l = max(e[i].l, e[j].l + 1);
			u = fa[u];
		}
	}
	rep (i, 1, m) p[i] = i;
	sort(p + 1, p + 1 + m, [](const int a, const int b) {
		return e[a].l == e[b].l ? e[a].r < e[b].r : e[a].l < e[b].l;
	});
	if (!check(1)) return puts("-1"), 0;
	rep (i, 1, m) {
		int l = e[i].l, r = e[i].r, ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			e[i].r = mid;
			if (check(i)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		vis[ans] = 1;
		print(ans), putchar(32);
	}
	return 0;
}
