#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= b; i++)
#define _rep(i, a, b) for(int i = (a); i >= b; i--)

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

int T;
double x_1, y_1, x_2, y_2, x_m, y_m;

int main() {
	cin >> T;
	while (T --> 0) {
		cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_m >> y_m;
		double t = sqrt(x_m * x_m + y_m * y_m);
		printf("%.7lf %.7lf\n", x_m * sqrt(x_1 * x_2) / t, y_m * sqrt(x_1 * x_2) / t);
	}
	return 0; 
}
