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

#define int ll
const int MOD = 998244353;

#include "../lib/modint.hpp"

struct Element {
	Modint <MOD> cntu, cntr, prod, sumi, sums, sqrs;

	Element() {
		cntu = cntr = prod = sumi = sums = sqrs = 0;
	}

	Element operator + (Element t) {
		Element res;
		res.cntu = cntu + t.cntu;
		res.cntr = cntr + t.cntr;
		res.sumi = sumi + t.sumi + cntr * t.cntr;
		res.sums = sums + t.sums + cntu * t.cntr;
		res.sqrs = sqrs + t.sqrs + cntu * cntu * t.cntr + Modint <MOD> (2) * cntu * t.sums;
		res.prod = prod + t.prod + cntu * cntr * t.cntr + cntu * t.sumi + cntr * t.sums;
		return res;
	}
};

Element qpow(Element a, int b) {
	Element res;
	while (b) {
		if (b & 1) res = res + a;
		a = a + a;
		b >>= 1;
	}
	return res;
}

int div(int a, int b, int c, int d) {
	return ((long double) 1.0 * a * b + c / d);
}

signed main() {

	return 0;
}