#include <bits/stdc++.h>

#define int ll

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

const int MAXN = 5e4 + 5;
int n, m, root, sum;
vector <int> G[MAXN];
int siz[MAXN], p[MAXN], r[MAXN], dis[MAXN];
int mk[10000005], t[10000005];
bool vis[MAXN];

void update_root(int u, int fa) {
	siz[u] = 1, p[u] = 0;
	for (auto v : G[u]) {
		if (v == fa || vis[v]) continue;
		update_root(v, u);
		siz[u] += siz[v];
		p[u] = max(p[u], siz[v]);
	}
	p[u] = max(p[u], sum - siz[u]);
	if (p[u] < p[root]) root = u;
}

void get_dis(int u, int fa) {
	r[++r[0]] = dis[u];
	for (auto v : G[u]) {
		if (v == fa || vis[v]) continue;
		dis[v] = dis[u] + 1;
		get_dis(v, u);
	}
}

int query[MAXN];
int diff[MAXN], dcnt = 0;

void calc(int u) {
	dcnt = 0;
	for (auto v : G[u]) {
		if (vis[v]) continue;
		r[0] = 0; dis[v] = 1;
		get_dis(v, u);
		rep (i, 1, r[0]) {
			rep (j, 1, m) {
				if (query[j] >= r[i]) mk[j] += t[query[j] - r[i]];
			}
		}
		rep (i, 1, r[0]) {
			diff[++dcnt] = r[i];
			t[r[i]]++;
		}
	}
	rep (i, 1, dcnt) t[diff[i]]--;
}

void solve(int u) {
	vis[u] = 1, t[0] = 1;
	calc(u);
	for (auto v : G[u]) {
		if (vis[v]) continue;
		sum = siz[v];
		p[root = 0] = 1e9;
		update_root(v, 0);
		solve(root);
	}
}

int C[4];

signed main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	n = read(), m = read();
	rep (i, 1, m) query[i] = read();
	rep (i, 1, n - 1) {
		int u, v;
		u = read(), v = read();
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	p[root] = sum = n;
	update_root(1, 0);
	update_root(root, 0);
	solve(root);
	rep (i, 1, n) C[i % 3 == 0 ? 3 : i % 3]++;
	rep (i, 1, 3) {
		double ans = 0;
		double x = C[i];
		rep (i, 1, m) ans += mk[i] * 1.0 * (x * 1.0 * (x - 1) / n * 1.0 / (n - 1.0));
		printf("%.2lf\n", ans);
	}
	return 0;
}
