#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
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

int n, k, c;
int f[200][200];
int ch[200], ach[200], ans = 1e9;

void dfs(int step) {
	if (step > n) {
		int tans = 0;
		rep (i, 1, n) {
			rep (j, 1, n) {
				if (i == j) continue;
				tans = max(tans, f[i][ch[i]] + f[j][ch[j]] + c * (abs(ch[i] - ch[j])));
			}
		}
		if (tans < ans) {
			ans = tans;
			rep (i, 1, step) ach[i] = ch[i];
		}
		return;
	}
	rep (i, 1, k) ch[step] = i, dfs(step + 1);
	// 总裁，我笑了
}

signed main() {
#ifndef LOCAL
	ignore = freopen("zone.in", "r", stdin);
	ignore = freopen("zone.out", "w", stdout);
#endif
	n = read(), k = read(), c = read();
	rep (i, 1, n) {
		rep (j, 1, k) f[i][j] = read();
	}
	dfs(1);
	cout << ans << endl;
	rep (i, 1, n) cout << ach[i] << " ";
	cout << endl;
	return 0;
}
