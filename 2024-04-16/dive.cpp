#include <bits/stdc++.h>

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

const int MAXN = 4e5 + 5;
vector <int> G[MAXN];
int n, m;

namespace Bipolar {

	vector <int> T[MAXN];
	vector <int> nxt[MAXN];
	vector <int> plan, chain;
	int dfn[MAXN], low[MAXN], clk;
	int fa[MAXN], deg[MAXN], rm[MAXN];

	bool tarjan(int u, int t) {
		bool flg = (u == t);
		/* cout << u << " " << t << endl; */
		dfn[u] = low[u] = ++clk;
		for (auto v : T[u]) {
			if (!dfn[v]) {
				fa[v] = u;
				deg[u]++;
				flg |= tarjan(v, t);
				low[u] = min(low[u], low[v]);
			}
			else low[u] = min(low[u], dfn[v]);
		}
		if (flg) chain.push_back(u);
		return flg;
	}

	void del(int u) {
		if (rm[u]) return;
		rm[u] = 1;
		plan.push_back(u);
		for (auto v : nxt[dfn[u]]) del(v);
	}

	void solve(int s, int t, int ccnt) {
		tarjan(s, t);
		queue <int> q;
		rep (i, 1, ccnt) if (!deg[i]) q.push(i);
		while (q.size()) {
			int tp = q.front(); q.pop();
			if (tp == t) continue;
			nxt[low[tp]].push_back(tp);
			nxt[dfn[fa[tp]]].push_back(tp);
			deg[fa[tp]]--;
			if (!deg[fa[tp]]) q.push(fa[tp]);
		}
		reverse(chain.begin(), chain.end());
		for (auto id : chain) del(id);
	}

} // namespace Bipolar

namespace BCT {

int dfn[MAXN], low[MAXN], clk;
int stk[MAXN], top, cnt, f[MAXN], col[MAXN], rm[MAXN];
int siz[MAXN], hs[MAXN], ans = 1e9, p0, p1, ps, ccnt;
vector <int> T[MAXN], nodes[MAXN];

void dp(int u, int fa) {
	siz[u] = (u <= n);
	int ch0 = 0, ch1 = 0;
	for (auto v : T[u]) {
		if (v == fa) continue;
		dp(v, u);
		siz[u] += siz[v];
		if (siz[v] > siz[ch0]) ch1 = ch0, ch0 = v;
		else if (siz[v] > siz[ch1]) ch1 = v;
	}
	f[u] = f[ch0];
	hs[u] = ch0;
	int ans0 = (u <= n), ans1 = (u <= n);
	for (auto v : T[u]) {
		if (v == fa || v == ch0) continue;
		if (u <= n) ans0 += siz[v];
		else ans0 = max(ans0, siz[v]);
		if (v == ch1) continue;
		if (u <= n) ans1 += siz[v];
		else ans1 = max(ans1, siz[v]);
	}
	if (u <= n) ans1 += n - siz[u];
	else ans1 = max(ans1, n - siz[u]);
	ans1 = max(ans1, f[ch0]);
	ans1 = max(ans1, f[ch1]);
	f[u] = max(f[u], ans0);
	if (ans1 <= ans) {
		ans = ans1, ps = u;
		p0 = ch0, p1 = ch1;
	}
}

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
					T[n + cnt].push_back(x);
					T[x].push_back(n + cnt);
				} while (x != v);
				T[n + cnt].push_back(u);
				T[u].push_back(n + cnt);
			}
		}
		else low[u] = min(low[u], dfn[v]);
	}
}

void color(int u, int fa) {
	if (col[u] || rm[u]) return;
	col[u] = ccnt;
	if (u <= n) nodes[ccnt].push_back(u);
	for (auto v : T[u]) {
		if (v == fa) continue;
		color(v, u);
	}
}

void solve() {
	tarjan(1);
	dp(1, 0);
	if (ps > n) rm[ps] = 1;
	int L = ps, R = ps;
	/* int L = 0, R = 0; */
	for (int ch = p0; ch; ch = hs[ch]) if (ch > n) rm[ch] = 1; else L = ch;
	for (int ch = p1; ch; ch = hs[ch]) if (ch > n) rm[ch] = 1; else R = ch;
	/* assert(R); */
	/* cout << "x:" << L << " " << R << endl; */
	rep (i, 1, n) if (!col[i]) ++ccnt, color(i, 0);
	rep (i, 1, n) {
		for (auto j : G[i]) {
			if (col[i] != col[j]) {
				Bipolar::T[col[i]].push_back(col[j]);
				Bipolar::T[col[j]].push_back(col[i]);
			}
		}
	}
	Bipolar::solve(col[L], col[R], ccnt);
	print(ans), putchar(32), print(Bipolar::plan.size()), puts("");
	for (auto id : Bipolar::plan) {
		print(nodes[id].size()), putchar(32);
		for (auto v : nodes[id]) {
			print(v), putchar(32);
		}
		puts("");
	}
}

} // namespace BCT

signed main() {
	n = read(), m = read();
	rep (i, 1, m) {
		int x = read(), y = read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	BCT::solve();
	return 0;
}
