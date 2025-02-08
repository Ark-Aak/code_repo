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
#define de(val) cerr << #val << " = " << (val) << endl

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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 1e6 + 5;
int n, s, T;
int t[MAXN][2];
int sum[MAXN][2];
int lst[MAXN];

vector <int> G[MAXN];
int col[MAXN];

void dfs(int u, int c) {
	col[u] = c;
	for (auto v : G[u]) {
		if (!col[v]) dfs(v, 3 - c);
		else assert(col[u] != col[v]);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
#endif
#endif
	n = read(), s = read(), T = read();
	rep (i, 1, n) t[i][0] = read(), t[i][1] = read();
	rep (i, 1, n) {
		int l = t[i][0], r = t[i][1];
		G[i * 2 - 1].push_back(i * 2);
		G[i * 2].push_back(i * 2 - 1);
		if (l == r) continue;
		if (lst[l]) {
			G[i * 2 - 1].push_back(lst[l]);
			G[lst[l]].push_back(i * 2 - 1);
		}
		if (lst[r]) {
			G[i * 2].push_back(lst[r]);
			G[lst[r]].push_back(i * 2);
		}
		lst[l] = i * 2 - 1;
		lst[r] = i * 2;
	}
	rep (i, 1, n << 1) {
		if (!col[i]) dfs(i, 1);
	}
	rep (i, 1, n) {
		print(t[i][col[i * 2 - 1] - 1]), putchar(32), print(t[i][col[i * 2] - 1]), puts("");
	}
	return 0;
}
