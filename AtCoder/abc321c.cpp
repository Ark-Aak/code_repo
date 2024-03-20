#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define _rep(i, a, b) for(int i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}



int main() {
	ll kk, cnt = 0;
	cin >> kk;
	++kk;
	rep (a, 0, 9)
	rep (b, 0, a == 0 ? 9 : a - 1)
	rep (c, 0, a == 0 && b == 0 ? 9 : b - 1)
	rep (d, 0, a == 0 && b == 0 && c == 0 ? 9 : c - 1)
	rep (e, 0, a == 0 && b == 0 && c == 0 && d == 0 ? 9 : d - 1)
	rep (f, 0, a == 0 && b == 0 && c == 0 && d == 0 && e == 0 ? 9 : e - 1)
	rep (g, 0, a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 ? 9 : f - 1)
	rep (h, 0, a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 ? 9 : g - 1)
	rep (i, 0, a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 ? 9 : h - 1)
	rep (j, 0, a == 0 && b == 0 && c == 0 && d == 0 && e == 0 && f == 0 && g == 0 && h == 0 && i == 0 ? 9 : i - 1) {
		++cnt;
		ll num = a * 1e9 + b * 1e8 + c * 1e7 + d * 1e6 + e * 1e5 + f * 1e4 + g * 1e3 + h * 1e2 + i * 10 + j;
		if (cnt == kk) {
			cout << num;
			return 0;
		}
	}
	return 0; 
}
