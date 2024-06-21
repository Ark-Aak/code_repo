#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef pair<int, int> pii;

inline int read() {
	int x = 0, f = 1;
	char c = getchar();
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
int n, a[MAXN], b[MAXN], c[MAXN], cnt[MAXN][MAXN][MAXN];
int la[MAXN], lb[MAXN], lc[MAXN], A, B, C, o;
ll f[2][MAXN][MAXN], sum;

signed main() {
	n = read();
	rep (i, 1, n) {
		a[i] = la[i] = read();
		b[i] = lb[i] = read();
		c[i] = lc[i] = read();
		sum += (1ll * a[i] + b[i] + c[i]);
	}
	sort(la + 1, la + 1 + n);
	sort(lb + 1, lb + 1 + n);
	sort(lc + 1, lc + 1 + n);
	A = unique(la + 1, la + 1 + n) - la - 1;
	B = unique(lb + 1, lb + 1 + n) - lb - 1;
	C = unique(lc + 1, lc + 1 + n) - lc - 1;
	rep (i, 1, n) {
		a[i] = lower_bound(la + 1, la + 1 + A, a[i]) - la;
		b[i] = lower_bound(lb + 1, lb + 1 + B, b[i]) - lb;
		c[i] = lower_bound(lc + 1, lc + 1 + C, c[i]) - lc;
		cnt[a[i]][b[i]][c[i]]++;
	}
	rep (i, 1, A)
		rep (j, 1, B)
			rep (k, 1, C)
				cnt[i][j][k] += (cnt[i - 1][j][k] + cnt[i][j - 1][k] + cnt[i][j][k - 1] - cnt[i - 1][j - 1][k] - cnt[i][j - 1][k - 1] - cnt[i - 1][j][k - 1] + cnt[i - 1][j - 1][k - 1]);

	rep (i, 1, A) {
		o ^= 1;
		rep (j, 1, B)
			rep (k, 1, C)
				f[o][j][k] = 1e16;
		rep (j, 1, B) {
			rep (k, 1, C) {
				ll v = 1ll * la[i] + lb[j] + lc[k];
				f[o][j][k] = min(f[o][j][k], f[o ^ 1][j][k] + 1ll * v * (cnt[i][j][k] - cnt[i - 1][j][k]));
				f[o][j][k] = min(f[o][j][k], f[o][j - 1][k] + 1ll * v * (cnt[i][j][k] - cnt[i][j - 1][k]));
				f[o][j][k] = min(f[o][j][k], f[o][j][k - 1] + 1ll * v * (cnt[i][j][k] - cnt[i][j][k - 1]));
			}
		}
	}
	print(f[o][B][C] - sum), puts("");
	return 0;
}
