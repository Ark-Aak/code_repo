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

ll table[][2] = {{1,1},{80,80},{90,99},{100,109},{9800,9800},{9900,9999},{10000,10099},{998000,998000},{999000,999999},{1000000,1000999},{99980000,99980000},{99990000,99999999},{100000000,100009999},{9999800000,9999800000},{9999900000,9999999999},{10000000000,10000099999},{999998000000,999998000000},{999999000000,999999999999},{1000000000000,1000000999999},{99999980000000,99999980000000},{99999990000000,99999999999999},{100000000000000,100000009999999},{9999999800000000,9999999800000000},{9999999900000000,9999999999999999},{10000000000000000,10000000099999999},{999999998000000000,999999998000000000},{999999999000000000,999999999999999999},{1000000000000000000,1000000000000000000}};

ll T, n;

signed main() {
	T = read();
	rep (_, 1, T) {
		n = read();
		ll sum = 0;
		rep (i, 0, 27) {
			ll l = table[i][0];
			ll r = table[i][1];
			if (n >= r) sum += r - l + 1;
			else if (n < l) break;
			else {
				sum += n - l + 1;
			}
		}
		print(sum), putchar(10);
	}
	return 0;
}
