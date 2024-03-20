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

mt19937 rnd(time(0));

int Rand(int l, int r) {
	return (abs((int) rnd()) % (r - l + 1)) + l;
}

int n, m, k;

int main() {
	n = Rand(1, 1000);
	m = Rand(1, 1000);
	k = Rand(1, 1000);
	print(n), putchar(32), print(m), putchar(32), print(k), putchar(10);
	rep (i, 1, k) {
		int r = Rand(1, 2);
		if (r == 1) {
			putchar('R');
			putchar(32);
			print(Rand(1, n));
			putchar(32);
			print(Rand(1, 1e9));
		}
		else {
			putchar('S');
			putchar(32);
			print(Rand(1, m));
			putchar(32);
			print(Rand(1, 1e9));
		}
		if (i != k) putchar(10);
	}
	return 0;
}
