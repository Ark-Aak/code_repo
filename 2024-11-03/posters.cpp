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
#define de(val) cerr << #val << " = " << (val) << endl

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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

int n, m, k;
int w[10], h[10];

int get(pii a1, pii b1, pii a2, pii b2) {
	if (a1.ec > b2.ec || a2.ec > b1.ec) return 0;
	if (a1.fb > b2.fb || a2.fb > b1.fb) return 0;
	pii a = dl(max(a1.ec, a2.ec), max(a1.fb, a2.fb));
	pii b = dl(min(b1.ec, b2.ec), min(b1.fb, b2.fb));
	return (b.ec - a.ec) * (b.fb - a.fb);
	return 0;
}

int ord[10];
int mp[105][105];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("posters.in", "r", stdin);
	freopen("posters.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), k = read();
	rep (i, 1, k) w[i] = read();
	rep (i, 1, k) h[i] = read();
	if (k == 1) {
		print(w[1] * h[1]), puts("");
		return 0;
	}
	int ans = 0;
	if (k == 2) {
		rep (i1, 1, n) {
			rep (j1, 1, m) {
				rep (i2, 1, n) {
					rep (j2, 1, m) {
						if (i1 + w[1] - 1 >= n || j1 + h[1] - 1 >= m) continue;
						if (i2 + w[2] - 1 >= n || j2 + h[2] - 1 >= m) continue;
						int s = get(dl(i1, j1), dl(i1 + w[1] - 1, j1 + h[1] - 1),
									dl(i2, j2), dl(i2 + w[2] - 1, j2 + h[2] - 1));
						if (w[1] * h[1] + w[2] * h[2] - s > ans) {
							ans = w[1] * h[1] + w[2] * h[2] - s;
							// cout << i1 << ' ' << j1 << ' ' << i2 << ' ' << j2 << endl;
						}
					}
				}
			}
		}
	}
	else if (k <= 4) {
		rep (i, 1, 4) ord[i] = i;
		do {
			memset(mp, 0, sizeof mp);
			rep (i, 1, k) {
				if (ord[i] == 1) {
					rep (k, 1, w[i]) {
						rep (j, 1, h[i]) mp[j][k] = 1;
					}
				}
				if (ord[i] == 2) {
					rep (k, 1, w[i]) {
						rep (j, 1, h[i]) mp[j][m - k + 1] = 1;
					}
				}
				if (ord[i] == 3) {
					rep (k, 1, w[i]) {
						rep (j, 1, h[i]) mp[n - j + 1][k] = 1;
					}
				}
				if (ord[i] == 4) {
					rep (k, 1, w[i]) {
						rep (j, 1, h[i]) mp[n - j + 1][m - k + 1] = 1;
					}
				}
			}
			int sum = 0;
			rep (i, 1, n) rep (j, 1, m) sum += mp[i][j];
			ans = max(ans, sum);
		} while (next_permutation(ord + 1, ord + 1 + 4));
	}
	else ans = n * m;
	print(ans), puts("");
	return 0;
}
