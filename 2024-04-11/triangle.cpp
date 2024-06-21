#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <immintrin.h>
#include <emmintrin.h>

#include <bits/stdc++.h>

/* #define double float */

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

double ans = 1e10;

double dis(pii a, pii b) {
	return sqrt(1ll * (a.ec - b.ec) * (a.ec - b.ec) + 1ll * (a.fb - b.fb) * (a.fb - b.fb));
}

double slope(pii a) {
	return a.fb * 1.0 / a.ec;
}

// 极角
inline double angle(pii a) {
	return atan2(a.fb, a.ec);
}

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e6 + 5;
int n;
pii pt[MAXN], pt2[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("triangle.in", "r", stdin);
	freopen("triangle.out", "w", stdout);
#endif
#endif
	/* const int addr = 1e8; */
	n = read();
	const int addr1 = rnd(), addr2 = rnd();
	rep (i, 1, n) pt[i].ec = read() + addr1, pt[i].fb = read() + addr2;
	if (n > 100) {
		sort(pt + 1, pt + n + 1, [](pii a, pii b) { return a.ec < b.ec; });
		const int th = 5;
		rep (i, 1, n - 2) {
			rep (j, i + 1, min(n, i + th * 3)) {
				rep (k, j + 1, min(n, i + th * 3)) {
					double tans = dis(pt[i], pt[j]) + dis(pt[j], pt[k]) + dis(pt[k], pt[i]);
					if (tans < ans) {
						ans = tans;
					}
				}
			}
		}
		sort(pt + 1, pt + n + 1, [](pii a, pii b) { return slope(a) == slope(b) ? a.ec < b.ec : slope(a) < slope(b); });
		int cnt = 1, ct = 1;
		pt2[1] = pt[1];
		rep (i, 2, n) {
			if (slope(pt[i]) != slope(pt[i - 1])) {
				ct = 1;
				pt2[++cnt] = pt[i];
			}
			else {
				if (ct >= 5) continue;
				pt2[++cnt] = pt[i];
				ct++;
			}
		}
		rep (i, 1, cnt) pt[i] = pt2[i];
		n = cnt;
		rep (i, 1, n - 2) {
			rep (j, i + 1, n) {
				rep (k, j + 1, n) {
					double tans = dis(pt[i], pt[j]) + dis(pt[j], pt[k]) + dis(pt[k], pt[i]);
					if (tans < ans) {
						ans = tans;
					}
					if (clock() * 1.0 / CLOCKS_PER_SEC > 1.9) {
						printf("%.14lf\n", ans);
						return 0;
					}
				}
			}
		}
		printf("%.14lf\n", ans);
	}
	else {
		rep (i, 1, n) {
			rep (j, 1, n) {
				rep (k, 1, n) {
					if (i == j || j == k || i == k) continue;
					ans = min(ans, dis(pt[i], pt[j]) + dis(pt[j], pt[k]) + dis(pt[k], pt[i]));
				}
			}
		}
		printf("%.14lf\n", ans);
	}
	return 0;
}
