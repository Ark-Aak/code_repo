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

const int MAXN = 1e5 + 5;
int n, c[MAXN], ans = 2e18, sum, wc[MAXN];
vector <int> G[MAXN];

void dfs1(int dep, int u, int fa) {
	sum += dep * c[u];
	wc[u] = c[u];
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs1(dep + 1, v, u);
		wc[u] += wc[v];
	}
}

void dfs2(int u, int fa) {
	ans = min(ans, sum);
	/* cout << "de:" << u << " " << sum << endl; */
	/* rep (i, 1, n) cout << wc[i] << " "; */
	/* cout << endl; */
	for (auto v : G[u]) {
		if (v == fa) continue;
		int tsum = sum;
		/* sum -= c[v]; */
		/* sum += c[u]; */
		sum -= wc[v];
		int ot = wc[u] - wc[v];
		sum += ot;
		int tvu = wc[u], tvv = wc[v];
		int tv = wc[u];
		wc[u] -= wc[v];
		wc[v] = tv;
		dfs2(v, u);
		sum = tsum;
		wc[u] = tvu;
		wc[v] = tvv;
	}
}

signed main() {
	n = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep (i, 1, n) c[i] = read();
	dfs1(0, 1, 0);
	dfs2(1, 0);
	print(ans), putchar('\n');
	return 0;
}
