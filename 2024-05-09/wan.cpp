#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 1e6 + 5;
typedef double ld;
ld n, h[MAXN], r[MAXN], R[MAXN];

using point_t = ld;

constexpr point_t eps = 1e-6;

/*
 * 点与向量
 */
template <typename T>
struct point {
	T x, y;

	bool operator == (const point &a) const { return (abs(x - a.x) <= eps && abs(y - a.y) <= eps); }
	bool operator < (const point &a) const { if (abs(x - a.x) <= eps) return y < a.y - eps; return x < a.x - eps; }
	bool operator > (const point &a) const { return !(*this < a || *this == a); }
	point operator + (const point &a) const { return { x + a.x, y + a.y }; }
	point operator - (const point &a) const { return { x - a.x, y - a.y }; }
	point operator - () const { return { -x, -y }; }
	point operator * (const T k) const { return { k * x, k * y }; }
	point operator / (const T k) const { return { x / k, y / k }; }
	T operator * (const point &a) const { return x * a.x + y * a.y; }  // 点积
	T operator ^ (const point &a) const { return x * a.y - y * a.x; }  // 叉积，注意优先级
	int toleft(const point &a) const {const auto t = (*this) ^ a; return (t > eps) - (t < -eps);}  // to-left 测试
	T len2() const { return (*this) * (*this);}  // 向量长度的平方
	T dis2(const point &a) const { return (a - (*this)).len2(); }  // 两点距离的平方
};

using Point = point <point_t>;

/*
 * 极角排序
 */
struct argcmp {
	bool operator () (const Point &a, const Point &b) const {
		const auto quad = [](const Point &a) {
            if (a.y < -eps) return 1;
            if (a.y > eps) return 4;
            if (a.x < -eps) return 5;
			if (a.x > eps) return 3;
			return 2;
		};
		const int qa = quad(a), qb = quad(b);
		if (qa != qb) return qa < qb;
		const auto t = a ^ b;
		// if (abs(t) <= eps) return a * a < b * b - eps;  // 不同长度的向量需要分开
		return t > eps;
	}
};

/*
 * 直线
 */
template<typename T>
struct line {
	point <T> p, v;
	// p 为直线上一点，v 为方向向量

	bool operator == (const line &a) const { return v.toleft(a.v) == 0 && v.toleft(p - a.p) == 0; }
	int toleft(const point <T> &a) const { return v.toleft(a - p); }  // to-left 测试
	// 半平面交算法定义的排序
	bool operator < (const line &a) const {
		if (abs(v ^ a.v) <=	eps && v * a.v >= -eps) return toleft(a.p) == -1;
		return argcmp()(v, a.v);
	}
};

using Line = line <point_t>;

/*
 * 线段
 */

template<typename T>
struct segment {

	// 判定性函数建议在整数域使用
	point <T> a, b;

	bool operator < (const segment &s) const { return make_pair(a, b) < make_pair(s.a, s.b); }

	/*
	 * 判断点是否在线段上
	 * -1 点在线段端点 | 0 点不在线段上 | 1 点严格在线段上
	 */
	int is_on(const point <T> &p) const {
		if (p == a || p == b) return -1;
		return (p - a).toleft(p - b) == 0 && (p - a) * (p - b) < -eps;
	}

	/*
	 * 判断线段直线是否相交
	 * -1 直线经过线段端点 | 0 线段和直线不相交 | 1 线段和直线严格相交
	 */
	int is_inter(const line <T> &l) const {
		if (l.toleft(a) == 0 || l.toleft(b) == 0) return -1;
		return l.toleft(a) != l.toleft(b);
	}

	/*
	 * 判断两线段是否相交
	 * -1 在某一线段端点处相交 | 0 两线段不相交 | 1 两线段严格相交
	 */
	int is_inter(const segment <T> &s) const {
		if (is_on(s.a) || is_on(s.b) || s.is_on(a) || s.is_on(b)) return -1;
		const line <T> l{ a, b - a }, ls{ s.a, s.b - s.a };
		return l.toleft(s.a) * l.toleft(s.b) == -1 && ls.toleft(a) * ls.toleft(b) == -1;
	}
};

using Segment = segment <point_t>;
ld ans[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("wan.in", "r", stdin);
	freopen("wan.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) h[i] = read(), r[i] = read(), R[i] = read();
	ld y_axis = 0;
	ld pans = 0;
	set <Segment> s;
	set <pair <ld, ld> > axis;
	rep (i, 1, n) {
		if (!s.size()) {
			s.insert((Segment) { (Point) { r[i], y_axis }, (Point) { R[i], y_axis + h[i] } });
			ans[i] = y_axis;
			pans = max(pans, ans[i] + h[i]);
			axis.insert(dl(R[i], y_axis + h[i]));
			continue;
		}
		if ((*s.rbegin()).b.x - r[i] < -eps) {
			y_axis = pans;
			ans[i] = y_axis;
			s.insert((Segment) { (Point) { r[i], y_axis }, (Point) { R[i], y_axis + h[i] } });
			axis.insert(dl(R[i], y_axis + h[i]));
			pans = max(pans, ans[i] + h[i]);
			axis.clear();
			continue;
		}
		long double pL = y_axis, pR = 1e15, mid = 0;
		auto aiter = axis.lower_bound(dl(r[i], 1e15));
		if (aiter != axis.begin()) {
			aiter = prev(aiter);
			pL = max(pL, (long double) (*aiter).fb);
		}
		auto iter = s.upper_bound((Segment) { (Point) { R[i], 0 }, (Point) { 0, 0 } });
		if (iter == s.begin()) {
			s.insert((Segment) { (Point) { r[i], y_axis }, (Point) { R[i], y_axis + h[i] } });
			ans[i] = y_axis;
			axis.insert(dl(R[i], y_axis + h[i]));
			pans = max(pans, ans[i] + h[i]);
			continue;
		}
		iter = prev(iter);
		Segment ts = *iter;
		while (pR - pL > eps) {
			mid = (pL + pR) / 2.0;
			Segment nw = { (Point) { r[i], (ld) mid }, (Point) { R[i], (ld) mid + h[i] } };
			if (nw.is_inter(ts) == 1) pL = mid + eps;
			else pR = mid - eps;
		}
		ans[i] = mid;
		pans = max(pans, ans[i] + h[i]);
		y_axis = mid;
		Segment nw = { (Point) { r[i], (ld) mid }, (Point) { R[i], (ld) mid + h[i] } };
		while (s.size() && (*s.begin()).b.y < nw.b.y) {
			s.erase(s.begin());
		}
		while (axis.size() && (*axis.begin()).fb < y_axis) {
			axis.erase(axis.begin());
		}
		s.insert((Segment) { (Point) { r[i], y_axis }, (Point) { R[i], y_axis + h[i] } });
		axis.insert(dl(R[i], y_axis + h[i]));
	}
	/* rep (i, 1, n) { */
		/* fprintf(stderr, "%d: %.6lf %.6lf\n", i, ans[i], h[i]); */
	/* } */
	printf("%.6lf\n", pans);
	fprintf(stderr, "Time: %.6lf sec\n", clock() * 1.0 / CLOCKS_PER_SEC);
	return 0;
}
