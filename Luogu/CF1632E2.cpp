#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (auto i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (auto i = (a), i##end = (b); i >= i##end; i--)

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, w = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') w = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = x * 10 + (c ^ 48);
		c = getchar();
	}
	return x * w;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

const int MAXN = 3e5 + 5;
int T, n;
vector <int> G[MAXN];
int dep[MAXN], mx[MAXN];
int val[MAXN];

void dfs(int u, int fa) {
	mx[u] = dep[u] = dep[fa] + 1;
	int mxa = mx[u], mxb = mx[u];
	for (auto v : G[u]) {
		if (v ^ fa) {
			dfs(v, u);
			mx[u] = max(mx[u], mx[v]);
			if (mx[v] > mxa) {
				mxb = mxa;
				mxa = mx[v];
			}
			else if (mx[v] > mxb) {
				mxb = mx[v];
			}
		}
	}
	if (mxb > 0) val[mxb - 1] = max(val[mxb - 1], mxa + mxb - 2 * dep[u]);
}

void solve() {
	n = read();
	rep (i, 1, n) vector <int>().swap(G[i]);
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep (i, 0, n + 1) val[i] = 0;
	rep (i, 1, n) dep[i] = mx[i] = 0;
	dep[0] = -1;
	dfs(1, 0);
	int cur = 0;
	_rep (i, n, 0) {
		val[i] = max(val[i + 1], val[i]);
	}
	rep (i, 1, n) {
		while (cur < mx[1] && ((val[cur] + 1) >> 1) + i > cur) cur++;
		print(cur), putchar(32);
	}
	puts("");
}

signed main() {
	T = read();
	while (T --> 0) solve();
	return 0;
}
