#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

const int MAXN = 5e4 + 5;
int n, k;
vector <int> G[MAXN];

#define mid ((L + R) >> 1)
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)

int ans;
int dfn[MAXN], wSon[MAXN], hSon[MAXN];
int cnt, fa[MAXN], dep[MAXN], top[MAXN];
int val[MAXN];

void getSize(int step, int u, int f) {
	wSon[u] = 1; fa[u] = f; dep[u] = step;
	for (auto v : G[u]) {
		if (v == f) continue;
		getSize(step + 1, v, u);
		wSon[u] += wSon[v];
		if (wSon[v] > wSon[hSon[u]]) hSon[u] = v;
	}
}

void getDFN(int u, int header) {
	dfn[u] = ++cnt, top[u] = header;
	if (!hSon[u]) return;
	getDFN(hSon[u], header);
	for (auto v : G[u]) {
		if (v == fa[u] || v == hSon[u]) continue;
		getDFN(v, v);
	}
}

int LCA(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	return x;
}

void calc(int u, int fa, int sum) {
	sum += val[u];
	ans = max(ans, sum);
	for (auto v : G[u]) {
		if (v == fa) continue;
		calc(v, u, sum);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("flow.in", "r", stdin);
	freopen("flow.out", "w", stdout);
#endif
#endif
	read(n), read(k);
	rep (i, 1, n - 1) {
		int u, v;
		read(u), read(v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	getSize(1, 1, 1);
	getDFN(1, 1);
	rep (i, 1, k) {
		int s, t;
		read(s), read(t);
		val[s]++;
		int lca = LCA(s, t);
		val[fa[lca]]--;
		val[t]--;
	}
	calc(1, 1, 0);
	cout << ans;
	return 0;
}