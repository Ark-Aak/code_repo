#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

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

const int MAXN = 1e6 + 5;
int iw[MAXN], w[MAXN];
int Min[MAXN][21];

int wSon[MAXN], hSon[MAXN], siz[MAXN], fa[MAXN], dfn[MAXN], dep[MAXN];
int top[MAXN], cnt;
vector <int> G[MAXN];
int n, q, minnTop = INT_MAX, lca;

void build() {
	rep (i, 1, n) Min[i][0] = w[i];
	rep (j, 1, 21)
		for(int i = 1; i + (1 << j) - 1 <= n; i++)
			Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r) {
	int k = log2(r - l + 1);
	return min(Min[l][k], Min[r - (1 << k) + 1][k]);
}

void getSize(int step, int u, int fa) {
	::fa[u] = fa, dep[u] = step, siz[u] = 1;
	for (auto v : G[u]) {
		if (v == fa) continue;
		getSize(step + 1, v, u);
		siz[u] += siz[v];
		if (siz[v] > siz[hSon[u]]) hSon[u] = v;
	}
}

void getDFN(int u, int h) {
	top[u] = h, dfn[u] = ++cnt, w[dfn[u]] = iw[u];
	if (!hSon[u]) return;
	getDFN(hSon[u], h);
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

int calcChain(int x, int y) {
	int res = INT_MAX;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		res = min(res, query(dfn[top[x]], dfn[x]));
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	res = min(res, query(dfn[x], dfn[y]));
	return res;
}

void JC(int x) {
	if (!lca) return (void) (lca = x, minnTop = iw[x]);
	int oldLCA = lca;
	lca = LCA(lca, x);
	minnTop = min(calcChain(oldLCA, lca), minnTop);
	minnTop = min(calcChain(x, lca), minnTop);
}

int Query(int x) {
	int ans = INT_MAX;
	ans = min(ans, min(calcChain(x, lca), minnTop));
	return ans;
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
#endif
#endif
	read(n), read(q);
	rep (i, 1, n - 1) {
		int u, v;
		read(u), read(v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	rep (i, 1, n) iw[i] = i;
	getSize(1, 1, 1);
	getDFN(1, 1); build();
	while (q --> 0) {
		char op[10];
		scanf("%s", op);
		int x; read(x);
		if (op[0] == 'J') JC(x);
		else print(Query(x)), putchar(10);
	}
	return 0; 
}

//时间复杂度 O(n\alpha(log^2n)), \alpha(n) = 8 \times n
