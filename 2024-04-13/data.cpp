#include <bits/stdc++.h>

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

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r) { return abs((int) rnd()) % (r - l + 1) + l; }

int n = 2e5, k = 3;

signed main() {
	freopen("data.in", "w", stdout);
	ll sum = 0;
	print(n), putchar(32), print(k), puts("");
	rep (i, 2, n) {
		print(Rand(1, i - 1)), putchar(32);
		print(i), puts("");
	}
	rep (i, 1, n) {
		int t = Rand(1, 1e9);
		print(t), putchar(32);
		sum += t;
	}
	freopen("data.out", "w", stdout);
	print(sum);
	return 0;
}
