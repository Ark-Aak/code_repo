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

const int MOD1 = 39989, MOD2 = 1e9;
const double eps = 1e-9;

int cmp(double a, double b) {
	if (a - b > eps) return 1;
	if (b - a > eps) return -1;
	return 0;
}

struct func {
	double k, b;

	func() : k(0), b(0) {}

	func(double _k, double _b) : k(_k), b(_b) {}

	double val(double x) {
		return k * x + b;
	}
};

vector <func> p;

void insert(int _x0, int _y0, int _x1, int _y1) {
	if (_x0 == _x1) p.emplace_back(func(0, max(_y0, _y1)));
	else p.emplace_back(func(1.0 * (_y1 - _y0) / (_x1 - _x0),
						_y0 - 1.0 * (_y1 - _y0) / (_x1 - _x0) * _x0));
}



int main() {

	return 0;
}