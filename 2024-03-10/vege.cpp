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

const int MAXN = 2e3 + 5;

struct node {
	int cnt, d, w;
} a[MAXN], b[MAXN], c[MAXN];

int n, k;
int f[MAXN][MAXN];

bool cmp(node a, node b) {
	return a.d < b.d;
}

bool cmp2(node a, node b) {
	return a.d + f[a.cnt][a.w] < b.d + f[b.cnt][b.w];
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("vege.in", "r", stdin);
	freopen("vege.out", "w", stdout);
#endif
#endif
	n = read(), k = read();
	rep (i, 1, n) c[i].w = read(), c[i].d = read();
	sort(c + 1, c + n + 1, cmp);
	rep (i, 0, n) f[n][i] = (n - i) * 1e14;
	_rep (i, n - 1, 0) {
		rep (j, 0, i) {
			if (c[i + 1].d > j) f[i][j] = min(f[i + 1][j], f[i + 1][j + 1] + c[i + 1].w);
			else f[i][j] = f[i + 1][j];
		}
	}
	int cnt = 1;
	rep (i, 1, n) {
		int tcnt = 0;
		rep (j, 1, cnt) {
			++tcnt;
			b[tcnt].cnt = a[j].cnt + 1;
			b[tcnt].w = a[j].w;
			b[tcnt].d = a[j].d;
			if (a[j].w < c[i].d) {
				++tcnt;
				b[tcnt].cnt = a[j].cnt + 1;
				b[tcnt].w = a[j].w + 1;
				b[tcnt].d = a[j].d + c[i].w;
			}
		}
		sort(b + 1, b + tcnt + 1, cmp2);
		cnt = min(k, tcnt);
		rep (j, 1, cnt) a[j] = b[j];
	}
	rep (i, 1, k) {
		print(a[i].w), putchar(32), print(a[i].d), putchar(10);
	}
}
