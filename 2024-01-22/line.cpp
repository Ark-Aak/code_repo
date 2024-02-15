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

const int MAXN = 5005;
int n, h[MAXN], d[MAXN];
int order[MAXN];

pii f(int i, int j, int k) {
	int h1 = h[i], d1 = d[i], h2 = h[j], d2 = d[j], h3 = h[k], d3 = d[k];
	return make_pair(h1 * d2 + h2 * d3 + h3 * d1, h3 * d2 + h2 * d1 + h1 * d3);
}

bool check(int i, int j, int k) {
	return f(i, j, k).first >= f(i, j, k).second;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("line.in", "r", stdin);
	freopen("line.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) h[i] = read(), d[i] = read();
	rep (i, 1, n) order[i] = i;
	_rep (i, n, 3) {
		rep (i, 1, n) {
			int j = i;
			while (j > 2 && !check(order[j - 2], order[j - 1], order[j])) {
				swap(order[j], order[j - 1]);
				j--;
			}
		}
	}
	rep (i, 1, n) print(order[i]), putchar(32);
	return 0;
}
