#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

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

const int MAXN = 5e3 + 5;
int n, v[MAXN];
vector <int> G[MAXN];
int ans, buc[MAXN], ig, seq[MAXN], pos[MAXN];

void dfs(int s, int u, int fa, int o) {
	pos[s] = u;
	seq[s] = v[u];
	buc[v[u]]++;
	int tig = ig;
	if (v[u] != buc[s]) ig++;
	if (s != v[u] && pos[v[u]] && v[pos[v[u]]] == buc[v[u]]) ig--;
	if (s != v[u] && pos[v[u]] && v[pos[v[u]]] == buc[v[u]] - 1) ig++;
	if (!ig) {
		ans++;
	}
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(s + 1, v, u, o);
	}
	pos[s] = 0;
	seq[s] = 0;
	buc[v[u]]--;
	ig = tig;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("www.in", "r", stdin);
	freopen("www.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) v[i] = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep (i, 1, n) {
		dfs(0, i, 0, i);
		memset(buc, 0, sizeof buc);
		ig = 0;
		memset(seq, 0, sizeof seq);
		memset(pos, 0, sizeof pos);
	}
	print(ans);
	return 0;
}
