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

const int MAXN = 1e6 + 5;
int n, k, dep[MAXN], f[MAXN], ans;
vector <int> G[MAXN];

void dfs(int u, int fa) {
	int mx = 0;
	for (auto v : G[u]) {
		if (v ^ fa) {
			dfs(v, u);
			mx = max(mx, f[v]);
			f[u] = mx + 1;
		}
	}
	if (f[u] == k - 1 && fa != 1) ans++, f[u] = 0;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("lost.in", "r", stdin);
	freopen("lost.out", "w", stdout);
#endif
#endif
	n = read(), k = read();
	bool flg = 0;
	rep (i, 1, n) {
		int d = read();
		if (i == 1) {
			flg = d != 1;
			continue;
		}
		G[d].push_back(i);
		G[i].push_back(d);
	}
	dfs(1, 0);
	print(ans + flg);
	puts("");
	return 0;
}
