#include <bits/stdc++.h>
#include "testlib.h"

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

const int MOD = 998244353;
const int MAXN = 1e6 + 5;
vector <pii> e;
vector <int> G[MAXN];
int in[MAXN], out[MAXN];

bool topo(int n, int s, int t) {
	if (in[s] != 0 || out[t] != 0) return false;
	rep (i, 1, n) {
		if (i == s) continue;
		if (in[i] == 0) return false;
	}
	rep (i, 1, n) {
		if (i == t) continue;
		if (out[i] == 0) return false;
	}
	queue <int> q;
	q.push(s);
	while (q.size()) {
		int tp = q.front(); q.pop();
		for (auto v : G[tp]) {
			in[v]--; out[tp]--;
			if (!in[v]) q.push(v);
		}
	}
	rep (i, 1, n) if (in[i]) return false;
	return true;
}

int low[MAXN], dfn[MAXN], stk[MAXN], clk, top, n, m;
int S, T, cnt, del[MAXN];
vector <int> nt[MAXN];
map <int, int> vis;

void tarjan(int u) {
	low[u] = dfn[u] = ++clk;
	stk[++top] = u;
	for (auto v : G[u]) {
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				int x;
				cnt++;
				do {
					x = stk[top--];
					nt[n + cnt].push_back(x);
					nt[x].push_back(n + cnt);
				} while (x != v);
				nt[n + cnt].push_back(u);
				nt[u].push_back(n + cnt);
			}
		}
		else low[u] = min(low[u], dfn[v]);
	}
}

vector <int> chain;

bool dfs0(int u, int fa, int t) {
	if (u == t) return chain.push_back(u), true;
	for (auto v : nt[u]) {
		if (v == fa) continue;
		if (dfs0(v, u, t)) return chain.push_back(u), true;
	}
	return false;
}

bool dfs1(int u, int fa) {
	int res = 1, cnt = 0;
	for (auto v : nt[u]) {
		if (v == fa || nt[v].size() == 1) continue;
		cnt++;
		res &= dfs1(v, u);
	}
	res &= (cnt <= 1);
	return res;
}

vector <int> ph;

bool dfs2(int u, int fa) {
	for (auto v : nt[u]) {
		if (v == fa || nt[v].size() == 1) continue;
		if (dfs2(v, u)) return true;
	}
	if (u >= n) return ph.push_back(u), true;
	return false;
}

const double partScore = 0.3;

signed main(int argc, char** argv) {
	registerTestlibCmd(argc, argv);
	n = inf.readInt(), m = inf.readInt();
	S = inf.readInt(), T = inf.readInt();
	rep (i, 1, m) {
		int x = inf.readInt(), y = inf.readInt();
		e.push_back(dl(x, y));
	}
	int oufP = ouf.readInt(0, MOD - 1);
	int ansP = ans.readInt(0, MOD - 1);
	if (oufP != ansP) quitf(_wa, "Wrong probability.");
	if (ansP) {
		int u = ouf.readInt(1, n);
		int v = ouf.readInt(1, n);
		string w = ouf.readToken();
		if ((int) w.size() != m) quitp(partScore, "Wrong length of string.");
		G[u].push_back(v);
		out[u]++, in[v]++;
		rep (i, 0, m - 1) {
			int x = e[i].ec, y = e[i].fb;
			if (w[i] == '0') G[x].push_back(y), out[x]++, in[y]++;
			else G[y].push_back(x), out[y]++, in[x]++;
		}
		if (!topo(n, S, T)) quitp(partScore, "Wrong construction.");
		quitf(_ok, "Accepted");
	}
	else {
		int oufN = ouf.readInt(1, n);
		int ansN = ans.readInt(1, n);
		if (ansN < oufN) quitp(partScore, "Wrong number of nodes.");
		rep (i, 1, oufN) {
			int x = ouf.readInt(1, n);
			if (vis[x]) quitp(partScore, "Vertex %d appears twice.", x);
			vis[x] = del[x] = 1;
		}
		for (auto [i, j] : e) {
			if (del[i] || del[j]) continue;
			G[i].push_back(j);
			G[j].push_back(i);
		}
		vis.clear();
		G[S].push_back(T);
		G[T].push_back(S);
		tarjan(S);
		rep (i, 1, n) if (!dfn[i] && !del[i]) quitp(partScore, "Vertex %d is not connected", i);
		int ok = cnt == 1;
		if (ok && ansN == oufN) quitf(_ok, "Accepted");
		else if (ok && ansN > oufN) quitf(_fail, "Participants have better solutions");
		else quitp(partScore, "Wrong construction");
	}
	return 0;
}
