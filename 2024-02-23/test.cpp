#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

double Rand_d() {
	return (double) rnd() / (double) (UINT_MAX);
}

int Rand(int l, int r) {
	return Rand_d() * (r - l + 1) + l;
}

signed main() {
	freopen("rand.txt", "w", stdout);
	rep (i, 1, 2e7) {
		putchar('a' + Rand(0, 25));
	}
	return 0;
}
