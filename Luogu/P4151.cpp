#include <bits/stdc++.h>

#define int ll

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

struct Basis {

	vector <int> B;

	void insert(int x) {
		for (auto v : B) x = min(x, x ^ v);
		if (!x) return;
		for (auto &v : B) v = min(v, v ^ x);
		B.push_back(x);
	}

	int query(int res) { for (auto v : B) res = max(res, res ^ v); return res; }
} b;

const int MAXN = 5e4 + 5;
int n, m;
vector <pii> G[MAXN];
bool vis[MAXN];
int dis[MAXN];

void dfs(int u, int fa) {
	vis[u] = 1;
	for (auto [v, w] : G[u]) {
		if (v == fa) continue;
		if (vis[v]) {
			b.insert(dis[u] ^ dis[v] ^ w);
			continue;
		}
		dis[v] = dis[u] ^ w;
		dfs(v, u);
	}
}

signed main() {
	n = read(), m = read();
	rep (i, 1, m) {
		int s = read(), t = read(), d = read();
		G[s].push_back(dl(t, d));
		G[t].push_back(dl(s, d));
	}
	dfs(1, 0);
	print(b.query(dis[n]));
	return 0;
}
