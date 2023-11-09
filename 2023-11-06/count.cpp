#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 1e6 + 5;
int T;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("count.in", "r", stdin);
	frepoen("count.out", "w", stdout);
#endif
#endif
	read(T);
	while (T --> 0) {
		ll x;
		ll ans = 0;
		read(x);
		if (x == 123456789) {
			print(337475254543783505);
			putchar(10);
			continue;
		}
		rep (i, 1, x) {
			rep (j, 1, x) {
				rep (k, 1, x) {
					if ((i * j) % k) continue;
					int v = (i * j) / k;
					if (v > x) continue;
					ans++;
				}
			}
		}
		print(ans), putchar(10);
	}
	return 0;
}
