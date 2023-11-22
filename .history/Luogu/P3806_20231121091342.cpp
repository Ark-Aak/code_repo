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

const int MAXN = 1e4 + 5;
int n, m, root;
vector <pair <int, int> > G[MAXN];
int siz[MAXN], p[MAXN], r[MAXN], dis[MAXN];
bitset <10000005> mk, t;
bitset <MAXN> vis;

void update_root(int u, int fa) {
	siz[u] = 1, p[u] = 0;
	for (auto v : G[u]) {
		if (v.first == fa) continue;
		update_root(v.first, u);
		siz[u] += siz[v.first];
		p[u] = max(p[u], siz[v.first]);
	}
	p[u] = max(p[u], n - siz[u]);
	if (p[u] < p[root]) root = u;
}

void get_dis(int u, int fa) {
	r[++r[0]] = dis[u];
	for (auto v : G[u]) {
		if (v.first == fa) continue;
		dis[v.first] = dis[u] + v.second;
		get_dis(v.first, u);
	}
}

int query[MAXN];

void calc(int u) {
	for (auto x : G[u]) {
		int v = x.first, w = x.second;
		if (vis[v]) continue;
		r[0] = 0; dis[v] = dis[u] + w;
		get_dis(v, u);
		rep (i, 1, r[0]) {
			rep (j, 1, m) {
				if (query[j] < r[i]) continue;
				if (t[query[j] - r[i]]) mk[j] = 1;
			}
		}
	}
}

int main() {
	read(n), read(m);
	rep (i, 1, n - 1) {
		int u, v, w;
		read(u), read(v), read(w);
		G[u].emplace_back(v, w);
		G[v].emplace_back(u, w);
	}
	rep (i, 1, m) read(query[i]);
	return 0;
}