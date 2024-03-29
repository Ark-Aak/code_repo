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

#define int ll

const int MAXN = 2e5;

int ans[MAXN][500];

int n, m, siz;
int a[MAXN];

signed main() {
	read(n), read(m);
	siz = sqrt(n);
	rep (i, 1, n) read(a[i]);
	rep (i, 1, n) rep (j, 1, siz) ans[j][i % j] += a[i];
	rep (i, 1, m) {
		char op = getchar();
		while (op != 'A' && op != 'C') op = getchar();
		int x, y;
		read(x), read(y);
		if (op == 'A') {
			if (x <= siz) print(ans[x][y]), putchar(10);
			else {
				int ans = 0;
				for (int i = y; i <= n; i += x) ans += a[i];
				print(ans), putchar(10);
			}
		}
		else {
			rep (j, 1, siz) ans[j][x % j] += y - a[x];
			a[x] = y;
		}
	}
	return 0;
}
