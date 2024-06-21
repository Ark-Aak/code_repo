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

const int MAXN = 5e5 + 5;
int n, a[MAXN];

namespace BIT {
	int mx[MAXN];

	void add(int x, int v) {
		++x;
		for (int o = x; o <= 2 * n; o += o & -o)
			mx[o] = max(mx[o], v);
	}

	int query(int x, int res = 0) {
		++x;
		for (int o = x; o; o -= o & -o)
			res = max(res, mx[o]);
		return res;
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n) {
		int diff = a[i] - i;
		if (diff < 0) continue;
		int val = BIT::query(diff);
		BIT::add(diff, val + 1);
		if (i == n) {
			return print(n - val - 1), puts(""), 0;
		}
	}
	return 0;
}
