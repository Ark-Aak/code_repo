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

const int MAXN = 2e5 + 5;
int n, m;
int cw[MAXN], cc[MAXN], bot[MAXN];

signed main() {
	read(n), read(m);
	rep (i, 1, n) read(cw[i]);
	rep (i, 1, m) read(cc[i]), bot[i] = 0;
	rep (i, 1, m) {
		rep (j, 1, n) {
			int et = max(0ll, cw[j] >= cc[i] ? cc[i] - bot[i] : cw[j] - bot[i]);
			bot[i] += et;
			cw[j] += et;
			if (bot[i] >= cc[i]) break;
		}
	}
	rep (i, 1, n) print(cw[i]), putchar(10);
	return 0;
}
