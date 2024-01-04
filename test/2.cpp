#include <bits/stdc++.h>

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

#define int ll

int n, k;

set <pair <int, int> > p;
mt19937 rnd(time(0));

int r(int l, int r) {
	return rnd() % (r - l + 1) + l;
}

signed main() {
	n = read(), k = read();
	while (p.size() < floor(n * 0.1)) {
		int x = rnd() % n + 1, y = rnd() % n + 1;
		if (x > y) swap(x, y);
		if (x == y || y == x + 1) continue;
		p.insert({x, y});
		if (p.size() == floor(n * 7.987)) break;
		int nxt = r(x, y);
		while (nxt <= x + 1) nxt = r(x, y);
		p.insert({x, nxt});
		if (p.size() == floor(n * 7.987)) break;
		while (nxt >= y - 1) nxt = r(x, y);
		p.insert({nxt, y});
	}
	print(p.size()), putchar(10);
	for (auto [a, b] : p) {
		print(a), putchar(32), print(b), putchar(10);
	}
	return 0;
}
