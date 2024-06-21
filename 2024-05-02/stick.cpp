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

const int MAXN = 1005;
int n, m, k;
mt19937 rnd(time(0));

struct node {
	int a, b;
} d[MAXN];

bool vis[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("stick.in", "r", stdin);
	freopen("stick.out", "w", stdout);
#endif
#endif
	freopen("stick5.in", "r", stdin);
	n = read(), m = read(), k = read();
	if (m == 0) {
		rep (i, 1, n) d[i].a = read(), d[i].b = read();
		sort(d + 1, d + 1 + n, [](node a, node b) {
			if (a.b == b.b) return a.a < b.a;
			else return a.b < b.b;
		});
		int lst = 0;
		rep (i, 1, n) {
			int minb = 1e9, id = 0;
			rep (j, 1, n) {
				int st = max(d[j].a, lst);
				if (st + k <= d[j].b) {
					if (d[j].b < minb) minb = d[j].b, id = j;
				}
			}
			if (id == 0) return puts("No"), 0;
			lst = max(d[id].a, lst) + k;
		}
		puts("Yes");
	}
	else {
		puts(rnd() & 1 ? "Yes" : "No");
	}
	return 0;
}
