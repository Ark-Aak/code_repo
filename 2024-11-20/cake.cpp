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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

int k, l, p, q;
int x[20], y[20];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
#endif
#endif
	k = read(), l = read(), p = read(), q = read();
	rep (i, 1, q) {
		x[i] = read(), y[i] = read();
		int ans = 0;
		rep (j, 1, l) {
			vector <int> cakes[20];
			rep (K, 1, k * l) {
				cakes[((K + j) / l) % k].push_back(K);
			}
			int ord[15];
			rep (K, 1, k) ord[K] = K;
			do {
				bool flg = 0;
				rep (K, 1, i) {
					bool f = 0;
					for (auto id : cakes[ord[y[K]] - 1]) {
						if (id == x[K]) f = 1;
					}
					if (!f) { flg = 1; break; }
				}
				if (flg) continue;
				ans++;
				ans %= p;
			} while (next_permutation(ord + 1, ord + 1 + k));
		}
		print(ans), puts("");
	}
	return 0;
}
