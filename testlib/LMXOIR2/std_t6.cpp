#include <bits/stdc++.h>

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

const int MAXN = 1e6 + 5;
const int MOD = 998244353;
int low[MAXN], dfn[MAXN], stk[MAXN], clk, top, n, m;
int S, T, cnt;
vector <int> G[MAXN];
vector <int> nt[MAXN];
bitset <MAXN> vis;

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
					/* cerr << x << " <-> " << n + cnt << endl; */
				} while (x != v);
				nt[n + cnt].push_back(u);
				nt[u].push_back(n + cnt);
				/* cerr << u << " <-> " << n + cnt << endl; */
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
	/* cerr << "x:" << u << endl; */
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
	/* cerr << "y:" << u << endl; */
	for (auto v : nt[u]) {
		if (v == fa || nt[v].size() == 1) continue;
		if (dfs2(v, u)) return true;
	}
	if (u >= n) return ph.push_back(u), true;
	return false;
}

int ord[MAXN];

namespace Bipolar {

	vector <int> T[MAXN];
	vector <int> nxt[MAXN];
	vector <int> plan, chain;
	int fa[MAXN], deg[MAXN];
	bitset <MAXN> rm;

	bool tarjan(int u, int t) {
		bool flg = (u == t);
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
		clk = 0;
		memset(low, 0, sizeof low);
		memset(dfn, 0, sizeof dfn);
		top = 0;
		memset(stk, 0, sizeof stk);
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
		rep (i, 0, ccnt - 1) ord[plan[i]] = i + 1;
	}
} // namespace Bipolar

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % MOD;
		a = 1ll * a * a % MOD;
		b >>= 1;
	}
	return res;
}

unordered_map <int, int> id[MAXN];

signed main() {
	n = read(), m = read(), S = read(), T = read();
	rep (i, 1, m) {
		int x = read(), y = read();
		G[x].push_back(y);
		G[y].push_back(x);
		id[x][y] = i;
	}
	tarjan(S);
	dfs0(S, 0, T);
	reverse(chain.begin(), chain.end());
	/* for (auto v : chain) cerr << v << " "; */
	/* cerr << endl; */
	for (auto v : chain) vis[v] = 1;
	int ok = 1;
	for (auto u : chain) {
		int cnt = 0;
		for (auto v : nt[u]) {
			if (vis[v] || nt[v].size() == 1) continue;
			++cnt;
		}
		if (u <= n && cnt > 1) { ok = 0; break; }
		if (u > n && cnt > 2) { ok = 0; break; }
		for (auto v : nt[u]) {
			if (vis[v] || nt[v].size() == 1) continue;
			ok &= (dfs1(v, u) ? dfs2(v, u), 1 : 0);
		}
		if (ph.size() > 2) ok = 0;
		if (!ok) break;
	}
	const int INV = qpow(1ll * n * (n + 1) / 2 % MOD, MOD - 2);
	if (ok) {
		rep (i, 1, n) Bipolar::T[i] = G[i];
		string str;
		rep (i, 1, m) str += '0';
		if (ph.size() == 0) {
			print(1ll * n * (n - 1) % MOD * qpow(2, MOD - 2) % MOD * INV % MOD), puts("");
			Bipolar::T[1].push_back(2);
			Bipolar::T[2].push_back(1);
			Bipolar::solve(S, T, n);
			rep (i, 1, n) {
				for (auto v : G[i]) {
					if (!id[i][v]) continue;
					if (ord[i] < ord[v]) str[id[i][v] - 1] = '0';
					else str[id[i][v] - 1] = '1';
				}
			}
			/* if (ord[1] < ord[2]) puts("1 2"); */
			/* else puts("2 1"); */
		}
		else if (ph.size() == 1) {
			int cir = (int) nt[ph[0]].size() - 1;
			int fa = 0;
			int ps = ph[0], lst = 0;
			while (!vis[ps]) {
				for (auto v : nt[ps]) {
					if (v == lst || nt[v].size() == 1) continue;
					lst = ps;
					ps = v;
					break;
				}
			}
			fa = ps;
			int lenM = chain.size() / 2 + (fa > n);
			for (auto u : chain) {
				for (auto v : nt[u]) {
					if (vis[v] || nt[v].size() > 1) continue;
					lenM++;
				}
			}
			int pln = 1ll * cir * lenM % MOD;
			print(1ll * pln * INV % MOD), puts("");
			int au = 0, av = 0;
			for (auto v : nt[ph[0]]) {
				if (nt[v].size() != 1) continue;
				au = v;
				int pt = 0;
				while (chain[pt] == fa || chain[pt] > n) pt++;
				av = chain[pt];
				break;
			}
			Bipolar::T[au].push_back(av);
			Bipolar::T[av].push_back(au);
			Bipolar::solve(S, T, n);
			rep (i, 1, n) {
				for (auto v : G[i]) {
					if (!id[i][v]) continue;
					if (ord[i] < ord[v]) str[id[i][v] - 1] = '0';
					else str[id[i][v] - 1] = '1';
				}
			}
			/* if (ord[au] < ord[av]) print(au), putchar(32), print(av); */
			/* else print(av), putchar(32), print(au); */
			/* puts(""); */
		}
		else {
			int cir0 = (int) nt[ph[0]].size() - 1;
			int cir1 = (int) nt[ph[1]].size() - 1;
			int pln = 1ll * cir0 * cir1 % MOD;
			print(1ll * pln * INV % MOD), puts("");
			int au = 0, av = 0;
			for (auto v : nt[ph[0]]) {
				if (nt[v].size() != 1) continue;
				au = v;
				break;
			}
			for (auto v : nt[ph[1]]) {
				if (nt[v].size() != 1) continue;
				av = v;
				break;
			}
			Bipolar::T[au].push_back(av);
			Bipolar::T[av].push_back(au);
			Bipolar::solve(S, T, n);
			rep (i, 1, n) {
				for (auto v : G[i]) {
					if (!id[i][v]) continue;
					if (ord[i] < ord[v]) str[id[i][v] - 1] = '0';
					else str[id[i][v] - 1] = '1';
				}
			}
			/* if (ord[au] < ord[av]) print(au), putchar(32), print(av); */
			/* else print(av), putchar(32), print(au); */
			/* puts(""); */
		}
		/* puts(str.c_str()); */
	}
	else {
		puts("0");
		rep (i, 1, n + cnt) vector <int>().swap(nt[i]);
		cnt = 0;
		G[S].push_back(T);
		G[T].push_back(S);
		memset(stk, 0, sizeof stk);
		top = 0;
		memset(low, 0, sizeof low);
		memset(dfn, 0, sizeof dfn);
		clk = 0;
		tarjan(S);
		int fa = 0;
		for (auto v : nt[S]) if (v > n) {
			bool flg = 0;
			for (auto p : nt[v]) {
				if (p == T) {
					fa = v;
					flg = 1;
					break;
				}
			}
			if (flg) break;
		}
		vis.reset();
		for (auto v : nt[fa]) vis[v] = 1;
		int cnt = 0;
		rep (i, 1, n) if (!vis[i]) cnt++;
		print(cnt), puts("");
		/* rep (i, 1, n) if (!vis[i]) print(i), putchar(32); */
		/* puts(""); */
	}
	return 0;
}
