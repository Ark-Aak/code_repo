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

const int MAXN = 1e6 + 5;
int n, m;
vector <int> G1[MAXN], G2[MAXN];
int col[MAXN];
#define bel(x) ((x - 1) >> 1 & 1)

bool dfs(int step) {
	if (step > n) {
		int res = 0;
		rep (i, 1, 2 * n) {
			for (auto v : G1[i]) {
				if (col[i] == 0 && col[v] == 1) res = 1;
			}
		}
		return res;
	}
	col[2 * step - 1] = 0;
	col[2 * step] = 1;
	bool res1 = dfs(step + 1);
	col[2 * step - 1] = 1;
	col[2 * step] = 0;
	bool res2 = dfs(step + 1);
	if (res1 == ((step - 1) & 1) ||
		res2 == ((step - 1) & 1)) return ((step - 1) & 1);
	return res1;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, m) {
		int x = read(), y = read();
		G1[x].push_back(y);
		G2[y].push_back(x);
	}
	if (n <= 10) {
		puts(dfs(1) ? "Bob" : "Alice");
		return 0;
	}
	memset(col, -1, sizeof col);
	rep (i, 1, n) {
		int ptx = 2 * i - 1, pty = 2 * i;
		if (!bel(ptx)) {
			bool ax = 1, ay = 1;
			for (auto v : G1[ptx]) ax &= !bel(v);
			for (auto v : G1[ptx]) ax &= (col[v] != 1);
			for (auto v : G1[pty]) ay &= !bel(v);
			for (auto v : G1[pty]) ay &= (col[v] != 1);
			if (!ax && !ay) return puts("Bob"), 0;
			bool bx = 1, by = 1;
			for (auto v : G2[ptx]) bx &= !bel(v);
			for (auto v : G2[ptx]) bx &= (col[v] != 0);
			for (auto v : G2[pty]) by &= !bel(v);
			for (auto v : G2[pty]) by &= (col[v] != 0);
			if (!bx && !by) return puts("Bob"), 0;
			if (ax && bx && ay && by) {
				col[ptx] = 0;
				col[pty] = 1;
			}
			else if (ax && by) {
				// ptx -> B pty -> W
				col[ptx] = 0;
				col[pty] = 1;
			}
			else if (ay && bx) {
				// ptx -> W pty -> B
				col[ptx] = 1;
				col[pty] = 0;
			}
		}
		else {
			bool ax = 0, ay = 0;
			for (auto v : G1[ptx]) ax |= (col[v] == 1);
			for (auto v : G1[pty]) ay |= (col[v] == 1);
			if (ax || ay) return puts("Bob"), 0;
			bool bx = 0, by = 0;
			for (auto v : G2[ptx]) bx |= (col[v] == 0);
			for (auto v : G2[pty]) by |= (col[v] == 0);
			if (bx || by) return puts("Bob"), 0;
			for (auto v : G1[ptx]) if (v == pty) return puts("Bob"), 0;
			for (auto v : G2[ptx]) if (v == pty) return puts("Bob"), 0;
			col[ptx] = 0, col[pty] = 1;
		}
	}
	puts("Alice");
	return 0;
}
