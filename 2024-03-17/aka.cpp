#include <bits/stdc++.h>

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

const int MAXN = 1e5 + 5;
int o, T, vis[MAXN], c[MAXN];
int n, m, ans, cc, cp;
vector <int> G[MAXN];

bool dfs(int u) {
	for (auto v : G[u]) {
		if (vis[v]) continue;
		vis[v] = 1;
		if (!c[v] || dfs(c[v])) return c[v] = u, 1;
	}
	return 0;
}

void solve() {
	n = read(), m = read();
	ans = cc = cp = 0;
	int ps = 0;
	memset(c, 0, sizeof c);
	rep (i, 1, n << 1) G[i].clear();
	rep (i, 1, m) {
		int u = read(), v = read();
		G[u + n].push_back(v);
		G[v].push_back(u + n);
		G[v + n].push_back(u);
		G[u].push_back(v + n);
	}
	rep (i, 1, n << 1) {
		memset(vis, 0, sizeof vis);
		dfs(i);
	}
	rep (i, 1, n) {
		if (c[i]) ans++;
		else {
			if (!c[i + n]) cp++, ps = i;
			else cc++;
		}
	}
	if (cp != 1 || cc) print(ans - cp - cc);
	else if (G[ps].size()) print(ans - cp - cc);
	else print(ans - cp - cc - 2);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("aka.in", "r", stdin);
	freopen("aka.out", "w", stdout);
#endif
#endif
	o = read(), T = read();
	while (T --> 0) solve(), puts("");
	return 0;
}
