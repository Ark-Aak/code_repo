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

const int MOD = 998244353;
int n, m;
int mp[1505][1505];
int fac[1505], ifac[1505];
map <int, int> cnt;
vector <int> c;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % MOD;
		a = 1ll * a * a % MOD;
		b >>= 1;
	}
	return res;
}

void init(int n) {
	fac[0] = 1;
	rep (i, 1, n) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[n] = qpow(fac[n], MOD - 2);
	_rep (i, n - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % MOD;
}

int C(int n, int m) {
	if (n < m) return 0;
	return 1ll * fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

int ch[10][10];

bool check1() {
	int p[10][10];
	rep (i, 1, n) rep (j, 1, m) p[i][j] = ch[i][j];
	rep (i, 1, n) {
		vector <int> s;
		rep (j, 1, m) s.push_back(p[i][j]);
		sort(s.begin(), s.end());
		rep (j, 1, m) p[i][j] = s[j - 1];
	}
	rep (i, 1, m) {
		vector <int> s;
		rep (j, 1, n) s.push_back(p[j][i]);
		sort(s.begin(), s.end());
		rep (j, 1, n) p[j][i] = s[j - 1];
	}
	rep (i, 1, n) rep (j, 1, m) if (p[i][j] != mp[i][j]) return 0;
	return 1;
}

bool check2() {
	int p[10][10];
	rep (i, 1, n) rep (j, 1, m) p[i][j] = ch[i][j];
	rep (i, 1, m) {
		vector <int> s;
		rep (j, 1, n) s.push_back(p[j][i]);
		sort(s.begin(), s.end());
		rep (j, 1, n) p[j][i] = s[j - 1];
	}
	rep (i, 1, n) {
		vector <int> s;
		rep (j, 1, m) s.push_back(p[i][j]);
		sort(s.begin(), s.end());
		rep (j, 1, m) p[i][j] = s[j - 1];
	}
	rep (i, 1, n) rep (j, 1, m) if (p[i][j] != mp[i][j]) return 0;
	return 1;
}

int ans = 0;

void dfs(int step, int x, int y) {
	if (step > n * m) {
		if (check1() && check2()) ans = (ans + 1) % MOD;
		return;
	}
	ch[x][y] = 1;
	dfs(step + 1, x + (y == m), y % m + 1);
	ch[x][y] = 0;
	dfs(step + 1, x + (y == m), y % m + 1);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, n) rep (j, 1, m) mp[i][j] = read();
	if (n == 1 && m == 1) return puts("1"), 0;
	init(1500);
	if (n == 1 || m == 1) {
		if (n == 1) rep (i, 1, m) cnt[mp[1][i]]++;
		if (m == 1) rep (i, 1, n) cnt[mp[i][1]]++;
		for (auto [u, v] : cnt) c.push_back(v);
		sort(c.begin(), c.end(), greater <int>());
		int ans = 1, sum = c[0];
		c.erase(c.begin());
		for (auto v : c) ans = (1ll * ans * C(sum + v, v)) % MOD, sum = (sum + v) % MOD;
		print(ans), puts("");
		return 0;
	}
	if (n == 2 && m == 2) {
		int ans = 0;
		rep (i, 0, 9) {
			rep (j, 0, 9) {
				rep (k, 0, 9) {
					rep (l, 0, 9) {
						int a00 = i;
						int a01 = j;
						int a10 = k;
						int a11 = l;
						int aa00, aa01, aa10, aa11;
						aa00 = a00;
						aa01 = a01;
						aa10 = a10;
						aa11 = a11;
						if (aa00 > aa10) swap(aa00, aa10);
						if (aa01 > aa11) swap(aa01, aa11);
						if (aa00 > aa01) swap(aa00, aa01);
						if (aa10 > aa11) swap(aa10, aa11);
						if (aa00 != mp[1][1]) continue;
						if (aa01 != mp[1][2]) continue;
						if (aa10 != mp[2][1]) continue;
						if (aa11 != mp[2][2]) continue;
						aa00 = a00;
						aa01 = a01;
						aa10 = a10;
						aa11 = a11;
						if (aa00 > aa01) swap(aa00, aa01);
						if (aa10 > aa11) swap(aa10, aa11);
						if (aa00 > aa10) swap(aa00, aa10);
						if (aa01 > aa11) swap(aa01, aa11);
						if (aa00 != mp[1][1]) continue;
						if (aa01 != mp[1][2]) continue;
						if (aa10 != mp[2][1]) continue;
						if (aa11 != mp[2][2]) continue;
						ans = (ans + 1) % MOD;
					}
				}
			}
		}
		print(ans), puts("");
		return 0;
	}
	if (n <= 4 && m <= 4) {
		dfs(1, 1, 1);
		print(ans), puts("");
		return 0;
	}
	return 0;
}
