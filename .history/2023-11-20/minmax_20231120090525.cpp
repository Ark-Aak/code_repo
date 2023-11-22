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

const int MAXN = 2e5 + 5;
int n, k;
vector <pair <int, int> > G[MAXN];
int mn[5005][5005], mx[5005][5005];

void dfs(int ori, int mn, int mx, int u, int fa) {
	::mn[ori][u] = mn, ::mx[ori][u] = mx;
	for (auto v : G[u]) {
		if (v.first == fa) continue;
		int val = v.second;
		dfs(ori, min(mn, val), max(mx, val), v.first, u);
	}
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("minmax.in", "r", stdin);
	freopen("minmax.out", "w", stdout);
#endif
#endif
	read(n), read(k);
	rep (i, 1, n) {
		int u, v, w;
		read(u), read(v), read(w);
		G[u].emplace_back(make_pair(v, w));
		G[v].emplace_back(make_pair(u, w));
	}
	ll ans = 0;
	if (n <= 5000) {
		rep (i, 1, n) dfs(i, 0x3f3f3f3f, 0, i, 0);
		rep (i, 1, n) {
			rep (j, i + 1, n) {
				if (mx[i][j] - mn[i][j] == k) ans++;
			}
		}
	}
	return 0;
}