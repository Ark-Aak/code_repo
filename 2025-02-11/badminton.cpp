#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define y1 _yahsdkj24JJlsadJ

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


int n, m, k;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("badminton.in", "r", stdin);
	freopen("badminton.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	vector <vector <int> > a1(n + 2, vector <int>(m + 2, 0));
	k = read();
	while (k --> 0) {
		int x = read(), y = read(), a = read(), b = read();
		int radius = a / b + (a % b > 0);
		int minn = a - radius * b;
		int x1, y1, x2, y2;
		x1 = x - radius + 1, x2 = x + radius - 1;
		y1 = y - radius + 1, y2 = y + radius - 1;
		rep (i, x1, x2) {
			a[i][y1] += minn;
		}

	}
	return 0;
}
