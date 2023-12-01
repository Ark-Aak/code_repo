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

int T, n, m;

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("divide.in", "r", stdin);
	freopen("divide.out", "w", stdout);
#endif
#endif
	read(T);
	while (T --> 0) {
		read(n), read(m);
		if (n == 1) {
			puts("-1");
			continue;
		}
		int tn = m / 2, tm = m;
		rep (i, -5, 5) {
			rep (j, -5, 5) {
				int ttn1 = tn + i, ttn2 = tn + j;
				tm = m - ttn1 * 2 - ttn2 * 2;
				if (ttn1 <= 0 || ttn2 <= 0) continue;
				if (tm < 0) continue;
				if (n == 2 && tm == 0) {
					if (min(ttn1, ttn2) > (ttn1 ^ ttn2)) {
						print(ttn1), putchar(32), print(ttn2), putchar(10);
						goto end;
					}
				}
				else if (n == 3) {
					if (min(tm, min(ttn1, ttn2)) > (tm ^ ttn1 ^ ttn2)) {
						print(tm), putchar(32), print(ttn1), putchar(32), print(ttn2), putchar(10);
						goto end;
					}
				}
			}
		}
		puts("-1");
		end:
		continue;
	}
	return 0;
}