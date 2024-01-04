#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 2e3 + 5;
char c[MAXN][MAXN];
int h, w;
unordered_map <string, bool> vis;

string compress() {
	stringstream ss;
	rep (i, 1, h) rep (j, 1, w) ss << c[i][j];
	return ss.str();
}

void dfs() {
	string tmp;
	if (vis[tmp = compress()]) return;
	vis[tmp] = 1;
	rep (i, 1, h) {
		rep (j, 1, (w + 1) / 2) swap(c[i][j], c[i][w - j + 1]);
		dfs();
		rep (j, 1, (w + 1) / 2) swap(c[i][j], c[i][w - j + 1]);
	}
	rep (i, 1, w) {
		rep (j, 1, (h + 1) / 2) swap(c[j][i], c[h - j + 1][i]);
		dfs();
		rep (j, 1, (h + 1) / 2) swap(c[j][i], c[h - j + 1][i]);
	}
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("noa.in", "r", stdin);
	freopen("noa.out", "w", stdout);
#endif
#endif
	read(h), read(w);
	int x = 0, y = 0;
	rep (i, 1, h) {
		rep (j, 1, w) {
			do {
				c[i][j] = getchar();
			} while (!isalpha(c[i][j]));
			if (c[i][j] ^ 97) x = i, y = j;
		}
	}
	if (h <= 3 && w <= 3) {
		dfs();
		print(vis.size()), putchar(10);
		return 0;
	}
	else {
		if (x == 0 && y == 0) return print(1), 0;
		int ans = 4, flg = 0;
		rep (i, 1, (h + 1) / 2) {
			if (c[i][y] != c[h - i + 1][y]) {
				flg = 1;
				break;
			}
		}
		if (!flg) ans -= 2;
		flg = 0;
		rep (i, 1, (w + 1) / 2) {
			if (c[x][i] != c[x][w - i + 1]) {
				flg = 1;
				break;
			}
		}
		if (!flg) ans -= 2;
		flg = 0;
		print(max(ans, 1));
		return 0;
	}
	return 0;
}
