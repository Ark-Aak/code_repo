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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 2e5 + 5;
unsigned long long ans = 0;
vector <int> G[MAXN];
int mxa = 0, mxb = 0, n, m;

void dfs(int dep, int u, int fa) {
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(dep + 1, v, u);
	}
	if (G[u].size() ^ 1) return;
	if (dep >= mxa) mxb = mxa, mxa = dep;
	else if (dep >= mxb) mxb = dep;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 2, n) {
		int fa = read();
		G[fa].push_back(i);
		G[i].push_back(fa);
	}
	dfs(1, 1, 0);
	ans += mxa + mxb - 1;
	rep (i, 1, m - 1) ans += 2ull * mxa;
	print(ans);
	return 0;
}
