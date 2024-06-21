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

#include "graph.hpp"
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

int Rand(int l, int r) { return abs((int) rnd()) % (r - l + 1) + l; }

signed main() {
	const int n = 5, m = 7, q = 3;
	const int V = 10;
	vector <pii> edges = DAG(n, m);
	cout << n << " " << m << " " << q << endl;
	for (auto [u, v] : edges) cout << u << " " << v << endl;
	rep (i, 1, q) {
		int tp = Rand(1, 3);
		cout << tp << " ";
		if (tp == 1) cout << Rand(1, n) << " " << Rand(1, V) << endl;
		if (tp == 2) cout << Rand(1, n) << " " << Rand(1, V) << endl;
		if (tp == 3) cout << Rand(1, n) << endl;
	}
	return 0;
}
