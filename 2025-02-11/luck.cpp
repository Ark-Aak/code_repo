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

const int MAXN = 1e5 + 5;

vector <int> k[MAXN];
int n, Q;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("luck.in", "r", stdin);
	freopen("luck.out", "w", stdout);
#endif
#endif
	n = read(), Q = read();
	rep (i, 1, n) {
		int K = read();
		rep (j, 1, K) k[i].push_back(read());
	}
	while (Q --> 0) {
		int x = read(), y = read();
		if (x > y) swap(x, y);
		int res = 0, ptrx = 1, ptry = 1;
		int wayx = (k[x][1] > k[x][0]), wayy = (k[y][1] > k[y][0]);
		int posx = k[x][0], posy = k[y][0];
		while (ptrx < k[x].size() && ptry < k[y].size()) {
			int costx = abs(posx - k[x][ptrx]), costy = abs(posy - k[y][ptry]);
			int cost = min(costx,costy);
			if (wayx != wayy) {
				int lx = (wayx ? posx : posx - cost), rx = (wayx ? posx + cost : posx);
				int ly = (wayy ? posy : posy - cost), ry = (wayy ? posy + cost : posy);
				if (!(rx < ly) && !(ry < lx)) res++;
			}
			posx += (wayx ? cost : -cost), posy += (wayy ? cost : -cost);
			if (posx == k[x][ptrx]) ptrx++, wayx ^= 1;
			if (posy == k[y][ptry]) ptry++, wayy ^= 1;
		}
		print(res), puts("");
	}
	return 0;
}
