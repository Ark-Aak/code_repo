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

ll n, m;
ll e[105][105];

int main() {
	read(n), read(m);
	memset(e, 0x3f, sizeof e);
	rep (i, 1, m) {
		int u, v, w;
		read(u), read(v), read(w);
		e[u][v] = e[v][u] = w;
	}
	rep (k, 1, n) {
		rep (i, 1, n) {
			rep (j, 1, n) e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
		}
	}
	rep (i, 1, n) e[i][i] = 0;
	rep (i, 1, n) {
		rep (j, 1, n) {
			print(e[i][j]), putchar(32);
		}
		putchar(10);
	}
	return 0;
}
