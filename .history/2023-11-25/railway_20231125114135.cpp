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

const int MAXN = 2005;

#define int ll

vector <pair <int, int> > G[MAXN];
bool vis[MAXN];
int n, m, ans = 1e9, asq;

void dfs(int u, int step, int sum, int sq) {
	if (sum > ans) return;
	if (u == n) {
		if (sum < ans) ans = sum, asq = sq;
		else if (sum == ans) asq = min(asq, sq);
		return;
	}
	for (auto v : G[u]) {
		if (vis[v.first]) continue;
		vis[v.first] = 1;
		dfs(v.first, step + 1, sum + v.second, sq + pow(v.second, 2));
		vis[v.first] = 0;
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("railway.in", "r", stdin);
	freopen("railway.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	rep (i, 1, m) {
		int s;
		read(s);
		int lst;
		read(lst);
		int t, nxt;
		rep (i, 1, s) {
			read(t), read(nxt);
			G[lst].emplace_back(make_pair(nxt, t));
			lst = nxt;
		}
	}
	vis[1] = 1;
	dfs(1, 
	return 0;
}