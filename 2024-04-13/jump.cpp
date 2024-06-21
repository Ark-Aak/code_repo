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

const int MAXN = 2e5 + 5;
int n, k, w[MAXN];
vector <int> G[MAXN];

namespace subtask1 {

	int ans = 0, cnt = 0;
	int tgt, ch[MAXN];

	void dfs(int u, int fa, int sum) {
		if (ans < sum) ans = sum, tgt = u;
		for (auto v : G[u]) {
			if (v == fa) continue;
			dfs(v, u, sum + w[v]);
		}
	}

	void printAns(int step, int u, int fa) {
		ch[step] = u;
		if (u == tgt) {
			print(step), puts("");
			rep (i, 1, step) print(ch[i]), putchar(32);
			return;
		}
		for (auto v : G[u]) {
			if (v == fa) continue;
			printAns(step + 1, v, u);
		}
	}

	void solve() {
		dfs(1, 0, w[1]);
		print(ans), puts("");
		printAns(1, 1, 0);
	}
} // namespace subtask1

namespace subtask2 {

	bool vis[MAXN];
	int h[MAXN];
	vector <int> pth;

	void dfs(int u, int fa, int flg) {
		if (!flg) pth.push_back(u);
		for (auto v : G[u]) {
			if (v == fa) continue;
			dfs(v, u, flg ^ 1);
		}
		if (flg) pth.push_back(u);
	}

	void solve() {
		int ans = 0;
		rep (i, 1, n) ans += w[i];
		print(ans), puts("");
		print(n), puts("");
		dfs(1, 0, 0);
		for (auto v : pth) print(v), putchar(32);
	}
} // namespace subtask2

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
#endif
#endif
	n = read(), k = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep (i, 1, n) w[i] = read();
	if (k == 1) return subtask1::solve(), 0;
	if (k == 3) return subtask2::solve(), 0;
	return 0;
}
