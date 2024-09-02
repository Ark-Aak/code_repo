#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define ec first
#define fb second
#define de(x) cerr << #x << " = " << (x) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, w = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + (ch ^ 48);
		ch = getchar();
	}
	return x * w;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

int n, q;
int dis[105][105];

int tdis[105];

void dfs0(int step, int now, int fa) {
	rep (i, 1, n) {
		if (!dis[now][i]) continue;
		if (i == fa) continue;
		tdis[i] = tdis[now] + dis[now][i];
		dfs0(step + 1, i, now);
	}
}

vector <pii> edges;

int calc() {
	tdis[1] = 0;
	dfs0(0, 1, 0);
	int mx = 0, pos = 0;
	rep (i, 1, n) if (tdis[i] > mx) mx = tdis[i], pos = i;
	tdis[pos] = 0;
	dfs0(0, pos, 0);
	mx = 0;
	rep (i, 1, n) mx = max(mx, tdis[i]);
	return mx;
}

int ans = 1e9;

void dfs(int step, int k) {
	int val = calc();
	if (val >= ans) return;
	if (step > k) {
		ans = min(ans, val);
		return;
	}
	for (auto [u, v] : edges) {
		dis[u][v]++, dis[v][u]++;
		dfs(step + 1, k);
		dis[u][v]--, dis[v][u]--;
	}
}

int main() {
#ifndef LOCAL
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
	n = read();
	if (n > 20) {
		int k = 0;
		rep (i, 1, n - 1) k = read();
		q = read();
		while (q --> 0) {
			k = read();
			print(n - 1 + k), puts("");
		}
		return 0;
	}
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		dis[u][v] = dis[v][u] = 1;
		edges.push_back(dl(u, v));
	}
	q = read();
	while (q --> 0) {
		int k = read();
		ans = 1e9;
		dfs(1, k);
		print(ans), puts("");
	}
	return 0;
}
