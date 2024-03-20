#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

#define int ll

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

const int MAXN = 1e6 + 5, MAXM = 2e6 + 5;
int fa[MAXN];

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	fa[find(y)] = find(x);
}

int n, m, q, ans;
vector <int> edges[MAXN];
int w[MAXN], f[MAXN], dep[MAXN];
int st[MAXN << 1][30];

int cntN;

void dfs(int u, int step, int fa) {
	f[u] = fa, dep[u] = step;
	for (auto v : edges[u]) {
		if (v == fa) continue;
		dfs(v, step + 1, u);
	}
}

int LCA(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	_rep (i, 30, 0) if (dep[x] - (1 << i) >= dep[y]) x = st[x][i];
	if (x == y) return x;
	_rep (i, 30, 0) {
		if (st[x][i] != st[y][i]) x = st[x][i], y = st[y][i];
	}
	return st[x][0];
}

int val[MAXN];

signed main() {
	read(n), read(m), read(q);
	rep (i, 1, n) fa[i] = i;
	cntN = n;
	rep (i, 1, m) {
		int u, v;
		read(u), read(v);
		if (find(u) == find(v)) continue;
		merge(u, v);
		edges[++cntN].emplace_back(v);
		edges[cntN].emplace_back(u);
		edges[u].emplace_back(cntN);
		edges[v].emplace_back(cntN);
		w[cntN] = i;
	}
	dfs(cntN, 1, cntN);
	rep (i, 1, n << 1) st[i][0] = f[i];
	for (int i = 1; (1 << i) <= cntN; i++) {
		rep (j, 1, (n << 1)) {
			st[j][i] = st[st[j][i - 1]][i - 1];
		}
	}
	rep (i, 1, n - 1) {
		val[i] = w[LCA(i, i + 1)];

	}
	memset(st, 0, sizeof st);
	rep (i, 1, n - 1) st[i][0] = val[i];
	rep (j, 1, log2(n)) {
		rep (i, 1, n - (1 << j) + 1) {
			st[i][j] = max(st[i + (1 << (j - 1))][j - 1], st[i][j - 1]);
		}
	}
	rep (i, 1, q) {
		int l, r;
		read(l), read(r);
		if (l == r) continue;
		int t = log2(r - l + 1);
		ans ^= max(st[l][t], st[r - (1 << t) + 1][t]);
	}
	print(ans);
	return 0;
}
