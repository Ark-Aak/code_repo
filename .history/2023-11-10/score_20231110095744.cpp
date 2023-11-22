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

const int MAXN = 1e5 + 5;
int n, m;
vector <int> G[MAXN];
int cnt[MAXN], w[MAXN];
vector <int> x[MAXN], y[MAXN];

namespace Subtask1 {
	int ans = 0;
	int fans = 0;

	void dfs(int u, int fa) {
		for (auto v : x[u]) {
			cnt[v]++;
			if (cnt[v] >= 2) ans += w[v];
		}
		for (auto v : y[u]) {
			cnt[v]++;
			if (cnt[v] >= 2) ans += w[v];
		}
		fans = max(fans, ans);
		for (auto v : G[u]) {
			if (v == fa) continue;
			dfs(v, u);
		}
	}

	void solve() {
		rep (i, 1, n) {
			ans = 0;
			memset(cnt, 0, sizeof cnt);
			dfs(i, i);
			fans = max(fans, ans);
		}
	}
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("score.in", "r", stdin);
	freopen("score.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	rep (i, 1, n - 1) {
		int u, v;
		read(u), read(v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	rep (i, 1, m) {
		int xx, yy;
		read(xx), read(yy), read(w[i]);
		x[xx].emplace_back(i), y[yy].emplace_back(i);
	}
	if (n <= 1000) {
		Subtask1::solve();
		print(Subtask1::fans), putchar(10);
		return 0;
	}
	return 0;
}