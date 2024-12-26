#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define y1 __arknights

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

const int MOD = 1e9 + 7;
const int MAXN = 1e3 + 5;
int n, m;
int x1[MAXN], x2[MAXN], y1[MAXN], y2[MAXN];
int ch[15], ans;
int dp[MAXN][MAXN], mp[MAXN][MAXN];

/*

int get(pii a1, pii b1, pii a2, pii b2) {
	if (a1.ec > b2.ec || a2.ec > b1.ec) return 0;
	if (a1.fb > b2.fb || a2.fb > b1.fb) return 0;
	pii a = dl(max(a1.ec, a2.ec), max(a1.fb, a2.fb));
	pii b = dl(min(b1.ec, b2.ec), min(b1.fb, b2.fb));
	return (b.ec - a.ec) * (b.fb - a.fb);
}

void dfs(int step) {
	if (step > m) {
		rep (i, 1, m) {
			if (ch[i] == 0 && y1[i] == 0) return;
			if (ch[i] == 1 && y2[i] == n) return;
			if (ch[i] == 0 && x2[i] == n) return;
			if (ch[i] == 1 && x1[i] == 0) return;
		}
		rep (i, 1, m) {
			rep (j, 1, m) {
				if (ch[i] == ch[j]) continue;
				if (get(dl(x1[i], y1[i]), dl(x2[i] + 1, y2[i] + 1),
						dl(x1[j], y1[j]), dl(x2[j] + 1, y2[j] + 1)) != 0) return;
				if (ch[i] == 0 && ch[j] == 1) {
					if (y1[j] - y2[i] <= 1) return;
				}
			}
		}
		return;
	}
	ch[step] = 1;
	dfs(step + 1);
	ch[step] = 0;
	dfs(step + 1);
}
*/

inline int Mod(int x) {
	if (x >= MOD) return x - MOD;
	if (x < 0) return x + MOD;
	return x;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("douglas.in", "r", stdin);
	freopen("douglas.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, m) {
		x1[i] = read(), y1[i] = read();
		x2[i] = read(), y2[i] = read();
		rep (j, x1[i], y1[i]) {
			rep (k, x2[i], y2[i]) {
				mp[j][k] = 1;
			}
		}
	}
	rep (i, 1, n) mp[0][i] = mp[i][0] = mp[i][n + 1] = mp[n + 1][i] = 1;
	/*
	dfs(1);
	print(ans), puts("");
	*/
	dp[1][1] = 1;
	rep (i, 1, n) {
		rep (j, 1, n) {
			if (mp[i][j]) continue;
			if (mp[i + 1][j + 1] == 1) {
				dp[i][j + 1] = Mod(dp[i][j + 1] + dp[i][j]);
				dp[i + 1][j] = Mod(dp[i + 1][j] + dp[i][j]);
			}
			else if (mp[i][j + 1] == 1) {
				dp[i + 1][j] = Mod(dp[i + 1][j] + dp[i][j]);
			}
			else dp[i][j + 1] = Mod(dp[i][j + 1] + dp[i][j]);
		}
	}
	print(dp[n][n]), puts("");
	return 0;
}

/*
	dp[1][1] = 1;
	rep (i, 1, n) {
		rep (j, 1, n) {
			if (mp[i][j]) continue;
			if (mp[i + 1][j + 1] == 1) {
				dp[i][j + 1] = Mod(dp[i][j + 1] + dp[i][j]);
				dp[i + 1][j] = Mod(dp[i + 1][j] + dp[i][j]);
			}
			else if (mp[i][j + 1] == 1) {
				dp[i + 1][j] = Mod(dp[i + 1][j] + dp[i][j]);
			}
			else dp[i][j + 1] = Mod(dp[i][j + 1] + dp[i][j]);
		}
	}
	print(dp[n][n]), puts("");
*/
