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

const int T = 2;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	const int n = 2;
	print(T), puts("");
	/*
	rep (i, 1, T) {
		vector <int> ord(n);
		rep (i, 1, n) ord[i - 1] = i;
		shuffle(ord.begin(), ord.end(), rnd);
		print(n), puts("");
		for (auto v : ord) print(v), putchar(32);
		puts("");
	}
	*/
	vector <int> ord(n);
	rep (i, 1, n) ord[i - 1] = i;
	do {
		print(n), puts("");
		for (auto v : ord) print(v), putchar(32);
		puts("");
	} while (next_permutation(ord.begin(), ord.end()));
	return 0;
}
