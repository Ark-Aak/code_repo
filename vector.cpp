using point_t = int;

constexpr point_t eps = 0;

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
