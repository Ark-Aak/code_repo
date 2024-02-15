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

const int MAXN = 1005;
const int MOD = 2500000001;
int T, n, m, k, a[MAXN], b[MAXN];
int fac[1000005], f[25][25];
unordered_map <int, int> mp[50005];
int cnt[1000005];

int qpow(int a, int b = MOD - 2) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("snowball.in", "r", stdin);
	freopen("snowball.out", "w", stdout);
#endif
#endif
	fac[1] = 1;
	rep (i, 2, 1000000) fac[i] = fac[i - 1] * i % MOD;
	T = read();
	while (T --> 0) {
		n = read(), m = read(), k = read();
		rep (i, 1, k) a[i] = read(), b[i] = read();
		if (1) {
			memset(f, 0x3f, sizeof f);
			rep (i, 1, k) {
				rep (j, 1, n) {
					rep (l, 1, m) {
						f[j][l] = min(f[j][l], abs(a[i] - j) + abs(b[i] - l));
					}
				}
			}
			vector <pair <int, int> > p;
			rep (i, 1, n) rep (j, 1, m) p.push_back({i, j});
			int order[30], ans = 0;
			rep (i, 1, n * m) order[i] = i - 1;
			do {
				bool flg = 0;
				rep (i, 0, n * m - 1) {
					int x = p[order[i + 1]].first, y = p[order[i + 1]].second;
					if (f[x][y] > i) {
						flg = 1;
						break;
					}
				}
				if (!flg) ans++;
			} while(next_permutation(order + 1, order + 1 + n * m));
			print(ans * qpow(fac[n * m]) % MOD), putchar(10);
		}
	}
	return 0;
}
