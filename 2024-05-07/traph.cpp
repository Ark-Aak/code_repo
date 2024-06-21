#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef __int128 i128;
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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = 8e4 + 5;
int n, cnt;
int id[MAXN], ans[MAXN];
vector <int> G[MAXN];

struct point {
	int x, y, id;
};

void dfs(int u, int fa) {
	id[u] = cnt++;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(v, u);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("traph.in", "r", stdin);
	freopen("traph.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n - 1) {
		int x = read(), y = read();
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int root = 0;
	rep (i, 1, n) if (G[i].size() == 1) root = i;
	vector <point> v;
	rep (i, 1, n) {
		int x = read(), y = read();
		v.push_back({ x, y, i });
	}
	sort(v.begin(), v.end(), [](point a, point b) { return a.x < b.x; });
	int sy = v[0].y, lx = v[0].x;
	vector <point> v1, v2;
	for (auto pt : v) {
		if (pt.y >= sy && pt.x >= lx) v1.push_back(pt), lx = pt.x;
		else v2.push_back(pt);
	}
	v.clear();
	sort(v1.begin(), v1.end(), [](point a, point b) { return a.x < b.x; });
	sort(v2.begin(), v2.end(), [](point a, point b) { return a.x > b.x; });
	for (auto pt : v1) v.push_back(pt);
	for (auto pt : v2) v.push_back(pt);
	dfs(root, 0);
	rep (i, 1, n) ans[v[id[i]].id] = i;
	rep (i, 1, n) print(ans[i]), putchar(32);
	puts("");
	return 0;
}
