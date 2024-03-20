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

#define int __int128
const int MOD = 998244353;
int l[8], r[8], ans = 1;
const int n = 7;

int w[8];
int aL = 0, aR = 1e30;
int bL = 0, bR = 1e30;
int cL = 0, cR = 1e30;

int dp[400][2][2][2][2][2];

class binary {
	int len;
	bitset <1024> val;

public:
	binary() {
		len = 0;
		val.reset();
	}

	binary(int x) {
		len = 0;
		val.reset();
		while (x) {
			val[++len] = x & 1;
			x >>= 1;
		}
	}

	bool operator [] (int x) {
		return val[x];
	}
} aLb, aRb, bLb, bRb;

int solve(int x) {
	if (aL > aR) return 0;
	if (bL > bR) return 0;
	if (cL > cR) return 0;
	memset(dp, 0, sizeof dp);
	if (x < 0) return 0;
	binary c(x);
	dp[129][1][1][1][1][1] = 1;
	_rep (i, 128, 1) {
		rep (l1, 0, 1) {
			rep (r1, 0, 1) {
				rep (l2, 0, 1) {
					rep (r2, 0, 1) {
						rep (r3, 0, 1) {
							rep (u, 0, 1) {
								rep (d, 0, 1) {
									int now = u ^ d;
									if (l1 && u < aLb[i]) continue;
									if (l2 && d < bLb[i]) continue;
									if (r1 && u > aRb[i]) continue;
									if (r2 && d > bRb[i]) continue;
									if (r3 && now > c[i]) continue;
									bool nL1 = (l1 && (u == aLb[i]));
									bool nR1 = (r1 && (u == aRb[i]));
									bool nL2 = (l2 && (d == bLb[i]));
									bool nR2 = (r2 && (d == bRb[i]));
									bool nR3 = (r3 && (now == c[i]));
									dp[i][nL1][nR1][nL2][nR2][nR3] += dp[i + 1][l1][r1][l2][r2][r3];
									dp[i][nL1][nR1][nL2][nR2][nR3] %= MOD;
								}
							}
						}
					}
				}
			}
		}
	}
	int ans = 0;
	rep (i, 0, 1) {
		rep (j, 0, 1) {
			rep (k, 0, 1) {
				rep (l, 0, 1) {
					rep (m, 0, 1) {
						ans += dp[1][i][j][k][l][m];
						ans %= MOD;
					}
				}
			}
		}
	}
	return ans;
}

signed main() {
	//freopen("qgygd.in", "r", stdin);
	//freopen("qgygd.out", "w", stdout);
	rep (i, 1, n) read(l[i]), read(r[i]);
	rep (i, 1, 3) aL = max(aL, l[i]), aR = min(aR, r[i]);
	rep (i, 5, 7) bL = max(bL, l[i]), bR = min(bR, r[i]);
	cL = l[4], cR = r[4];
	rep (i, 1, n) ans = ans * (r[i] - l[i] + 1) % MOD;
	aLb = binary(aL), aRb = binary(aR), bLb = binary(bL), bRb = binary(bR);
	ans -= solve(cR) - solve(cL - 1);
	print((ans + 998 * MOD) % MOD);
	return 0;
}
