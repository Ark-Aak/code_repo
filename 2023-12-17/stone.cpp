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

int n;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
#endif
#endif
	read(n);
	if ((n >> 1) & 1) return puts("NO"), 0;
	else puts("YES");
	if (!(n & 1)) {
		int k = n / 4;
		rep (i, 1, k) print(i), putchar(32), print(n - i + 1), putchar(10);
		rep (i, k + 1, 2 * k - 1) print(i), putchar(32), print(n - i), putchar(10);
		print(2 * k), putchar(32), print(1), putchar(10);
		rep (i, 2 * k + 1, 3 * k - 1) print(i), putchar(32), print(n - i + 1), putchar(10);
		print(3 * k), putchar(32), print(n - k), putchar(10);
		rep (i, 3 * k + 1, 4 * k) print(i), putchar(32), print(n - i + 2), putchar(10);
	}
	else {
		int k = n / 4;
		rep (i, 1, k) print(i), putchar(32), print(n - i + 1), putchar(10);
		print(k + 1), putchar(32), print(k + 2), putchar(10);
		rep (i, k + 2, 2 * k) print(i), putchar(32), print(n - i + 2), putchar(10);
		print(2 * k + 1), putchar(32), print(1), putchar(10);
		rep (i, 2 * k + 2, 3 * k + 1) print(i), putchar(32), print(n - i + 3), putchar(10);
		rep (i, 3 * k + 2, 4 * k + 1) print(i), putchar(32), print(n - i + 2), putchar(10);
	}
	return 0;
}
