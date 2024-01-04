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

const int MAXN = 5e3 + 5;
int T, n, m, k;
int f[MAXN][MAXN];

int qpow(int a, int b, int p) {
	int res = 1;
	for (a %= p; b; b >>= 1, a = a * a % p)
		if (b & 1) res = res * a % p;
	return res;
}

const int MOD = 998244353;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("gull.in", "r", stdin);
	freopen("gull.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) {
		n = read(), m = read(), k = read();
		if (k == 0) {
			puts("1");
			continue;
		}
		memset(f, 0, sizeof f);
		f[0][0] = 1;
		rep (i, 1, n) {
			rep (j, 1, min(i, m)) {
				rep (k, 1, i) {
					f[i][j] += f[k - 1][j - 1];
					f[i][j] %= MOD;
				}
			}
		}
		int sum = 0, ans = 0;
		rep (i, 1, n) sum += f[i][m], sum %= MOD;
		rep (i, 1, n) ans = (ans + qpow(i, k, MOD) * f[i][m] % MOD) % MOD;
		print(ans * qpow(sum, MOD - 2, MOD) % MOD); putchar(10);
	}
	return 0;
}
