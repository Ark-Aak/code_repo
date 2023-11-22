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

const int MAXN = 5e5 + 5;
int T, n, root = -1, cnt;
vector <int> G[MAXN];
int mn[MAXN], ans[MAXN];

void dfs1(int u, int fa) {
	mn[u] = G[u].size() == 1 ? u : INT_MAX;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs1(v, u);
		mn[u] = min(mn[u], mn[v]);
	}
}

int dfs2(int u, int fa) {
	int p = -1;
	for (auto v : G[u]) {
		if (v == fa) continue;
		if (p == -1 || mn[v] > mn[p]) p = v;
	}
	if (p == -1) return u;
	if (u > mn[p]) return u;
	return dfs2(p, u);
}

int dfs3(int u, int fa) {
	sort(G[u].begin(), G[u].end(), [](int x, int y) {return mn[x] < mn[y];});
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs3(v, u);
	}
	ans[++cnt] = u;
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
#endif
	read(T);
	while (T --> 0) {
		root = -1;
		read(n);
		memset(mn, 0, sizeof mn);
		memset(ans, 0, sizeof ans);
		cnt = 0;
		rep (i, 1, n) G[i].clear();
		rep (i, 1, n - 1) {
			int u, v;
			read(u), read(v);
			G[u].emplace_back(v);
			G[v].emplace_back(u);
		}
		rep (i, 1, n) {
			if (G[i].size() == 1) {
				root = i;
				break;
			}
		}
		dfs1(root, -1);
		root = dfs2(root, -1);
		dfs1(root, -1);
		dfs3(root, -1);
		rep (i, 1, n) print(ans[i]), putchar(32);
		putchar(10);
	}
	return 0;
}