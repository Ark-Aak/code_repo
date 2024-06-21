#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define int ll

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

const int MOD = 1e9 + 7;

struct Mat {
	int mat[50][50], n;

	Mat(int n) {
		rep (i, 1, n) rep (j, 1, n) mat[i][j] = 0;
		rep (i, 1, n) mat[i][i] = 1;
		this -> n = n;
	}

	Mat operator * (Mat &t) const  {
		Mat res(n);
		rep (i, 1, n) {
			rep (j, 1, n) {
				rep (k, 1, n) {
					res.mat[i][j] = (res.mat[i][j] + mat[i][k] * t.mat[k][j] % MOD) % MOD;
				}
			}
		}
		return res;
	}
};

int n, t, k;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

Mat qpow(Mat a, int b) {
	Mat res(42);
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

const int MAXN = 1e3 + 5;
map <vector <int>, int> mp[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
#endif
#endif
	n = read(), t = read(), k = read();
	const int inv = qpow(n * n, MOD - 2);
	if (n == k) return print(qpow(qpow(n, MOD - 2), t)), puts(""), 0;
	vector <int> v;
	rep (i, 1, n) v.push_back(1);
	mp[0][v] = 1;
	rep (i, 1, t) {
		for (auto [vec, p] : mp[i - 1]) {
			vector <int> nv;
			int cnt = 0;
			for (auto v : vec) {
				rep (j, 1, v) nv.push_back(cnt);
				cnt++;
			}
			rep (j, 0, nv.size() - 1) {
				rep (k, 0, nv.size() - 1) {
					vector <int> nt = nv;
					nt[j] = nt[k];
					vector <int> nb(n);
					for (auto v : nt) nb[v]++;
					sort(nb.begin(), nb.end());
					while (nb.size() && (*nb.begin() == 0)) {
						nb.erase(nb.begin());
					}
					mp[i][nb] += mp[i - 1][vec] * inv % MOD;
					mp[i][nb] %= MOD;
				}
			}
		}
	}
	int ans = 0;
	for (auto [vec, p] : mp[t]) {
		if ((int) vec.size() >= k) {
			ans = (ans + p) % MOD;
		}
	}
	print(ans), puts("");
	/* cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl; */
	return 0;
}
