#include <map>
#include <set>
#include <array>
#include <cmath>
#include <deque>
#include <bitset>
#include <random>
#include <string>
#include <vector>
#include <cassert>
#include <complex>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int MAXN = 300'300;
const double INF = 8e18;

long long h[MAXN];
long long v[MAXN];  // max-catch !!! it differs from the statement
long long u[MAXN];  // max-drop  !!! because I read it incorrectly

struct LiChao1 {
    vector<long long> points;

    struct Line {
        double a;
        long long b;
        // a - sqrt(b + x)
        Line(double a, long long b) : a(a), b(b) {}
        Line() : a(INF), b(-INF){};
        double at(long long x) {
            if (b + x < 0)
                return INF;
            return a - sqrt(b + x);
        }
        bool operator==(const Line& other) { return a == other.a && b == other.b; }
    };

    const Line NONE;
    vector<Line> tree;
    vector<double> memo;

    void build(const vector<long long>& new_points) {
        int n = new_points.size();
        points = new_points;
        tree.resize(4 * n, NONE);
        memo.resize(4 * n, INF);
    }

    void add_line_on_segm(int v, int left, int right, int x, int y, Line line) {
        if (y <= left || right <= x || line == NONE)
            return;
        if (x <= left && right <= y) {
            int mid = (left + right) / 2;
            double new_v = line.at(points[mid]);
            if (memo[v] >= new_v) {
                swap(tree[v], line);
                swap(memo[v], new_v);
            }
            if (left + 1 == right || line == NONE || line.a == tree[v].a)
                return;
            if (line.b < tree[v].b) {
                if (tree[v].at(points[right - 1]) > line.at(points[right - 1]))
                    add_line_on_segm(2 * v + 2, mid, right, x, y, line);
            } else {
                if (tree[v].at(points[left]) > line.at(points[left]))
                    add_line_on_segm(2 * v + 1, left, mid, x, y, line);
            }
            return;
        }
        int mid = (left + right) / 2;
        add_line_on_segm(2 * v + 1, left, mid, x, y, line);
        add_line_on_segm(2 * v + 2, mid, right, x, y, line);
    }

    void add(double a, long long b, long long from, long long to) {
        add_line_on_segm(0, 0, points.size(),
                         lower_bound(points.begin(), points.end(), from) - points.begin(),
                         upper_bound(points.begin(), points.end(), to) - points.begin(), Line(a, b));
    }

    double get_opt(int v, int left, int right, int i) {
        if (left + 1 == right)
            return tree[v].at(points[i]);
        int mid = (left + right) / 2;
        if (i < mid)
            return min(tree[v].at(points[i]), get_opt(2 * v + 1, left, mid, i));
        else
            return min(tree[v].at(points[i]), get_opt(2 * v + 2, mid, right, i));
    }

    double get(long long x) {
        return get_opt(0, 0, points.size(), lower_bound(points.begin(), points.end(), x) - points.begin());
    }
};

long long cur_time = -INF;

struct LiChao2 {
    vector<long long> points;

    struct Line {
        double a;
        long long b;
        // a + sqrt(b + x)
        Line(double a, long long b) : a(a), b(b) {}
        Line() : a(INF), b(-INF){};
        double at(long long x) {
            x = max(x, cur_time);
            if (b + x < 0)
                return INF;
            return a + sqrt(b + x);
        }
        bool operator==(const Line& other) { return a == other.a && b == other.b; }
    };

    const Line NONE;

    vector<Line> tree;

    void build() {
        if (points.empty())
            points.emplace_back(0);
        int n = points.size();
        tree.resize(n == 1 ? 2 : (1 << (33 - __builtin_clz(n - 1))), NONE);
    }

    void add_line(int v, int left, int right, Line line) {
        if (line == NONE)
            return;
        int mid = (left + right) / 2;
        double old_v = tree[v].at(points[mid]);
        double new_v = line.at(points[mid]);
        if (old_v >= new_v) {
            swap(tree[v], line);
        }
        if (left + 1 == right || line == NONE)
            return;
        if (line.b > tree[v].b) {
            if (tree[v].at(points[right - 1]) > line.at(points[right - 1]))
                add_line(2 * v + 2, mid, right, line);
        } else {
            if (tree[v].at(points[left]) > line.at(points[left]))
                add_line(2 * v + 1, left, mid, line);
        }
    }

    void add(double a, long long b) { add_line(0, 0, points.size(), Line(a, b)); }

    double get_opt(int v, int left, int right, int i) {
        if (left + 1 == right)
            return tree[v].at(points[i]);
        int mid = (left + right) / 2;
        if (i < mid)
            return min(tree[v].at(points[i]), get_opt(2 * v + 1, left, mid, i));
        else
            return min(tree[v].at(points[i]), get_opt(2 * v + 2, mid, right, i));
    }

    double get(long long x) {
        return get_opt(0, 0, points.size(), lower_bound(points.begin(), points.end(), x) - points.begin());
    }
};

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    freopen("shiro.in", "r", stdin);
    freopen("shiro.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> h[i] >> u[i] >> v[i];

    LiChao1 li_chao1;
    vector<long long> points1(n);
    for (int i = 0; i < n; ++i) points1[i] = v[i] * v[i] + 2 * h[i];
    sort(points1.begin(), points1.end());
    points1.resize(unique(points1.begin(), points1.end()) - points1.begin());
    li_chao1.build(points1);

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(),
         [](int a, int b) { return u[a] * u[a] + 2 * h[a] < u[b] * u[b] + 2 * h[b]; });

    vector<int> id(n);
    for (int i = 0; i < n; ++i) id[order[i]] = i;

    vector<LiChao2> fenwick(n);

    vector<int> lefts(n);
    for (int j = n - 1; j >= 0; --j) {
        int left = -1, right = n;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            int i = order[mid];
            if (u[i] * u[i] + 2 * h[i] <= v[j] * v[j] + 2 * h[j])
                left = mid;
            else
                right = mid;
        }
        lefts[j] = left;
        for (int i = left; i >= 0; i = (i & (i + 1)) - 1) {
            fenwick[i].points.emplace_back(-2 * h[j]);
        }
    }

    for (int i = 0; i < n; ++i) fenwick[i].build();

    vector<double> dp(n, INF);
    dp[n - 1] = 0;
    for (int j = n - 1; j >= 0; --j) {
        cur_time = -2 * h[j];
        for (int i = lefts[j]; i >= 0; i = (i & (i + 1)) - 1) {
            double tmp = fenwick[i].get(-2 * h[j]);
            if (tmp < INF) {
                dp[j] = min(dp[j], tmp);
            }
        }

        double tmp = li_chao1.get(v[j] * v[j] + 2 * h[j]);
        if (tmp < INF) {
            dp[j] = min(dp[j], tmp + v[j]);
        }
        if (dp[j] != INF)
            li_chao1.add(dp[j], -2 * h[j], 2 * h[j], u[j] * u[j] + 2 * h[j]);

        if (dp[j] != INF) {
            for (int i = id[j]; i < n; i = (i | (i + 1))) {
                fenwick[i].add(dp[j] - u[j], u[j] * u[j] + 2 * h[j]);
            }
        }
    }
    if (dp[0] == INF) {
        cout << -1 << '\n';
    } else {
        cout << fixed << setprecision(20) << dp[0] << '\n';
    }

    // cerr << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}
