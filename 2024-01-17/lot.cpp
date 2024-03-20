#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,sse2,sse3,sse4")

#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)

#define int ll

using namespace std;

typedef long long ll;

int read() {
	ll x = 0, f = 1;
	char c = getchar();
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
	if (x < 0)
		x = (~x + 1), putchar('-');
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 2e5 + 5;

int n, a[MAXN];
vector <int> e[MAXN];
bool vis[MAXN];
int maxn[MAXN], siz[MAXN], sum, ans[MAXN], rt;

void getRoot(int u, int fa) {
	maxn[u] = 0, siz[u] = 1;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (v == fa || vis[v]) continue;
		getRoot(v, u);
		siz[u] += siz[v];
		maxn[u] = max(maxn[u], siz[v]);
	}
	maxn[u] = max(maxn[u], sum - siz[u]);
	if (maxn[u] < maxn[rt]) rt = u;
}

int s;
vector <int> f[MAXN];

void merge(vector <int> &a, vector <int> &b) {
	if (a.size() < b.size()) swap(a, b);
	for (int i = 0; i < b.size(); i++) a[i] = max(a[i], b[i]);
	b.clear();
}

pair <int, int> add(vector <int> &a, int x) {
	int w = lower_bound(a.begin(), a.end(), x, greater<int>()) - a.begin();
	if (w == a.size()) {
		a.push_back(x);
		return {w, -1};
	} else {
		int lst = a[w];
		a[w] = x;
		return {w, lst};
	}
}

void dp(int u, int fa) {
	siz[u] = 1;
	pair <int, int> lst = add(f[s], a[u]);
	ans[u] = max(ans[u], lst.first + 1);
	for (auto v : e[u]) {
		if (v == fa || vis[v]) continue;
		dp(v, u);
		siz[u] += siz[v];
	}
	if (lst.second == -1) f[s].pop_back();
	else f[s][lst.first] = lst.second;
}

void mergedp(int u, int fa) {
	f[u].clear();
	for (auto v : e[u]) {
		if (v == fa || vis[v]) continue;
		mergedp(v, u);
		merge(f[u], f[v]);
	}
	add(f[u], a[u]);
}

void calc(int u) {
	f[u].clear(), s = u;
	for (auto v : e[u]) {
		if (vis[v]) continue;
		pair <int, int> lst = add(f[u], a[u]);
		dp(v, u);
		if (lst.second == -1) f[u].pop_back();
		else f[u][lst.first] = lst.second;
		mergedp(v, u);
		merge(f[u], f[v]);
	}
	pair <int, int> lst = add(f[u], a[u]);
	ans[u] = max(ans[u], lst.first + 1);
	if (lst.second == -1) f[u].pop_back();
	else f[u][lst.first] = lst.second;
}

void solve(int u) {
	vis[u] = 1;
	calc(u);
	reverse(e[u].begin(), e[u].end());
	calc(u);
	reverse(e[u].begin(), e[u].end());
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i];
		if (vis[v]) continue;
		sum = siz[v], rt = 0;
		getRoot(v, u);
		solve(rt);
	}
}

signed main() {
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i < n; i++) {
		int u = read(), v = read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	maxn[0] = sum = n;
	getRoot(1, 0);
	solve(rt);
	for (int i = 1; i <= n; i++) {
		print(ans[i]);
		putchar(10);
	}
	return 0;
}