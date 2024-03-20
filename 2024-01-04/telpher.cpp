#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

const int MAXN = 1e5 + 5;
const long double eps = 1e-9;
int T, n;

int compare(long double a, long double b) {
	if (fabs(a - b) < eps) return 0;
	return a < b ? -1 : 1;
}

class convex {
public:
	struct point {
		long double x, y;
		point() {}
		point(int _x, int _y) : x(_x), y(_y) {}
	};
	struct line {
		long double k, b;
		line(point a, point b) {
			if (b.x - a.x == 0) { (this -> k = 1e12, this -> b = a.x); return; }
			this -> k = (b.y - a.y) / (b.x - a.x);
			this -> b = a.y - k * a.x;
		}
		long double at(long double x) { return k * x + b; }
		long double slope() { return k; }
	};
private:
	vector <point> p;
	long double slope(point a, point b) { return line(a, b).slope(); }
	bool check_slope(line A, line B) { return compare(A.slope(), B.slope()) == -1; }
public:
	void clear() { p.clear(); }
	void add(point x) {
		int siz = p.size();
		while (siz >= 2 && check_slope(line(p[siz - 2], p[siz - 1]), line(p[siz - 1], x)))
			p.pop_back(), siz--;
		p.push_back(x);
	}
	bool check(point a, point b) {
		point P;
		if (p.size() == 1) P = p[0];
		else {
			int l = 0, r = p.size() - 2;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (check_slope(line(p[mid], p[mid + 1]), line(a, b))) r = mid;
				else l = mid + 1;
			}
			if (check_slope(line(p[r], p[r + 1]), line(a, b))) P = p[r];
			else P = p[r + 1];
		}
		return compare(line(a, b).at(P.x), P.y) == -1;
	}
};

convex::point p[MAXN];

namespace seg {

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

	convex t[MAXN << 2];

	void build(int x, int L, int R) {
		t[x].clear();
		rep (i, L, R) t[x].add(p[i]);
		if (L == R) return;
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
	}

	int query(int x, int L, int R, int l, int r, int i) {
		if (l > r) return 0;
		if (L == l && R == r && t[x].check(p[i], p[i + 1]) == 0) return 0;
		if (L == R) return t[x].check(p[i], p[i + 1]) ? l : 0;
		if (r <= mid) return query(ls(x), L, mid, l, r, i);
		else if (l >= mid + 1) return query(rs(x), mid + 1, R, l, r, i);
		else {
			int res = query(ls(x), L, mid, l, mid, i);
			if (res) return res;
			else return query(rs(x), mid + 1, R, mid + 1, r, i);
		}
	}

#undef ls
#undef rs
#undef mid

} // namespace seg

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("telpher.in", "r", stdin);
	freopen("telpher.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) {
		n = read();
		rep (i, 1, n) p[i].x = read(), p[i].y = read();
		seg::build(1, 1, n);
		rep (i, 1, n - 1) {
			print(max(0, seg::query(1, 1, n, i + 2, n, i) - 1));
			putchar(32);
		}
		putchar(10);
	}
	return 0;
}
