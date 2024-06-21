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
typedef __int128 i128;
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

const int MAXN = 205;
int n, m, S, T;

namespace MaxFlow {

	map <pii, int> rev;
	vector <pii> G[MAXN];
	int dis[MAXN], cur[MAXN];

	void add(int u, int v, int w) {
		G[u].push_back(dl(v, w));
		G[v].push_back(dl(u, 0));
		rev[dl(u, v)] = G[v].size() - 1;
		rev[dl(v, u)] = G[u].size() - 1;
	}

	bool bfs() {
		memset(dis, -1, sizeof dis);
		queue <int> q;
		q.push(S);
		dis[S] = 0;
		while (q.size()) {
			int tp = q.front();
			q.pop();
			for (auto [v, w] : G[tp]) {
				if (dis[v] != -1 || w <= 0) continue;
				dis[v] = dis[tp] + 1;
				q.push(v);
			}
		}
		return dis[T] != -1;
	}

	int dfs(int u, int flow) {
		if (u == T) return flow;
		int rf = flow;
		for (int i = cur[u]; i < (int) G[u].size(); i++) {
			if (rf <= 0) break;
			cur[u] = i;
			auto &[v, w] = G[u][i];
			if (w <= 0 || dis[v] <= dis[u]) continue;
			auto _push = dfs(v, min(w, rf));
			rf -= _push;
			w -= _push;
			G[v][rev[dl(u, v)]].fb += _push;
		}
		return flow - rf;
	}

	int dinic() {
		int res = 0;
		while (bfs()) {
			memset(cur, 0, sizeof cur);
			res += dfs(S, 1e18);
		}
		return res;
	}
} // namespace MaxFlow

signed main() {
	n = read(), m = read(), S = read(), T = read();
	rep (i, 1, m) {
		int u = read(), v = read(), w = read();
		MaxFlow::add(u, v, w);
	}
	print(MaxFlow::dinic());
	return 0;
}
