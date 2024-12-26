#include <bits/stdc++.h>

#define int ll
// #define double long double

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

const int MAXN = 1e5 + 5;
int n, q;
int p[MAXN], t[MAXN], x[MAXN];
double dp[MAXN][51][33];

i128 qpow(i128 a, i128 b) {
	i128 res = 1;
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

double mkspd(int i, int j) {
	i128 res = qpow(2, i) * qpow(3, j);
	if (res > 1e15) return -1;
	return res;
}

signed main() {
	n = read(), q = read();
	rep (i, 1, n) p[i] = read(), t[i] = read(), x[i] = read();
	rep (i, 0, n) rep (j, 0, 50) rep (k, 0, 32) dp[i][j][k] = 1e18;
	dp[0][0][0] = 0;
	rep (i, 1, n) {
		double dis = p[i] - p[i - 1];
		rep (j, 0, 50) {
			rep (k, 0, 32) {
				double spd = mkspd(i, j);
				if (spd == -1) continue;
				double tim = dis / spd;
				dp[i][j][k] = dp[i - 1][j][k] + tim;
				if (x[i - 1] == 2 && j >= 1) {
					dp[i][j][k] = fmin(dp[i][j][k], dp[i - 1][j - 1][k] + tim + t[i - 1]);
				}
				if (x[i - 1] == 3 && k >= 1) {
					dp[i][j][k] = fmin(dp[i][j][k], dp[i - 1][j][k - 1] + tim + t[i - 1]);
				}
				if (x[i - 1] == 4 && j >= 2) {
					dp[i][j][k] = fmin(dp[i][j][k], dp[i - 1][j - 2][k] + tim + t[i - 1]);
				}
			}
		}
	}
	// rep (i, 0, n) rep (j, 0, 50) rep (k, 0, 32) assert(dp[i][j][k] > 0);
	rep (i, 1, q) {
		int pos = read();
		if (pos <= p[1]) {
			printf("%.10lf\n", (double) pos);
			continue;
		}
		int rx = *(upper_bound(p + 1, p + 1 + n, pos) - 1);
		double ans = 1e9;
		double dis = pos - p[rx];
		rep (j, 0, 50) {
			rep (k, 0, 32) {
				double spd = mkspd(i, j);
				if (spd == -1) continue;
				if (ans > dp[rx][j][k] + dis / spd) {
					cout << dp[rx][j][k] << " " << dis / spd << " " << rx << " " << j << " " << k << endl;
				}
				ans = fmin(ans, dp[rx][j][k] + dis / spd);
			}
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}
