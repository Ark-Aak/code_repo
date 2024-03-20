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

const int MAXN = 3e5 + 5;
const long double eps = 1e-6;
int n, h[MAXN], v[MAXN], l[MAXN];

inline long double calc(long double v, long double h) {
	return -v + sqrt(v * v + 2 * h);
}

long double f[MAXN];
list <int> stat;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("shiro.in", "r", stdin);
	freopen("shiro.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) h[i] = read(), v[i] = read(), l[i] = read();
	stat.push_back(1);
	rep (i, 2, n) {
		f[i] = 1e18;
		/* rep (j, (n >= 2000 ? i - 1 : 1), i - 1) { */
		vector <list <int>::iterator> iters;
		for (auto iter = stat.begin(); iter != stat.end(); iter++) {
			int j = *iter;
			long double L = 0, R = v[i];
			long double v = 0;
			long double H = h[i] - h[j];
			long double ans = 1e18;
			while (R - L > eps) {
				v = (L + R) / 2;
				if (v + calc(v, H) <= l[j]) {
					ans = min(ans, calc(v, H));
					L = v + eps;
				}
				else R = v - eps;
			}
			/* printf("%d -> %d = %.6Lf, speed = %.6Lf", i, j, ans, v); */
			/* puts(""); */
			f[i] = min(f[i], f[j] + ans);
			if (fabs(ans - 1e18) <= eps) {
				iters.push_back(iter);
			}
		}
		for (auto it : iters) stat.erase(it);
		stat.push_back(i);
	}
	/* printf("%.10Lf", f[n]); */
	if (fabs(f[n] - 1e18) <= eps) puts("-1");
	else printf("%.10Lf\n", f[n]);
	/* cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl; */
	return 0;
}
