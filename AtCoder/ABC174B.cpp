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

int T, a[10], p[10];

signed main() {
	T = read();
	while (T --> 0) {
		rep (i, 1, 5) a[i] = read();
		rep (i, 1, 5) p[i] = read();
		if (2 * a[1] + a[2] <= a[4] + 2 * a[5]) {
			puts("0");
			continue;
		}
		int r = 2 * a[1] + a[2] - a[4] - 2 * a[5];
		if (p[4] * 2 <= p[5]) print(r * p[4]);
		else {
			if ((!(r & 1)) || p[4] > p[5]) print((r + 1) / 2 * p[5]);
			else print(r / 2 * p[5] + p[4]);
		}
		puts("");
	}
	return 0;
}
