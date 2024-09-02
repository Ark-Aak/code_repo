#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int n, lg;
vector <tuple <int, int, int> > edges;

void work(int n) {
    rep (i, 1, lg) {
        edges.push_back(dk(i - 1, i, 1 << (i - 1)));
        edges.push_back(dk(i - 1, i, 0));
        // base axis
    }
    int sum = (1 << lg);
    _rep (i, lg - 1, 0) {
        // 第 i 个点能做到 0 ~ (1 << i) - 1
        if (sum + (1 << i) - 1 > n) continue;
        edges.push_back(dk(i, lg, sum));
        sum += (1 << i);
    }
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
#endif
#endif
    n = read();
    lg = log2(n + 1);
    work(n);
    printf("%d %d\n", lg + 1, (int) edges.size());
    for (auto edge : edges) {
        int x = get<0>(edge), y = get<1>(edge), z = get<2>(edge);
        x++, y++;
        if (y == lg + 1) y = 114;
        printf("%d %d %d\n", x, y, z);
    }
	return 0;
}
