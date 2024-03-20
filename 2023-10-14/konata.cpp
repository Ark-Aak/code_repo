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

double x[2], y[2];
double k, b;

const double PI = acos(-1.0);

double tor(double x) {
	return x / 180.0 * PI;
}

double tod(double x) {
	return x / PI * 180.0;
}

double dis(double k, double b, double x, double y, double d) {
	cout << k << " " << b << " " << x << " " << y << " " << d << endl;
	double kxby = abs(k * x + b - y);
	return kxby * cos(tor(d));
}

pair <double, double> getCenter(int X1, int Y1, int X2, int Y2, int X3, int Y3) {
	//c1 = x1,y1 x2,y2 交点
	//c2 = x1,y1 x3,y3 交点
	//c3 = x2,y2 x3,y3 交点 
	double cx1 = (X1 + X2) / 2.0, cy1 = (Y1 + Y2) / 2.0;
	double cx2 = (X1 + X3) / 2.0, cy2 = (Y1 + Y3) / 2.0;
	double cx3 = (X2 + X3) / 2.0, cy3 = (Y2 + Y3) / 2.0;
	double k1 = (cy3 - Y1) / (cx3 - X1);
	double b1 = cy3 - k1 * cx3;
	double k2 = (cy2 - Y2) / (cx2 - X2);
	double b2 = cy2 - k2 * cx2;
	double k3 = (cy1 - Y3) / (cx1 - X3);
	double b3 = cy1 - k3 * cx1;
	double cx = (b2 - b1) / (k1 - k2);
	double cy = k1 * cx + b1;
	return make_pair(cx, cy);
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("konata.in", "r", stdin);
	freopen("konata.out", "w",stdout);
#endif
#endif
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	if (x[0] == x[1]) {
		
		return 0;
	}
	if (y[0] > y[1]) k = (y[0] - y[1]) / (x[0] - x[1]);
	else k = (y[1] - y[0]) / (x[1] - x[0]);
	b = y[1] - k * (x[1]);
	double deg = 90.0 - tod(atan(1.0 / (k + b)));
	if (y[0] == y[1]) deg = 0;
	int n;
	cin >> n;
	if (n != 1) return 0;
	double X, Y, r;
	cin >> X >> Y >> r;
	double D = dis(k, b, X, Y, deg);
	double topy = Y + r, bottomy = Y - r;
	double leftx = X - r, rightx = X + r;
	if (r == D) {
		
	}
	return 0;
}

