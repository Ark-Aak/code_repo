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

#ifndef MODINT_HPP
#define MODINT_HPP 1

template <int mod>
class Modint {
private:
	int val;

public:
	Modint(int v = 0) {if (v < 0) v += mod; val = v % mod;}
	Modint operator + (Modint t) {return Modint(val + t.val);}
	Modint operator - (Modint t) {return Modint(val - t.val);}
	Modint operator * (Modint t) {return Modint(val * t.val);}
	Modint operator += (Modint t) {return *this = *this + t;}
	Modint operator -= (Modint t) {return *this = *this - t;}
	Modint operator *= (Modint t) {return *this = *this * t;}
	Modint pow(int b) {
		Modint res = 1, a = *this;
		while (b) {if (b & 1) res *= a; a *= a; b >>= 1;}
		return res;
	}
	Modint inv() {return pow(mod - 2);}
	Modint operator /= (Modint t) {return *this = *this * t.inv();}
	Modint operator / (Modint t) {return Modint(val * t.inv());}
	int value() {return val;}
};
#endif

struct Element {
	int cntu, cntr, prod, sumi, sums, sqrs;

	Element() {
		cntu = cntr = prod = sumi = sums = sqrs = 0;
	}

	Element operator + (Element t) {
		Element res;
		res.cntu = cntu + t.cntu;
		res.cntr = cntr + t.cntr;
		res.sumi = sumi + t.sumi + cntr * t.cntr;
		res.sums = sums + t.sums + cntu * t.cntr;
		res.sqrs = sqrs + t.sqrs + cntu * cntu * t.cntr + int * cntu * t.sums;
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
	return ((long double) 1.0 * a * b + c) / d;
}

Element solve(int p, int q, int r, int l, Element U, Element R) {
	if (!l) return Element();
	if (p >= q) return solve(p % q, q, r, l, U, qpow(U, p / q) + R);
	int m = div(l, p, r, q);
	if (!m) return qpow(R, l);
	int cnt = l - div(q, m, -r - 1, p);
	return qpow(R, (q - r - 1) / p) + U + solve(q, p, (q - r - 1) % p, m - 1, R, U) + qpow(R, cnt);
}

int T, p, q, r, l;

signed main() {
	cin >> T;
	rep (i, 1, T) {
		cin >> l >> p >> r >> q;
		Element U, R;
		U.cntu = 1;
		R.cntr = 1; R.sumi = 1;
		Element ans = qpow(U, r / q) + solve(p, q, r % q, l, U, R);
		int val1 = ans.sums.value(), val2 = ans.sqrs.value(), val3 = ans.prod.value();
		cout << (val1 + r / q) % p << " " << (val2 + (r / q) % p * (r / q) % p) % p << " " << val3 << endl;
	}
	return 0;
}