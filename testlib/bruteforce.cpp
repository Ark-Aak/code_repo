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

const int MAXN = 505;
int n, q;
int fa[MAXN];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	x = find(x), y = find(y);
	if (x != y) fa[x] = y;
}

signed main() {
	n = read(), q = read();
	rep (i, 1, n) fa[i] = i;
	while (q --> 0) {
		int op, l1, l2, r1, r2;
		op = read(), l1 = read(), r1 = read(), l2 = read(), r2 = read();
		if (op == 1) {
			rep (i, l1 + 1, r1) merge(l1, i);
			rep (i, l2 + 1, r2) merge(l2, i);
			merge(l1, l2);
		} else {
			rep (i, l1, r1) {
				rep (j, l2, r2) {
					if (find(i) != find(j)) {
						puts("No");
						goto end;
					}
				}
			}
			puts("Yes");
end:
			continue;
		}
	}
	return 0;
}
