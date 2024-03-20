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

const int MAXN = 105;
int k, n;
int pre[MAXN];
double p[MAXN];
double f[MAXN][1 << 20];

signed main() {
	k = read(), n = read();
	rep (i, 1, n) {
		p[i] = read();
		int t = read();
		while (t) pre[i] |= 1 << (t - 1), t = read();
	}
	_rep (i, k, 1) {
		rep (sta, 0, (1 << n) - 1) {
			rep (K, 1, n) {
				if ((sta & pre[K]) == pre[K]) {
					f[i][sta] += max(f[i + 1][sta], f[i + 1][sta | (1 << (K - 1))] + p[K]);
				}
				else f[i][sta] += f[i + 1][sta];
			}
			f[i][sta] /= (double) n;
		}
	}
	printf("%.6lf\n", f[1][0]);
	return 0;
}
