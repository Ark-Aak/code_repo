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

int m, n;

const int INF = 1e12;
const int MAXN = 60000;

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

int dx[5] = {0, 0, 0, 1, -1}, dy[5] = {0, 1, -1, 0, 0};

void connect(int x, int y) {
	rep (i, 0, 4) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
		add(n * m + (nx - 1) * m + ny, (x - 1) * m + y, INF);
		add((x - 1) * m + y, 2 * n * m + (nx - 1) * m + ny, INF);
	}
}

signed main() {
	n = read(), m = read();
	T = 3 * n * m + 1;
	int sum = 0;
	rep (i, 1, n) rep (j, 1, m) {
		int x = read();
		sum += x;
		add(S, (i - 1) * m + j, x);
	}
	rep (i, 1, n) rep (j, 1, m) {
		int x = read();
		sum += x;
		add((i - 1) * m + j, T, x);
	}
	rep (i, 1, n) rep (j, 1, m) {
		int x = read();
		sum += x;
		add(S, n * m + (i - 1) * m + j, x);
	}
	rep (i, 1, n) rep (j, 1, m) {
		int x = read();
		sum += x;
		add(2 * n * m + (i - 1) * m + j, T, x);
	}
	rep (i, 1, n) rep (j, 1, m) {
		connect(i, j);
	}
	print(sum - dinic());
	return 0;
}
