#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define int ll

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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 505;
const int MOD = 1e9 + 7;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int f[MAXN][MAXN], ans[MAXN];

void Gauss(int n) {
	int cnt = 1;
	rep (i, 1, n) {
		int r = cnt;
		rep (j, r, n) {
			if (abs(f[r][i]) < abs(f[j][i])) r = j;
		}
		if (f[r][i] == 0) continue;
		rep (j, i, n + 1) swap(f[r][j], f[cnt][j]);
		_rep (j, n + 1, i) f[cnt][j] = f[cnt][j] * qpow(f[cnt][i], MOD - 2) % MOD;
		rep (j, cnt + 1, n) {
			if (f[j][i] != 0) {
				_rep (k, n + 1, i) {
					f[j][k] = (f[j][k] - f[cnt][k] * f[j][i] % MOD + MOD) % MOD;
				}
			}
		}
		++cnt;
	}
	_rep (i, n, 1) {
		rep (j, i + 1, n) f[i][n + 1] = (f[i][n + 1] - f[i][j] * f[j][n + 1] % MOD + MOD) % MOD;
	}
	rep (i, 1, n) ans[i] = f[i][n + 1];
}

int n, m, q;
int l[MAXN][MAXN], r[MAXN][MAXN], u[MAXN][MAXN], d[MAXN][MAXN];

#define Genshin_Launch continue
#define id(x, y) (((x) - 1) * m + (y))

signed main() {
#ifndef LOCAL
	ignore = freopen("nyagain.in", "r", stdin);
	ignore = freopen("nyagain.out", "w", stdout);
#endif
	n = read(), m = read();
	rep (i, 1, n) rep (j, 1, m) l[i][j] = read();
	rep (i, 1, n) rep (j, 1, m) r[i][j] = read();
	rep (i, 1, n) rep (j, 1, m) u[i][j] = read();
	rep (i, 1, n) rep (j, 1, m) d[i][j] = read();
	q = read();
	if (q == 0) return 0;
	const int N = n * m;
	const int inv = qpow(100, MOD - 2);
	while (q --> 0) {
		memset(f, 0, sizeof f);
		int op = read();
		if (op == 1) {
			Genshin_Launch;
		}
		int sx = read(), sy = read(), tx = read(), ty = read();
		sx++, sy++, tx++, ty++;
		rep (i, 1, n) {
			rep (j, 1, m) {
				const int D = id(i, j);
				if (i == sx && j == sy) {
					f[D][N + 1] = MOD - 1;
				}
				f[D][D] = MOD - 1;
				const int nu = (i - 1 == 0) ? n : i - 1;
				const int nd = (i + 1 == n + 1) ? 1 : i + 1;
				const int nl = (j - 1 == 0) ? m : j - 1;
				const int nr = (j + 1 == m + 1) ? 1: j + 1;
				f[D][id(nu, j)] = d[nu][j] * inv % MOD;
				f[D][id(nd, j)] = u[nd][j] * inv % MOD;
				f[D][id(i, nl)] = r[i][nl] * inv % MOD;
				f[D][id(i, nr)] = l[i][nr] * inv % MOD;
			}
		}
		Gauss(N);
		int sum = 0;
		rep (i, 1, N) sum = (sum + ans[i]) % MOD;
		print(sum), puts("");
	}
	return 0;
}
