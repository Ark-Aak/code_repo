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

const int MAXN = 1e6 + 5;

string s, t, p;
int ns, nt, np, osum, ans[MAXN];

struct KMP {
	int nxt[MAXN], sum[MAXN], flg[MAXN];
	int lst[MAXN];
	string s, t, p;

	int init() {
		int j = 0;
		rep (i, 2, np) {
			while (j && p[i] != p[j + 1]) j = nxt[j];
			if (p[i] == p[j + 1]) j++;
			nxt[i] = j;
		}
		j = 0;
		rep (i, 1, nt) {
			while ((j == np) || (j && t[i] != p[j + 1])) j = nxt[j];
			if (t[i] == p[j + 1]) j++;
			if (j == np) osum++;
		}
		return j;
	}

	void solve(int op) {
		rep (i, 1, np) sum[i] = (sum[nxt[i]] + flg[np - i]);
		int res = 0, j = 0;
		rep (i, 0, ns) {
			while ((j == np) || (j && s[i] != p[j + 1])) j = nxt[j];
			if (s[i] == p[j + 1]) j++;
			lst[i] = j;
			if (j == np) j = nxt[j], res++;
			if (!op) ans[i] += res + sum[j];
			else ans[ns - i] += res + sum[j];
		}
	}
} S, T;

int nxt[MAXN], dfn[MAXN], lst[MAXN], cnt, vis[MAXN];

namespace BIT {

	int sum[MAXN];

	void add(int x, int val) {
		for (int o = x; o <= cnt; o += o & -o)
			sum[o] += val;
	}

	int query(int x, int res = 0) {
		for (int o = x; o; o -= o & -o)
			res += sum[o];
		return res;
	}
} // namespace BIT

vector <int> g1[MAXN], g2[MAXN];
vector <pii> e[MAXN];

void dfs1(int u) {
	dfn[u] = ++cnt;
	for (auto v : g2[u]) dfs1(v);
	lst[u] = cnt;
}

void dfs2(int u) {
	if (u && vis[u + nt] && np - (u + nt)) {
		BIT::add(dfn[np - (u + nt)], 1);
		BIT::add(lst[np - (u + nt)] + 1, -1);
	}
	for (auto [x, y] : e[u]) ans[y] += BIT::query(dfn[x]);
	for (auto v : g1[u]) dfs2(v);
	if (u && vis[u + nt] && np - (u + nt)) {
		BIT::add(dfn[np - (u + nt)], -1);
		BIT::add(lst[np - (u + nt)] + 1, 1);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("lgs.in", "r", stdin);
	freopen("lgs.out", "w", stdout);
#endif
#endif
	cin >> s >> t >> p;
	ns = s.size(), nt = t.size(), np = p.size();
	S.s = " " + s, S.t = " " + t, S.p = " " + p;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());
	reverse(p.begin(), p.end());
	T.s = " " + s, T.t = " " + t, T.p = " " + p;
	s = " " + s, t = " " + t, p = " " + p;
	int psx = S.init(), psy = T.init();
	osum >>= 1;
	if (psx == np) psx = S.nxt[psx];
	if (psy == np) psy = S.nxt[psy];
	while (psx) {
		T.flg[psx]++;
		psx = S.nxt[psx];
	}
	while (psy) {
		S.flg[psy]++;
		psy = T.nxt[psy];
	}
	S.solve(0), T.solve(1);
	if (nt < np) {
		int j = 0;
		rep (i, 2, nt) {
			while (j && S.t[i] != S.t[j + 1]) j = nxt[j];
			if (S.t[i] == S.t[j + 1]) j++;
			nxt[i] = j;
		}
		j = 0;
		rep (i, 1, np) {
			while ((j == nt) || (j && S.p[i] != S.t[j + 1])) j = nxt[j];
			if (S.p[i] == S.t[j + 1]) j++;
			if (j == nt) vis[i] = 1;
		}
		rep (i, 1, np) {
			g1[S.nxt[i]].push_back(i);
			g2[T.nxt[i]].push_back(i);
		}
		dfs1(0);
		rep (i, 0, ns) {
			int L = S.lst[i], R = T.lst[ns - i];
			if (L && R) e[L].push_back({R, i});
		}
		dfs2(0);
	}
	int L = 0, R = 0, mx = 0, cnt = 0;
	rep (i, 0, ns) {
		if (mx < ans[i]) {
			L = i, R = i, cnt = 0;
			mx = ans[i];
		}
		if (mx == ans[i]) R = i, cnt++;
	}
	cout << mx + osum << " " << cnt << " " << L << " " << R << endl;
	return 0;
}
