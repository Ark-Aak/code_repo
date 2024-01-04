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

int n, q, sum;
int p[1005][1005];

signed main() {
	read(n), read(q);
	rep (i, 0, n - 1) {
		rep (j, 0, n - 1) {
			char c = getchar();
			while (c != 'W' && c != 'B') c = getchar();
			p[i][j] = (c == 'B');
			sum += p[i][j];
		}
	}
	int ans = 0;
	while (q --> 0) {
		int a, b, c, d;
		read(a), read(b), read(c), read(d);

	}
	return 0;
}
