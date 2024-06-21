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

const int MAXN = 3e5 + 5;
int n, m;
vector <pii> G[MAXN];

int dis[MAXN][2];
bool vis[MAXN][2];
priority_queue <pii, vector <pii>, greater <pii> > q;
map <pair <int, int>, int> id, pos[2];
vector <int> son[2][MAXN];

void init() {
	rep (i, 1, n) dis[i][0] = dis[i][1] = 0x3f3f3f3f3f3f3f3f;
	rep (i, 1, n) vis[i][0] = vis[i][1] = 0;
	rep (i, 1, n) son[0][i].clear(), son[1][i].clear();
	while (!q.empty()) q.pop();
}

void dijkstra(int s, int op) {
	dis[s][op] = 0;
	q.push(dl(0, s));
	while (!q.empty()) {
		int u = q.top().fb; q.pop();
		if (vis[u][op]) continue;
		vis[u][op] = 1;
		for (auto e : G[u]) {
			int v = e.ec, w = e.fb;
			if (dis[v][op] > dis[u][op] + w) {
				dis[v][op] = dis[u][op] + w;
				q.push(dl(dis[v][op], v));
			}
		}
	}
}

struct Tarjan {
    int low[MAXN], dfn[MAXN], cnt;
    int stk[MAXN], tail, idx, bridge[MAXN], op;

    void init(int n, int m, int op) {
        rep (i, 1, n) low[i] = 0;
        rep (i, 1, n) dfn[i] = 0;
        rep (i, 1, n) stk[i] = 0;
        rep (i, 1, m) bridge[i] = 0;
        tail = 0; idx = 0; cnt = 0;
		this -> op = op;
    }

    void tarjan(int x, int fa) {
        dfn[x] = ++cnt;
        low[x] = cnt;
        stk[++tail] = x;
        for (auto i : son[op][x]) {
            if (i == fa) continue;
            if (!dfn[i]) {
                tarjan(i, x);
                low[x] = min(low[x], low[i]);
                if (dfn[x] < low[i]) bridge[id[dl(x, i)]] = true;
            }
			else low[x] = min(low[x], dfn[i]);
        }
    }
} tarjan1, tarjan2;

int T;

void solve() {
	n = read(), m = read();
	rep (i, 1, n) G[i].clear();
	rep (i, 1, m) {
		int u = read(), v = read(), w = read();
		G[u].push_back(dl(v, w));
		G[v].push_back(dl(u, w));
		id[dl(u, v)] = id[dl(v, u)] = i;
	}
	init();
	dijkstra(1, 0);
	dijkstra(n, 1);
	rep (i, 1, n) {
		for (auto [u, w] : G[i]) {
			if (dis[i][0] + dis[u][1] + w == dis[n][0]) {
				son[0][i].push_back(u);
				son[0][u].push_back(i);
				son[1][i].push_back(u);
				son[1][u].push_back(i);
			}
			if (dis[i][0] + dis[u][1] + w == dis[n][0] + 1) {
				son[1][i].push_back(u);
				son[1][u].push_back(i);
			}
		}
	}
	tarjan1.init(n, m, 0);
	tarjan2.init(n, m, 1);
	tarjan1.tarjan(1, 0);
	tarjan2.tarjan(1, 0);
	vector <int> ans;
	rep (i, 1, m) {
		if (tarjan1.bridge[i] && !tarjan2.bridge[i]) ans.push_back(i);
	}
	print(ans.size()), puts("");
	for (auto v : ans) print(v), putchar(32);
	puts("");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("vacation.in", "r", stdin);
	freopen("vacation.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
