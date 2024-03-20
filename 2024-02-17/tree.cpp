#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

const int MAXN = 55;
int n, m, q;
vector <pair <int, int> > G[MAXN];
bool vis[MAXN];

int fa[MAXN];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx != fy) fa[fx] = fy;
}

int sum[MAXN];
const int MOD = 1e9 + 9;

int qpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1, a = a * a % MOD) if (b & 1) res = res * a % MOD;
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
#endif
	/* freopen("ex_tree2.in", "r", stdin); */
	n = read(), m = read(), q = read();
	rep (i, 1, n) fa[i] = i, sum[i] = -1;
	rep (i, 1, m) {
		int u = read(), v = read(), w = read();
		if (u > v) swap(u, v);
		G[u].push_back(make_pair(v, w));
		G[v].push_back(make_pair(u, w));
		/* if (find(u) == find(v)) sum[find(v)] = -1; */
		merge(u, v);
	}
	rep (i, 1, n) {
		for (auto [v, w] : G[i]) {
			if (i > v) continue;
			if (sum[find(i)] == -1) sum[find(i)] = 0;
			sum[find(i)] += (w == 2);
		}
	}
	int ans = 0;
	rep (i, 1, n) ans = (ans + (sum[i] < 0 ? 0 : qpow(2, sum[i]))) % MOD;
	while (q --> 0) print(ans), putchar(10);
	return 0;
}
