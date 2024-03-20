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

int f[30][10][2][2];

int calc(int x) {
	memset(f, 0, sizeof f);
	int ch[30] = {0}, len = 0;
	while (x) ch[++len] = x % 10, x /= 10;
	rep (i, 0, ch[len]) f[len][i][i == ch[len]][i == 0] = 1;
	_rep (i, len - 1, 1) {
		rep (j, 0, 9) {
			rep (k, 0, 9) {
				rep (op, 0, 1) {
					rep (qd, 0, 1) {
						if (j == k && !qd) continue;
						if (op && j > ch[i]) continue;
						f[i][j][op && j == ch[i]][qd && j == 0] += f[i + 1][k][op][qd];
					}
				}
			}
		}
	}
	int res = 0;
	rep (i, 0, 9) res += f[1][i][0][1] + f[1][i][1][1] + f[1][i][1][0] + f[1][i][0][0];
	return res;
}

signed main() {
	int n;
	n = read();
	rep (i, 1, n) {
		int p;
		p = read();
		int l = 0, r = 1e18;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (calc(mid) <= p) l = mid + 1;
			else r = mid - 1;
		}
		print(l), putchar(10);
	}
	return 0;
}
