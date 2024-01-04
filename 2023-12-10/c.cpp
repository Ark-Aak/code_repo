#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

const int MOD = 1e9 + 7;
int n, m, x, y;
int f[80][(1 << 6) + 10];
int cnt[(1 << 6) + 10], stat[405][405];

int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

#define s(x) (1 << (x))

int solve(int n, int m) {
	memset(cnt, 0, sizeof cnt);
	memset(f, 0, sizeof f);
	memset(stat, 0, sizeof stat);
	rep (i, 1, n) stat[i][1] |= s(2);
	rep (i, 1, n) stat[i][m] |= s(3);
	rep (i, 1, m) stat[1][i] |= s(0);
	rep (i, 1, m) stat[n][i] |= s(1);
	rep (i, 1, n) {
		rep (j, 1, m) {
			if (!((i <= x && j <= y) ||
				 (i >= n - x + 1 && j >= m - y + 1)
			)) stat[i][j] |= s(4);
			if (!((i <= x && j >= m - y + 1) ||
				 (i >= n - x + 1 && j <= y)
			)) stat[i][j] |= s(5);
		}
	}
	rep (i, 1, n) rep (j, 1, m) cnt[stat[i][j]]++;
	f[0][0] = 1;
	rep (i, 0, 63) {
		rep (j, 0, 63) {
			f[i + 1][i | j] = (f[i + 1][i | j] +
							  (qpow(2, cnt[i], MOD) - 1) * f[i][j] % MOD) % MOD;
			f[i + 1][j] = (f[i + 1][j] + f[i][j]) % MOD;
		}
	}
	return (f[s(6)][s(5) - 1] + f[s(6)][s(4) - 1] + f[s(6)][s(6) - 1 - s(4)]) % MOD;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
#endif
#endif
	read(n), read(m), read(x), read(y);
	int ans = 1;
	rep (i, 1, n) {
		rep (j, 1, m) {
			ans = (ans + solve(i, j) * (n - i + 1) % MOD * (m - j + 1) % MOD) % MOD;
		}
	}
	print(ans);
	return 0;
}
