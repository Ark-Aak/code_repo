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

int a[4][4], vis[4][4];
pii toPair(int id) { return dl((id - 1) / 3 + 1, (id - 1) % 3 + 1); }

int dfs(int step) {
	if (step == 10) {
		int sum[3] = {0, 0, 0};
		rep (i, 1, 3) rep (j, 1, 3) sum[vis[i][j]] += a[i][j];
		if (sum[1] > sum[2]) return 1;
		return 2;
	}
	rep (i, 1, 3) {
		if (vis[i][1] && vis[i][1] == vis[i][2] && vis[i][2] == vis[i][3]) return vis[i][1];
	}
	rep (i, 1, 3) {
		if (vis[1][i] && vis[1][i] == vis[2][i] && vis[2][i] == vis[3][i]) return vis[1][i];
	}
	if (vis[1][1] && vis[1][1] == vis[2][2] && vis[2][2] == vis[3][3]) return vis[1][1];
	if (vis[1][3] && vis[1][3] == vis[2][2] && vis[2][2] == vis[3][1]) return vis[1][3];
	int ch = 2 - (step & 1);
	rep (i, 1, 9) {
		int x = toPair(i).ec, y = toPair(i).fb;
		if (!vis[x][y]) {
			vis[x][y] = ch;
			if (ch == dfs(step + 1)) return ch;
			vis[x][y] = 0;
		}
	}
	return 3 - ch;
}

signed main() {
	rep (i, 1, 3) rep (j, 1, 3) a[i][j] = read();
	puts(dfs(1) == 2 ? "Aoki" : "Takahashi");
	return 0;
}
