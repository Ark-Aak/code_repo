#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(x) cerr << #x << " = " << (x) << endl;

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

const int MAXN = 2005;

struct MaxFlow {

	map <pii, int> rev;
	vector <pii> G[MAXN];
	int dis[MAXN], cur[MAXN];
	int S, T;

	void add(int u, int v, int w) {
		if (!w) return;
		/* cout << u << " <-> " << v << " = " << w << endl; */
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
};

int T;
int n, k, pt[MAXN];
vector <pii> t1[MAXN], t2[MAXN];
int fa1[MAXN], fa2[MAXN];
int fac1[MAXN], fac2[MAXN];
int mp[MAXN];

void dfs1(int u, int fa) {
	fa1[u] = fa;
	for (auto [v, ignore] : t1[u]) if (v ^ fa) dfs1(v, u);
}

void dfs2(int u, int fa) {
	fa2[u] = fa;
	for (auto [v, ignore] : t2[u]) if (v ^ fa) dfs2(v, u);
}

signed main() {
	T = read();
	while (T --> 0) {
		MaxFlow mf;
		mf.S = 0, mf.T = 1001;
		n = read(), k = read();
		rep (i, 1, n) mp[i] = fac1[i] = fac2[i] = 0;
		rep (i, 1, k) pt[i] = read(), mp[pt[i]] = 1;
		rep (i, 1, n) vector <pii>().swap(t1[i]), vector <pii>().swap(t2[i]);
		int sum = 0;
		rep (i, 1, n - 1) {
			int u = read(), v = read(), w = read();
			if (!(mp[u] && mp[v])) w = 0;
			sum += w;
			t1[u].emplace_back(v, w);
			t1[v].emplace_back(u, w);
		}
		rep (i, 1, n - 1) {
			int u = read(), v = read(), w = read();
			if (!(mp[u] && mp[v])) w = 0;
			sum += w;
			t2[u].emplace_back(v, w);
			t2[v].emplace_back(u, w);
		}
		dfs1(1, 0), dfs2(1, 0);
		rep (i, 1, k) {
			int cost1 = 0, cost2 = 0;
			for (auto [v, w] : t1[pt[i]]) {
				if (v == fa1[pt[i]] && mp[fa1[pt[i]]]) { fac1[pt[i]] = w; continue; }
				cost1 += w;
			}
			for (auto [v, w] : t2[pt[i]]) {
				if (v == fa2[pt[i]] && mp[fa2[pt[i]]]) { fac2[pt[i]] = w; continue; }
				cost2 += w;
			}
			mf.add(mf.S, pt[i], cost1);
			mf.add(pt[i], mf.T, cost2);
			mf.add(fa1[pt[i]], pt[i], fac1[pt[i]]);
			mf.add(pt[i], fa2[pt[i]], fac2[pt[i]]);
		}
		sum -= mf.dinic();
		print(sum), puts("");
	}
	return 0;
}
