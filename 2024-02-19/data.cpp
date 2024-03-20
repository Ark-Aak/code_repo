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

int Rand(int l, int r) { return rnd() % (r - l + 1) + l; }

signed main() {
	freopen("data.in", "w", stdout);
	int n = 100000, q = 2000;
	printf("%lld %lld\n", n, q);
	while (q --> 0) {
		int tp = Rand(1, 3);
		if (tp != 1) tp += 2;
		if (tp == 1) {
			int l = Rand(1, n), r = Rand(1, n), x;
			if (l > r) swap(l, r);
			x = Rand(1, 2000);
			printf("%lld %lld %lld %lld\n", tp, l, r, x);
		}
		else if (tp == 4) {
			int x = Rand(1, 2000);
			printf("%lld %lld\n", tp, x);
		}
		else {
			printf("%lld\n", tp);
		}
	}
	return 0;
}
