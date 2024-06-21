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

int w, b;

signed main() {
	cin >> w >> b;
	string str;
	rep (i, 1, 1000) str += "wbwbwwbwbwbw";
	rep (i, 0, 1000 * 12 - 1 - w - b) {
		int cw = 0, cb = 0;
		rep (j, 0, w + b - 1) {
			cw += str[i + j] == 'w';
			cb += str[i + j] == 'b';
		}
		if (cw == w && cb == b) {
			return puts("Yes"), 0;
		}
	}
	puts("No");
	return 0;
}
