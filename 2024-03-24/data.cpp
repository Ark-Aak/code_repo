#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

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

mt19937 _rnd(chrono::steady_clock::now().time_since_epoch().count());

int rnd(int l, int r) {
	return abs((int) _rnd()) % (r - l + 1) + l;
}

const int n = 5, Q = 5;

#include "../testlib/lib/graph.hpp"

signed main() {
	freopen("data.in", "w", stdout);
	printf("%lld %lld\n", n, Q);
	vector <pii> g = tree(n, 0, 0, 0);
	for (auto x : g) printf("%lld %lld\n", x.ec, x.fb);
	rep (i, 1, n) printf("%lld ", rnd(1, 10));
	puts("");
	rep (i, 1, Q) {
		int op = rnd(1, 2);
		if (op == 2) op = 4;
		if (op == 1) {
			printf("1 %lld\n", rnd(1, n));
		}
		else if (op == 2) {
			printf("2 %lld %lld %lld %lld\n", rnd(1, n), rnd(1, 10), rnd(1, 10), rnd(1, 10));
		}
		else if (op == 3) {
			printf("3 %lld %lld %lld\n", rnd(1, n), rnd(1, 10), rnd(1, 10));
		}
		else {
			printf("4 %lld %lld %lld %lld\n", rnd(1, n / 2), rnd(n / 2 + 1, n), rnd(1, 10), rnd(1, 10));
		}
	}
	return 0;
}
