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

const int MAXN = 105;
int n, h, w, a[MAXN], b[MAXN], id[MAXN];
bool vis[MAXN][MAXN];
void dfs(int pp) {
	if (pp > n) {
		rep (i, 1, h) {
			rep (j, 1, w) {
				if (!vis[i][j]) {
					return;
				}
			}
		}
		puts("Yes"), exit(0);
	}
	dfs(pp + 1);
	int p = id[pp];
	rep (i, 1, h) {
		rep (j, 1, w) {
			if (!vis[i][j] && (vis[i][j - 1]) && (vis[i - 1][j])) {
				bool fl = 1;
				if (i + a[p] - 1 <= h && j + b[p] - 1 <= w) {
					rep (x, i, i + a[p] - 1) {
						rep (y, j, j + b[p] - 1) {
							if (vis[x][y]) {
								fl = 0;
								break;
							}
						}
						if (!fl) {
							break;
						}
					}
					if (fl) {
						rep (x, i, i + a[p] - 1) {
							rep (y, j, j + b[p] - 1) {
								vis[x][y] = 1;
							}
						}
						dfs(pp + 1);
						rep (x, i, i + a[p] - 1) {
							rep (y, j, j + b[p] - 1) {
								vis[x][y] = 0;
							}
						}
					}
				}
				fl = 1;
				if (i + b[p] - 1 <= h && j + a[p] - 1 <= w) {
					rep (x, i, i + b[p] - 1) {
						rep (y, j, j + a[p] - 1) {
							if (vis[x][y]) {
								fl = 0;
								break;
							}
						}
						if (!fl) {
							break;
						}
					}
					if (fl) {
						rep (x, i, i + b[p] - 1) {
							rep (y, j, j + a[p] - 1) {
								vis[x][y] = 1;
							}
						}
						dfs(pp + 1);
						rep (x, i, i + b[p] - 1) {
							rep (y, j, j + a[p] - 1) {
								vis[x][y] = 0;
							}
						}
					}
				}
			}
		}
	}
}

signed main() {
	n = read(), h = read(), w = read();
	rep (i, 0, h) {
		vis[i][0] = 1;
	}
	rep (i, 0, w) {
		vis[0][i] = 1;
	}
	rep (i, 1, n) {
		a[i] = read(), b[i] = read(), id[i] = i;
	}
	do {
		dfs(1);
        if (clock() * 1.0 / CLOCKS_PER_SEC > 1.8) {
			break;
		}
	} while(next_permutation(id + 1, id + n + 1));
	puts("No");
	return 0;
}
