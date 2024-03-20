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
const int MAXN = 600;

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

signed main() {
	cin >> m >> n;
	T = n + m + 1;
	int sum = 0;
	rep (i, 1, m) {
		int cost;
		cin >> cost;
		sum += cost;
		add(S, i, cost);
		char tools[10000];
		memset(tools, 0, sizeof tools);
		cin.getline(tools, 10000);
		int ulen = 0, tool;
		while (sscanf(tools + ulen, "%lld", &tool) == 1) {
			add(i, tool + m, INF);
			if (tool == 0) ulen++;
			else {
				while (tool) {
					tool /= 10;
					ulen++;
				}
			}
			ulen++;
		}
	}
	rep (i, 1, n) {
		int cost;
		cin >> cost;
		add(i + m, T, cost);
	}
	int val = dinic();
	rep (i, 1, m) if (dis[i] != -1) cout << i << " ";
	cout << endl;
	rep (i, 1, n) if (dis[i + m] != -1) cout << i << " ";
	cout << endl;
	cout << sum - val << endl;
	return 0;
}
