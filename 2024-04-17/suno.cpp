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

const int MOD = 998244353;
int n;
int ch[50][50], mx, ans;

void dfs(int x, int y) {
	if (x == n && y == n) {
		if (ch[x][y - 1] > ch[x][y] || ch[x - 1][y] > ch[x][y]) return;
		ans++;
		if (ans >= MOD) ans -= MOD;
		return;
	}
	if (x == y) {
		if (ch[x][y - 1] > ch[x][y] || ch[x - 1][y] > ch[x][y]) return;
		dfs(x, y + 1);
		return;
	}
	rep (i, max(ch[x][y - 1], ch[x - 1][y]), mx) {
		ch[x][y] = i;
		dfs(x + (y == n), y % n + 1);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("suno.in", "r", stdin);
	freopen("suno.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) ch[i][i] = read(), mx = max(mx, ch[i][i]);
	dfs(1, 1);
	print(ans);
	return 0;
}
