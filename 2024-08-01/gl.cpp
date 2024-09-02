#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define ec first
#define fb second
#define de(x) cerr << #x << " = " << (x) << endl

#define int ll

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair <int, int> pii;

int read() {
	int x = 0, w = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + (ch ^ 48);
		ch = getchar();
	}
	return x * w;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

const int MAXN = 4005;
const int MOD = 1e9 + 7;
int n, m;
string str;
int dp[MAXN][MAXN], ans[MAXN][MAXN];
int fac[MAXN], inv[MAXN];
// dp_{i, j} 表示a[i]=j的sum

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

void init(int n) {
	fac[0] = fac[1] = 1;
	rep (i, 2, n) fac[i] = fac[i - 1] * i % MOD;
	inv[n] = qpow(fac[n], MOD - 2), inv[0] = 1;
	_rep (i, n - 1, 1) inv[i] = inv[i + 1] * (i + 1) % MOD;
}

int C(int m, int n) {
	if (n > m) return 0;
	return fac[m] * inv[m - n] % MOD * inv[n] % MOD;
}

int A(int m, int n) {
	if (n > m) return 0;
	return fac[m] * inv[m - n] % MOD;
}

signed main() {
#ifndef LOCAL
	freopen("gl.in", "r", stdin);
	freopen("gl.out", "w", stdout);
#endif
	init(3000);
	cin >> n >> m;
	cin >> str;
	str = ' ' + str;
	rep (i, 1, m) dp[1][i] = 1, ans[1][i] = i;
	rep (i, 2, n) {
		rep (j, 0, m + 1) {
			rep (k, 1, m) {
				int nxt = str[i - 1] == 'C' ? C(k, j) : A(k, j);
				int rn = nxt;
				nxt = min(nxt, m + 1);
				dp[i][nxt] = (dp[i][nxt] + dp[i - 1][j]) % MOD;
				ans[i][nxt] = (ans[i][nxt] + dp[i - 1][j] * rn % MOD) % MOD;
			}
		}
	}
	int sum = 0;
	rep (j, 0, m + 1) sum = (sum + ans[n][j]) % MOD;
	print(sum), puts("");
	return 0;
}
