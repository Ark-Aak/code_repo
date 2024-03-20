#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

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

int r, c;
int w[30][30];
int ch[30][30], vis[30][30];

void check_dfs(int x, int y) {
	if (x < 1 || x > r || y < 1 || y > c) return;
	if (vis[x][y] || !ch[x][y]) return;
	vis[x][y] = 1;
	check_dfs(x - 1, y);
	check_dfs(x + 1, y);
	check_dfs(x, y - 1);
	check_dfs(x, y + 1);
}

bool check() {
	memset(vis, 0, sizeof(vis));
	int cnt = 0;
	rep(i, 1, r) rep(j, 1, c) if (ch[i][j] && !vis[i][j]) {
		check_dfs(i, j);
		++cnt;
		break;
	}
	return cnt == 1;
}

int sum() {
	int res = 0;
	rep(i, 1, r) rep(j, 1, c) if (ch[i][j]) res += w[i][j];
	return res;
}

int ans = 0, sm, W;

void dfs(int step, int val) {
	if (val > sm / W) return;
	if (step > r * c) {
		if (check() && sum() == sm / W) ans++;
		return;
	}
	ch[(step - 1) / c + 1][step % c == 0 ? c : step % c] = 1;
	dfs(step + 1, val + w[(step - 1) / c + 1][step % c == 0 ? c : step % c]);
	ch[(step - 1) / c + 1][step % c == 0 ? c : step % c] = 0;
	dfs(step + 1, val);
}

signed main() {
	r = read(), c = read();
	W = read();
	rep(i, 1, r) rep(j, 1, c) w[i][j] = read(), sm += w[i][j];
	if (sm % W) return puts("No"), 0;
	dfs(1, 0);
	print(ans);
	return 0;
}
