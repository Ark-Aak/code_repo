#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= b; i++)
#define _rep(i, a, b) for(int i = (a); i >= b; i--)

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

const int MAXN = 2e5 + 5;
vector <int> G[MAXN];
int n, k;
int a[MAXN], w[MAXN], ans, len[MAXN], wy[MAXN], awy[MAXN], epos;

void dfs(int step, int now, int sum, int fa) {
	a[now] = sum;
	if (sum > ans) {
		ans = sum;
		rep (i, 1, step) awy[i] = wy[i];
		epos = now;
	}
	len[now] = len[fa] + 1;
	for (auto x : G[now]) {
		if (x != fa) wy[step + 1] = x, dfs(step + 1, x, sum + w[x], now);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
#endif
#endif
	cin >> n >> k;
	rep (i, 2, n) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	rep (i, 1, n) cin >> w[i];
	if (k == 1) {
		wy[1] = 1;
		dfs(1, 1, w[1], 1);
		cout << a[epos] << endl;
		cout << len[epos] << endl;
		rep (i, 1, len[epos]) cout << awy[i] << " ";
		return 0;
	}
	return 0; 
}
