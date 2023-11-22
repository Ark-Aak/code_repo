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
int n, m, root, sum, cnt;
vector <pair <int, int> > G[MAXN];
int siz[MAXN], p[MAXN], dis[MAXN];
bool mk[10000005], t[10000005];
bool vis[MAXN];
pair <int, int> r[MAXN];

void update_root(int u, int fa) {
	siz[u] = 1, p[u] = 0;
	for (auto v : G[u]) {
		if (v.first == fa || vis[v.first]) continue;
		update_root(v.first, u);
		siz[u] += siz[v.first];
		p[u] = max(p[u], siz[v.first]);
	}
	p[u] = max(p[u], sum - siz[u]);
	if (p[u] < p[root]) root = u;
}

void get_dis(int u, int fa, int mx, int mn) {
	r[++cnt] = make_pair(mx, mn);
	for (auto v : G[u]) {
		if (v.first == fa || vis[v.first]) continue;
		dis[v.first] = dis[u] + v.second;
		get_dis(v.first, u);
	}
}

int query[MAXN];
int diff[MAXN], dcnt = 0;

void calc(int u) {
	dcnt = 0;
	for (auto x : G[u]) {
		int v = x.first, w = x.second;
		if (vis[v]) continue;
		r[0] = 0; dis[v] = w;
		get_dis(v, u);
		rep (i, 1, r[0]) {
			rep (j, 1, m) {
				if (query[j] >= r[i]) mk[j] |= t[query[j] - r[i]];
			}
		}
		rep (i, 1, r[0]) {
			if (!t[r[i]]) diff[++dcnt] = r[i];
			t[r[i]] = 1;
		}
	}
	rep (i, 1, dcnt) t[diff[i]] = 0;
}

void solve(int u) {
	vis[u] = 1, t[0] = 1;
	calc(u);
	for (auto x : G[u]) {
		int v = x.first;
		if (vis[v]) continue;
		sum = siz[v];
		p[root = 0] = 1e9;
		update_root(v, 0);
		solve(root);
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
	p[root] = sum = n;
	update_root(1, 0);
	update_root(root, 0);
	solve(root);

	return 0;
}