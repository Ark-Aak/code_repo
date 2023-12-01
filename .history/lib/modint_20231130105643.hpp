#ifndef MODINT_HPP
#define MODINT_HPP

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