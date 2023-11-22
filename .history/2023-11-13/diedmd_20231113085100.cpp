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

const int MAXN = 4e5 + 5;
int n, q, c[MAXN], dfn[MAXN], hvy[MAXN], siz[MAXN], dep[MAXN], fa[MAXN], top[MAXN], clk;
vector <int> G[MAXN];

void getHeavy(int u, int fa) {
	siz[u] = 1, hvy[u] = 0;
	for (auto v : G[u]) if (v != fa) {
		getHeavy(v, u);
		siz[u] += siz[v];
		if (siz[v] > siz[hvy[u]]) hvy[u] = v;
	}
}

void getDFN(int u, int header) {
	dfn[u] = ++clk, top[u] = header;
	if (!hvy[u]) return;
	getDFN(hvy[u], header);
	for (auto v : G[u]) if (v != fa[u] && v != hvy[u]) getDFN(v, v);
}

struct query {
	int x, y;
} qry[MAXN];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("diedmd.in", "r", stdin);
	freopen("diedmd.out", "w", stdout);
#endif
#endif
	read(n), read(q);
	rep (i, 1, n) read(c[i]);
	rep (i, 1, n - 1) {
		int u, v; read(u), read(v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	getHeavy(1, 0);
	getDFN(1, 1);
	return 0;
}