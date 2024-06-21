#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int n;
double x[105], y[105];

double dis(int X1, int Y1, int X2, int Y2) {
	return sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
}

signed main() {
	cin >> n;
	rep (i, 1, n) cin >> x[i] >> y[i];
	rep (i, 1, n) {
		int id = 0;
		double tv = 0;
		rep (j, 1, n) {
			if (i == j) continue;
			if (dis(x[i], y[i], x[j], y[j]) > tv) {
				tv = dis(x[i], y[i], x[j], y[j]);
				id = j;
			}
		}
		cout << id << endl;
	}
	return 0;
}
