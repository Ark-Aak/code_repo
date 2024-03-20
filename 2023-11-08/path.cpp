#include <bits/stdc++.h>

#define rep(i, a, b) for (auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for (auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll
#define mid ((L + R) >> 1)
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)

const int MAXN = 2e5 + 5;
int n, m;
int mx[MAXN << 2], mn[MAXN << 2], w[MAXN], iw[MAXN];
int dfn[MAXN], wSon[MAXN], hSon[MAXN];
int cnt, fa[MAXN], dep[MAXN], top[MAXN];
vector <int> G[MAXN];

void pushup(int x) {
	mx[x] = max(mx[ls(x)], mx[rs(x)]);
	mn[x] = min(mn[ls(x)], mn[rs(x)]);
}

void build(int x, int L, int R) {
	if (L == R) return (void) (mx[x] = mn[x] = w[L]);
	build(ls(x), L, mid);
	build(rs(x), mid + 1, R);
	pushup(x);
}

pair <int, int> query(int x, int L, int R, int l, int r) {
	if (l <= L && R <= r) return make_pair(mx[x], mn[x]);
	pair <int, int> res = make_pair(0, 1e9);
	if (l <= mid) {
		auto tmp = query(ls(x), L, mid, l, r);
		res.first = max(res.first, tmp.first);
		res.second = min(res.second, tmp.second);
	}
	if (r > mid) {
		auto tmp = query(rs(x), mid + 1, R, l, r);
		res.first = max(res.first, tmp.first);
		res.second = min(res.second, tmp.second);
	}
	return res;
}

void getSize(int step, int u, int f) {
	wSon[u] = 1; fa[u] = f; dep[u] = step;
	for (auto v : G[u]) {
		if (v == f) continue;
		getSize(step + 1, v, u);
		wSon[u] += wSon[v];
		if (wSon[v] > wSon[hSon[u]]) hSon[u] = v;
	}
}

vector <int> chains[MAXN];
int ccnt = 0, bel[MAXN];

void getDFN(int u, int header, int ct) {
	dfn[u] = ++cnt, w[cnt] = iw[u], top[u] = header;
	ccnt = max(ccnt, ct);
	chains[ct].emplace_back(dfn[u]);
	bel[u] = ct;
	if (!hSon[u]) return;
	getDFN(hSon[u], header, ct);
	for (auto v : G[u]) {
		if (v == fa[u] || v == hSon[u]) continue;
		getDFN(v, v, ct + 1);
	}
}

int sum[MAXN];
int sum1[100][MAXN];
int sum2[100][MAXN];

int queryChain(int x, int y) {
	int ans = 0;
	pair <int, int> tmp;
	ans = sum2[bel[x]][dfn[x]];
	int mx = 0, mn = 1e9;
	tmp = query(1, 1, n, dfn[top[x]], dfn[x]);
	mx = max(mx, tmp.first), mn = min(mn, tmp.second);
	x = fa[top[x]];
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		tmp = query(1, 1, n, dfn[top[x]], dfn[x]);
		ans = max(ans, sum[bel[x]]);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);

	return ans;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("path.in", "r", stdin);
	freopen("path.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	rep (i, 1, n - 1) {
		int u, v;
		read(u), read(v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	rep (i, 1, n) read(iw[i]);
	getSize(1, 1, 1);
	getDFN(1, 1, 1);
	build(1, 1, n);
	rep (i, 1, ccnt) {
		int st = chains[i][0], ed = chains[i][chains[i].size() - 1];
		int ans = 0;
		while (st < ed) {
			ans = max(ans, w[st] - query(1, 1, n, st, ed).second);
			++st;
			sum1[i][st] = ans;
		}
		sum[i] = ans;
	}
	rep (i, 1, ccnt) {
		int st = chains[i][chains[i].size() - 1], ed = chains[i][0];
		int ans = 0;
		while (st > ed) {
			ans = max(ans, w[ed] - query(1, 1, n, ed, st).second);
			--st;
			sum2[i][st] = ans;
		}
	}
	while (m --> 0) {
		int u, v;
		read(u), read(v);
	}
	return 0;
}
