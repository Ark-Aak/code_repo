#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

const int MAXN = 500 + 5;
const int MOD = 998244353;
int T, n, op, k, xorAns;
int mat[MAXN][MAXN];

int qpow(int a, int b) {
	int ans = 1;
	for (; b; b >>= 1, a = a * a % MOD) if (b & 1) ans = ans * a % MOD;
	return ans;
}

const function <int (int)> calc = [](int n) {
	return ((3 + 2 * n % MOD - 3 * qpow(n, 2) % MOD + 4 * qpow(n, 3) % MOD - 3 * ((n - 1) & 1)) % MOD + MOD) % MOD
			* qpow(6, MOD - 2) % MOD;
};

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("again.in", "r", stdin);
	freopen("again.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) {
		n = read(), op = read(), k = read();
		if (n <= 500) {
			memset(mat, 0, sizeof mat);
			int x = 1, y = 1, d = 0;
			rep(i, 1, n * n) {
				mat[x][y] = i;
				if (d == 0) {
					if (x == n || mat[x + 1][y]) d = 1, y++;
					else x++;
				}
				else if (d == 1) {
					if (y == n || mat[x][y + 1]) d = 2, x--;
					else y++;
				}
				else if (d == 2) {
					if (x == 1 || mat[x - 1][y]) d = 3, y--;
					else x--;
				}
				else {
					if (y == 1 || mat[x][y - 1]) d = 0, x++;
					else y--;
				}
			}
			int ans = 0;
			if (op == 1) {
				rep (i, k, n) {
					ans += mat[i][i - k + 1], ans %= MOD;
				}
			}
			else {
				rep (i, k, n) {
					ans += mat[i - k + 1][i], ans %= MOD;
				}
			}
			xorAns ^= ans;
		}
		else if (k == 1) {
			xorAns ^= calc(n);
		}
	}
	print(xorAns);
	return 0;
}
