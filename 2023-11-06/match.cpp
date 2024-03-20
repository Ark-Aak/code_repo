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

const int MAXN = 1e6 + 5;
vector <int> G[MAXN];
int n, m, ans;

int T;

namespace Solution {
	int deg[MAXN];

	void find(int step, int u, int fa, int ori) {
		if (step > 3) return;
		for (auto v : G[u]) {
			if (v == fa) continue;
			if (step == 3 && v == ori) return (void) (ans = max(ans, 3));
			find(step + 1, v, u, ori);
		}
	}

	void solve() {
		rep (i, 1, n) {
			ans = max(ans, deg[i]);
		}
		if (ans == 2) {
			rep (i, 1, n) find(1, i, i, i);
		}
	}
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
#endif
#endif
	read(T);
	while (T --> 0) {
		ans = 0;
		read(n), read(m);
		rep (i, 1, n) G[i].clear(), Solution::deg[i] = 0;
		rep (i, 1, m) {
			int u, v;
			read(u), read(v);
			G[u].emplace_back(v);
			G[v].emplace_back(u);
			++Solution::deg[u];
			++Solution::deg[v];
		}
		Solution::solve();
		print(ans), putchar(10);
	}
	return 0;
}
