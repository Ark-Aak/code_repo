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
vector <pair <int, int> > G[MAXN];
vector <pair <int, int> > edges;
int siz[MAXN], ans;
int mk[MAXN];

void calcSize(int u, int fa) {
	siz[u] = 1;
	for (auto x : G[u]) {
		int v = x.first;
		if (v == fa) continue;
		calcSize(v, u);
		siz[u] += siz[v];
	}
}

void dfs(int u, int fa) {
	for (auto x : G[u]) {
		int v = x.first;
		if (mk[x.second]) continue;
		ans = max(ans, siz[v] * (n - siz[v]));
		mk[x.second] = 1;
	}
	for (auto x : G[u]) {
		int v = x.first;
		if (v == fa) continue;
		siz[u] = (n - siz[v]);
		siz[v] = n;
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
		G[u].emplace_back(make_pair(v, edges.size()));
		G[v].emplace_back(make_pair(u, edges.size()));
		edges.emplace_back(make_pair(u, v));
	}

	return 0;
}