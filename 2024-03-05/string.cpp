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

const int MAXN = 505;
int n, m;
int str[MAXN][MAXN];
int fa[MAXN][MAXN];
int d[MAXN][MAXN], l[MAXN][MAXN], r[MAXN][MAXN];

int find(int x, int y) {
	return fa[y][x] == x ? fa[y][x] : fa[y][x] = find(fa[y][x], y);
}

#define dis(x, y) ((x) > (y) ? (x) - (y) : n - (y) + (x))

int calc(int x, int y) {
	int res = 0;
	rep (i, 0, m - 1)
		if (str[x][i] == str[y][i]) res |= 1 << i;
	return res;
}

queue <pii> q;

bool insert(int x, int y, int val) {
	if (d[x][y] >= 0) return false;
	if (l[x][y]) fa[y][x] = find(l[x][y], y);
	return q.emplace(x, y), d[x][y] = val, true;
}

void init() {
	rep (i, 1, n) {
		for (int j = i % n + 1; j != i; j = (j % n) + 1) {
			int stat = calc(i, j);
			for (int t = stat; ; t = (t - 1) & stat) {
				l[i][t] = j; if (!r[i][t]) r[i][t] = j;
				if (!t) break;
			}
		}
		rep (stat, 0, (1 << m) - 1) {
			if (!l[i][stat]) l[i][stat] = i;
			if (!r[i][stat]) r[i][stat] = i;
		}
	}
}

void bfs(int st) {
	memset(d, -1, sizeof d);
	rep (i, 1, n) {
		rep (j, 0, (1 << m) - 1) fa[j][i] = i;
	}
	rep (i, 0, (1 << m) - 1) insert(st, i, 0);
	while (q.size()) {
		int u = q.front().ec, val = q.front().fb;
		q.pop();
		insert(l[u][val], val, d[u][val] + 1);
		insert(r[u][val], val, d[u][val] + 1);
		rep (j, 0, m - 1) {
			int stat = val ^ (1 << j);
			if (!(val & (1 << j))) insert(u, stat, d[u][val] + 1);
			else {
				for (int x = find(u, stat); x; x = find(x, stat)) {
					if (u != x && dis(u, x) >= dis(u, l[u][val])) break;
					if (!insert(x, stat, d[u][val] + 1)) break;
				}
			}
		}
	}
}

int ans[MAXN][MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, n) rep (j, 0, m - 1) str[i][j] = read();
	init();
	rep (i, 1, n) {
		bfs(i);
		rep (j, 1, n) ans[j][i] = d[j][0];
	}
	rep (i, 1, n) {
		rep (j, 1, n) print(ans[i][j]), putchar(32);
		putchar(10);
	}
	return 0;
}
