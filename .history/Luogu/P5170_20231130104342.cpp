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
	Modint operator /= (Modint t) {return *this = *this * inv();}
	Modint operator / (Modint t) {return Modint(val * inv());}
	int val() {return val;}
	int mod() {return mod;}
};

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
	}
};

signed main() {
	Modint <MOD> a, b;
	a = 1, b = 2;
	
	return 0;
}