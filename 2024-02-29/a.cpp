#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

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

const int MAXN = 100005;
int n, m, k, Tk;

const int INF = 1e12;

struct edge{
	int nxt, v;
	ll c;
} e[10 * MAXN];

int cnt = 1, then[MAXN], dis[MAXN];

queue<int> q;

void _add(int u, int v, ll c) { e[++cnt] = (edge) {then[u], v, c}; then[u] = cnt; }
void add(int u, int v, ll c) { _add(u, v, c); _add(v, u, 0); }

int S, T, cur[MAXN];

bool dinic_bfs(){
	fill(dis, dis + MAXN, -1);
	dis[S] = 0; q.push(S);
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int u = then[t]; u; u = e[u].nxt) {
			if (e[u].c > 0 && dis[e[u].v] == -1) {
				dis[e[u].v] = dis[t] + 1;
				q.push(e[u].v);
			}
		}
	}
	return dis[T] != -1;
}

ll dinic_dfs(int x, ll flow) {
	if(x == T) return flow;
	ll rf = flow;
	for (int &u = cur[x]; u; u = e[u].nxt) {
		if (rf <= 0) break;
		cur[x] = u;
		ll rf_x = e[u].c;
		if (rf_x > 0 && dis[e[u].v] > dis[x]) {
			ll transfer = dinic_dfs(e[u].v, min(rf_x, rf));
			rf -= transfer;
			e[u].c -= transfer;
			e[u ^ 1].c += transfer;
		}
	}
	return flow - rf;
}

ll dinic() {
	ll ans = 0;
	while (dinic_bfs()) {
		copy(then, then + MAXN, cur);
		ans += dinic_dfs(S, INF);
	}
	return ans;
}

void clean() {
	cnt = 1;
	fill(then, then + MAXN, 0);
}

int f[1005][1005];

int id(int x, int y) {
	return (x - 1) * m + y;
}

void solve() {
	clean();
	n = read(), m = read(), k = read();
	rep (i, 1, n) {
		rep (j, 1, m) {
			f[i][j] = read();
			if (f[i][j] == -1) f[i][j] = INF;
			else f[i][j] = 100 - f[i][j];
		}
	}
	T = n * m + 1;
	rep (i, 1, n) add(S, id(i, 1), f[i][1]), add(id(i, m), T, INF);
	rep (i, 1, n) {
		rep (j, 2, m) add(id(i, j - 1), id(i, j), f[i][j]);
	}
	rep (i, 1, k) {
		int a = read(), b = read();
		add(S, id(b, 1), INF);
		rep (j, 2, m) add(id(a, j - 1), id(b, j), INF);
	}
	int ans = 100 * n - dinic();
	if (ans < -1e10) puts("-1");
	else print(ans), putchar(10);
}

signed main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	Tk = read();
	while (Tk --> 0) solve();
	return 0;
}
