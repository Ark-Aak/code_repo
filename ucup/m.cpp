#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

int T;

double dis(int X1, int Y1, int X2, int Y2) {
	return sqrt((X1 - X2) * (X1 - X2) + (Y1 - Y2) * (Y1 - Y2));
}

double rdis(int R, int x, int y) {
	return R - dis(x, y, 0, 0);
}

#define y1 nmslnmsl

const double eps = 1e-6;
const double PI = acos(-1);

double calc(double x1, double y1, double r1, double x2, double y2, double r2) {
	double d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	if (d >= r1 + r2) return 0.0;
	if (d <= fabs(r1 - r2)) return PI * pow(std::min(r1, r2), 2);
	double part1 = r1 * r1 * acos((d * d + r1 * r1 - r2 * r2) / (2 * d * r1));
	double part2 = r2 * r2 * acos((d * d + r2 * r2 - r1 * r1) / (2 * d * r2));
	double part3 = 0.5 * sqrt((-d + r1 + r2) * (d + r1 - r2) * (d - r1 + r2) * (d + r1 + r2));
	return part1 + part2 - part3;
}

void solve() {
	int n = read(), R = read(), r = read();
	vector <tuple <int, int, int> > pt;
	rep (i, 1, n) {
		int x = read(), y = read();
		pt.emplace_back(x, y, i);
	}
	vector <pair <double, int> > ans;
	for (auto [x, y, id] : pt) {
		ans.emplace_back(calc(0, 0, R, x, y, 2 * r), id);
	}
	sort(ans.begin(), ans.end(), greater <pair <double, int> >());
	vector <int> ansid;
	double maxv = ans[0].first;
	for (auto [v, id] : ans) if (fabs(v - maxv) < eps) ansid.push_back(id);
	sort(ansid.begin(), ansid.end());
	print(ansid.size()), puts("");
	for (auto x : ansid) print(x), putchar(32);
	puts("");
}

signed main() {
	T = read();
	while (T --> 0) solve();
	return 0;
}
