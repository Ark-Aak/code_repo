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

const int MAXN = 305;
int n, m, p;
int mp[MAXN][MAXN];

vector <pii> pos[MAXN * MAXN];

namespace subtask1 {

	int dp[2][MAXN][MAXN];

	void solve() {
		memset(dp, 0x3f, sizeof dp);
		dp[0][1][1] = 0;
		rep (i, 1, p) {
			for (auto [x1, y1] : pos[i]) {
				for (auto [x2, y2] : pos[i - 1]) {
					dp[1][x1][y1] = min(
							dp[1][x1][y1],
							dp[0][x2][y2] + abs(x1 - x2) + abs(y1 - y2)
						);
				}
			}
			for (auto [x, y] : pos[i - 1]) dp[0][x][y] = 0x3f3f3f3f;
			for (auto [x, y] : pos[i]) swap(dp[0][x][y], dp[1][x][y]);
		}
		int ans = 1e9;
		for (auto [x, y] : pos[p]) ans = min(ans, dp[0][x][y]);
		print(ans), puts("");
	}

} // namespace subtask1

namespace subtask2 {

	int dp[MAXN][MAXN];
	int nxt[MAXN][MAXN];

	void calc() {
		rep (i, 1, n) rep (j, 1, m) dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i][j]);
		rep (i, 1, n) _rep (j, m, 1) dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j + 1] + 1), dp[i][j]);
		_rep (i, n, 1) rep (j, 1, m) dp[i][j] = min(min(dp[i + 1][j] + 1, dp[i][j - 1] + 1), dp[i][j]);
		_rep (i, n, 1) _rep (j, m, 1) dp[i][j] = min(min(dp[i + 1][j] + 1, dp[i][j + 1] + 1), dp[i][j]);
	}

	void solve() {
		memset(dp, 0x3f, sizeof dp);
		dp[1][1] = 0;
		rep (i, 1, p) {
			memset(nxt, 0x3f, sizeof nxt);
			calc();
			for (auto [x, y] : pos[i]) nxt[x][y] = dp[x][y];
			memcpy(dp, nxt, sizeof nxt);
		}
		int ans = 1e9;
		for (auto [x, y] : pos[p]) ans = min(ans, dp[x][y]);
		print(ans), puts("");
	}

} // namespace subtask2

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("barry.in", "r", stdin);
	freopen("barry.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), p = read();
	rep (i, 1, n) rep (j, 1, m) {
		mp[i][j] = read();
		pos[mp[i][j]].emplace_back(i, j);
	}
	pos[0].emplace_back(1, 1);
	if (p > sqrt(n * m)) subtask1::solve();
	else subtask2::solve();
	return 0;
}
