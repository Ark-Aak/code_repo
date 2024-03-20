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
int a[MAXN][MAXN];
int b[MAXN][MAXN];
char c[MAXN][MAXN];
char d[MAXN][MAXN];
int h, w;
unordered_map <string, int> vis;

string compress(char c[MAXN][MAXN]) {
	stringstream ss;
	rep (i, 1, h) rep (j, 1, w) ss << c[i][j];
	return ss.str();
}

int ans = 1e9;
string tar;

void dfs(int step) {
	if (step >= ans || step > 30) return;
	string tmp = compress(c);
	if (tmp == tar) {
		ans = min(ans, step);
	}
	if (vis.count(tmp) && vis[tmp] <= step) return;
	vis[tmp] = step;
	rep (i, 1, h - 1) {
		rep (j, 1, w) swap(c[i][j], c[i + 1][j]);
		dfs(step + 1);
		rep (j, 1, w) swap(c[i][j], c[i + 1][j]);
	}
	rep (i, 1, w - 1) {
		rep (j, 1, h) swap(c[j][i], c[j][i + 1]);
		dfs(step + 1);
		rep (j, 1, h) swap(c[j][i], c[j][i + 1]);
	}
}

unordered_map <int, char> _Ref;

int main() {
	read(h), read(w);
	rep (i, 1, h) {
		rep (j, 1, w) {
			read(a[i][j]);
			if (!_Ref.count(a[i][j])) _Ref[a[i][j]] = 'a' + _Ref.size();
			c[i][j] = _Ref[a[i][j]];
		}
	}
	rep (i, 1, h) {
		rep (j, 1, w) {
			read(b[i][j]);
			if (!_Ref.count(b[i][j])) {
				puts("-1");
				exit(0);
			}
			d[i][j] = _Ref[b[i][j]];
		}
	}
	tar = compress(d);
	dfs(0);
	if (ans < 1e9) print(ans);
	else puts("-1");
	return 0;
}
