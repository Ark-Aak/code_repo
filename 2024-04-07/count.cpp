#include <bits/stdc++.h>

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

int n, k, c, ans;
int no[10][10];
int ch[10][10];

void dfs(int x, int y, int cnt) {
	if (x > 1 && y == 1) {
		bool flg = 0;
		rep (i, 1, n) flg |= ch[x - 1][i];
		if (!flg) return;
	}
	if (x == n + 1) {
		if (cnt != c) return;
		bool flg = 0;
		/* rep (x, 1, n) { */
			/* flg = 0; */
			/* rep (i, 1, n) flg |= ch[x][i]; */
			/* if (!flg) return; */
		/* } */
		rep (y, 1, n) {
			flg = 0;
			rep (i, 1, n) flg |= ch[i][y];
			if (!flg) return;
		}
		flg = 0;
		rep (i, 1, n) flg |= ch[i][i];
		if (!flg) return;
		flg = 0;
		rep (i, 1, n) flg |= ch[i][n - i + 1];
		if (!flg) return;
		ans++;
		return;
	}
	if (y == n) {
		if (cnt < c && !no[x][y]) {
			ch[x][y] = 1;
			dfs(x + 1, 1, cnt + 1);
		}
		ch[x][y] = 0;
		dfs(x + 1, 1, cnt);
	}
	else {
		if (cnt < c && !no[x][y]) {
			ch[x][y] = 1;
			dfs(x, y + 1, cnt + 1);
		}
		ch[x][y] = 0;
		dfs(x, y + 1, cnt);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
#endif
#endif
	n = read(), k = read(), c = read();
	rep (i, 1, k) {
		int x = read(), y = read();
		no[x][y] = 1;
	}
	dfs(1, 1, 0);
	print(ans);
	return 0;
}
