// Author: HeRaNO
// Thanks to template from cjj490168650
//     https://docs.qq.com/doc/DU3hjZHNiWnVQQWVW
#include "testlib.h"
using namespace std;

using point_t=long long;  //全局数据类型，可修改为 long long 等

constexpr point_t eps=0;

// 点与向量
template<typename T> struct point
{
	T x,y;

	bool operator==(const point &a) const {return (abs(x-a.x)<=eps && abs(y-a.y)<=eps);}
	bool operator<(const point &a) const {if (abs(x-a.x)<=eps) return y<a.y-eps; return x<a.x-eps;}
	bool operator>(const point &a) const {return !(*this<a || *this==a);}
	point operator+(const point &a) const {return {x+a.x,y+a.y};}
	point operator-(const point &a) const {return {x-a.x,y-a.y};}
	point operator-() const {return {-x,-y};}
	point operator*(const T k) const {return {k*x,k*y};}
	point operator/(const T k) const {return {x/k,y/k};}
	T operator*(const point &a) const {return x*a.x+y*a.y;}  // 点积
	T operator^(const point &a) const {return x*a.y-y*a.x;}  // 叉积，注意优先级
	int toleft(const point &a) const {const auto t=(*this)^a; return (t>eps)-(t<-eps);}  // to-left 测试
	T len2() const {return (*this)*(*this);}  // 向量长度的平方
	T dis2(const point &a) const {return (a-(*this)).len2();}  // 两点距离的平方
};

using Point=point<point_t>;

// 极角排序
struct argcmp
{
    bool operator()(const Point &a,const Point &b) const
    {
        const auto quad=[](const Point &a)
        {
            if (a.y<-eps) return 1;
            if (a.y>eps) return 4;
            if (a.x<-eps) return 5;
            if (a.x>eps) return 3;
            return 2;
        };
        const int qa=quad(a),qb=quad(b);
        if (qa!=qb) return qa<qb;
        const auto t=a^b;
        // if (abs(t)<=eps) return a*a<b*b-eps;  // 不同长度的向量需要分开
        return t>eps;
    }
};

// 直线
template<typename T> struct line
{
	point<T> p,v;  // p 为直线上一点，v 为方向向量

	bool operator==(const line &a) const {return v.toleft(a.v)==0 && v.toleft(p-a.p)==0;}
	int toleft(const point<T> &a) const {return v.toleft(a-p);}  // to-left 测试
	bool operator<(const line &a) const  // 半平面交算法定义的排序
	{
		if (abs(v^a.v)<=eps && v*a.v>=-eps) return toleft(a.p)==-1;
		return argcmp()(v,a.v);
	}
};

using Line=line<point_t>;

//线段
template<typename T> struct segment
{
	point<T> a,b;

	bool operator<(const segment &s) const {return make_pair(a,b)<make_pair(s.a,s.b);}

	// 判定性函数建议在整数域使用

	// 判断点是否在线段上
	// -1 点在线段端点 | 0 点不在线段上 | 1 点严格在线段上
	int is_on(const point<T> &p) const  
	{
		if (p==a || p==b) return -1;
		return (p-a).toleft(p-b)==0 && (p-a)*(p-b)<-eps;
	}

	// 判断线段直线是否相交
	// -1 直线经过线段端点 | 0 线段和直线不相交 | 1 线段和直线严格相交
	int is_inter(const line<T> &l) const
	{
		if (l.toleft(a)==0 || l.toleft(b)==0) return -1;
		return l.toleft(a)!=l.toleft(b);
	}
	
	// 判断两线段是否相交
	// -1 在某一线段端点处相交 | 0 两线段不相交 | 1 两线段严格相交
	int is_inter(const segment<T> &s) const
	{
		if (is_on(s.a) || is_on(s.b) || s.is_on(a) || s.is_on(b)) return -1;
		const line<T> l{a,b-a},ls{s.a,s.b-s.a};
		return l.toleft(s.a)*l.toleft(s.b)==-1 && ls.toleft(a)*ls.toleft(b)==-1;
	}
};

using Segment=segment<point_t>;


// 判断多条线段是否有交点
// 扫描线，复杂度 O(nlogn)
bool segs_inter(const vector<Segment> &segs)
{
	if (segs.empty()) return false;
	using seq_t=tuple<point_t,int,Segment>;
	const auto seqcmp=[](const seq_t &u, const seq_t &v)
	{
		const auto [u0,u1,u2]=u;
		const auto [v0,v1,v2]=v;
		if (abs(u0-v0)<=eps) return make_pair(u1,u2)<make_pair(v1,v2);
		return u0<v0-eps;
	};
	vector<seq_t> seq;
	for (auto seg:segs)
	{
		if (seg.a.x>seg.b.x+eps) swap(seg.a,seg.b);
		seq.push_back({seg.a.x,0,seg});
		seq.push_back({seg.b.x,1,seg});
	}
	sort(seq.begin(),seq.end(),seqcmp);
	point_t x_now;
	auto cmp=[&](const Segment &u, const Segment &v)
	{
		if (abs(u.a.x-u.b.x)<=eps || abs(v.a.x-v.b.x)<=eps) return u.a.y<v.a.y-eps;
		return (__int128)((x_now-u.a.x)*(u.b.y-u.a.y)+u.a.y*(u.b.x-u.a.x))*(v.b.x-v.a.x)<(__int128)((x_now-v.a.x)*(v.b.y-v.a.y)+v.a.y*(v.b.x-v.a.x))*(u.b.x-u.a.x)-eps;
	};
	multiset<Segment,decltype(cmp)> s{cmp};
	for (const auto [x,o,seg]:seq)
	{
		x_now=x;
		const auto it=s.lower_bound(seg);
		if (o==0)
		{
			if (it!=s.end() && seg.is_inter(*it) == 1) return true;
			if (it!=s.begin() && seg.is_inter(*prev(it)) == 1) return true;
			s.insert(seg);
		}
		else
		{
			if (next(it)!=s.end() && it!=s.begin() && (*prev(it)).is_inter(*next(it)) == 1) return true;
			if (it!=s.end()) s.erase(it);
		}
	}
	return false;
}

int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);
	int n = inf.readInt();
	vector<pair<int, int>> e;
	for (int i = 1; i < n; i++)
	{
		int x = inf.readInt();
		int y = inf.readInt();
		e.push_back({x, y});
	}
	vector<Point> p(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int x = inf.readInt();
		int y = inf.readInt();
		p[i] = (Point){x, y};
	}
	vector<int> pans = ouf.readInts(n, 1, n);
	vector<bool> vis(n, false);
	for (int i : pans)
	{
		if (vis[i - 1])
			quitf(_wa, "output is not a permutation");
		vis[i - 1] = true;
	}
	vector<int> tTop(n + 1, 0);
	for (int i = 0; i < n; i++) tTop[pans[i]] = i + 1;
	vector<Segment> segs;
	for (int i = 0; i < n - 1; i++)
	{
		int u, v; tie(u, v) = e[i];
		segs.push_back((Segment){p[tTop[u]], p[tTop[v]]});
	}
	if (segs_inter(segs))
		quitf(_wa, "intersection which isn't an endpoint exists.");
	quitf(_ok, "OK");
	return 0;
}
