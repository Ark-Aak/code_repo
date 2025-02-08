#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
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

const int MAXN = 1505;
int ans[MAXN];
int n, q, a[MAXN][MAXN];
#include <bits/extc++.h>
__gnu_pbds::gp_hash_table <int, int> da;
int cnt[MAXN * MAXN], lsh;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("square.in", "r", stdin);
	freopen("square.out", "w", stdout);
#endif
#endif
	n = read(), q = read();
	rep (i, 1, n) {
		rep (j, 1, n) {
			a[i][j] = read();
			if (!da[a[i][j]]) da[a[i][j]] = ++lsh;
			a[i][j] = da[a[i][j]];
		}
	}
	rep (x, 1, n) {
		rep (y, 1, (x == 1 ? n : 1)) {
			// this part will be excuted 2 * n - 1 times at most
			//rep (i, 1, lsh) cnt[i] = 0;
			memset(cnt + 1, 0, 4 * lsh);
			int curx = x, cury = y;
			int qq = 0;
			const auto add = [&](const int x) { ((++cnt[x]) == 1) ? ++qq : 0; };
			const auto del = [&](const int x) { ((--cnt[x]) == 0) ? --qq : 0; };
			int stx = x, sty = y;
			add(a[curx][cury]);
			do {
				while (qq <= q && curx < n && cury < n) {
					// try to expand the edge of the square
					curx++, cury++;
					rep (i, stx, curx) add(a[i][cury]);
					rep (i, sty, cury - 1) add(a[curx][i]);
				}
				if (qq > q) {
					// the square doesn't satisfy the condiftion
					// rollback the modifies
					rep (i, stx, curx) del(a[i][cury]);
					rep (i, sty, cury - 1) del(a[curx][i]);
					curx--, cury--;
				}
				// this means there's a legal square: [(stx, sty), k]
				// a square is legal means all of its sub-squares are legal
				// an element will be calculated twice
				// one add operation and one delete operation
				// a square will be illegal if its sub-squares contain an illegal square
				const int len = curx - stx + 1;
				ans[1]++;
				ans[len + 1]--;
				// then move the edge to the next square
				// maybe there's more legal square
				rep (i, stx, curx) del(a[i][sty]);
				rep (i, sty + 1, cury) del(a[stx][i]);
				stx++, sty++;
			} while (stx <= n && sty <= n);
		}
	}
	rep (i, 1, n) ans[i] += ans[i - 1];
	rep (i, 1, n) print(ans[i]), puts("");
	return 0;
}
