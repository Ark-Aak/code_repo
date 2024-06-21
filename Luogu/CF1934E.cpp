#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i < = i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i > = i##end; i--)
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

vector <tuple <int, int, int> > pans[13];

int T, n;

void write(vector <tuple <int, int, int> > &ans) {
	print(ans.size()), puts("");
	for (auto [x, y, z] : ans) {
		print(x), putchar(32);
		print(y), putchar(32);
		print(z), puts("");
	}
}

#define insert(x, y, z) ans.emplace_back(x, y, z)

void solve() {
	n = read();
	if (n <= 12) {
		write(pans[n]);
		return;
	}
	vector <tuple <int, int, int> > ans;
	int tar = n / 2;
	if (n % 4 == 3 || n % 4 == 0) insert(1, n - 1, n), n -= 2;
	while (n > tar) {
		int x = n - 11;
		if (x % 4 == 3) {
			insert(x, x + 1, x + 2);
			insert(x + 4, x + 5, x + 6);
			insert(x + 8, x + 9, x + 10);
			insert(x + 3, x + 7, x + 11);
		}
		else if (x % 4 == 2) {
			insert(x + 1, x + 2, x + 3);
			insert(x + 5, x + 6, x + 7);
			insert(x + 9, x + 10, x + 11);
			insert(x, x + 4, x + 8);
		}
		n -= 12;
	}
	write(ans);
}

signed main() {
	pans[3] = { { 1, 2, 3 } };
	pans[4] = { { 1, 3, 4 } };
	pans[5] = { { 3, 4, 5 } };
	pans[6] = { { 1, 3, 5 }, { 2, 4, 6 } };
	pans[7] = { { 2, 4, 6 }, { 3, 5, 7 } };
	pans[8] = { { 2, 6, 8 }, { 3, 5, 7 } };
	pans[9] = { { 1, 3, 5 }, { 2, 4, 6 }, { 7, 8, 9 } };
	pans[10] = { { 3, 4, 5 }, { 2, 6, 8 }, { 7, 9, 10 } };
	pans[11] = { { 2, 6, 8 }, { 3, 5, 7 }, { 9, 10, 11 } };
	pans[12] = { { 1, 11, 12 }, { 6, 8, 10 }, { 5, 7, 9 } };
	T = read();
	while (T --> 0) solve();
	return 0;
}
