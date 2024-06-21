#include <bits/stdc++.h>

#define int __int128

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

const int MAXN = 2e3 + 5;
int n, k, P;
int C[MAXN][MAXN], dp[MAXN][15][3], sum[MAXN][15][3];

void init() {
	rep (i, 0, n) {
		C[i][0] = 1;
		rep (j, 1, i) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("misty.in", "r", stdin);
	freopen("misty.out", "w", stdout);
#endif
#endif
	n = read(), k = read(), P = read();
	if (k > 10) {
		puts("0");
        return 0;
    }
	int K = k;
	k = 11;
	init();
	dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = 1;
	rep (p, 1, n) {
		rep (i, 0, k + 1) {
			sum[p - 1][i][0] = ((i == 0 ? 0 : sum[p - 1][i - 1][0]) + dp[p - 1][i][0]) % P;
			sum[p - 1][i][1] = ((i == 0 ? 0 : sum[p - 1][i - 1][1]) + dp[p - 1][i][1]) % P;
			sum[p - 1][i][2] = ((i == 0 ? 0 : sum[p - 1][i - 1][2]) + dp[p - 1][i][2]) % P;
		}
		rep (i, 0, p - 1) {
			int j = p - i - 1;
			int c = C[i + j][j];
			/* cout << c << endl; */
			rep (x, 1, k + 1) {
				int val = (dp[i][x - 1][1] * sum[j][x - 1][1]) % P + ((x == 1) ? 0 : sum[i][x - 2][1]) * dp[j][x - 1][1] % P;
				dp[p][x][0] = (dp[p][x][0] + val * c % P) % P;
				val = ((dp[i][x - 1][2] * sum[j][x][1]) % P + (((x == 1) ? 0 : sum[i][x - 2][2]) * dp[j][x][1]) % P) % P;
				dp[p][x][1] = (dp[p][x][1] + val * c % P) % P;
				val = ((dp[i][x][2] * sum[j][x - 1][2]) % P + (sum[i][x - 1][2] * dp[j][x][2]) % P) % P;
				val = (val + (dp[i][x - 1][2] * dp[j][x - 1][2]) % P) % P;
				dp[p][x][2] = (dp[p][x][2] + (val * c) % P) % P;
            }
		}
	}
	int ans = 0;
	rep (i, K + 1, 11) {
		ans = (ans + dp[n][i][0]) % P;
	}
	print(ans);
	return 0;
}
