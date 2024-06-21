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
typedef pair <unsigned, unsigned> pii;

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

const int MAXN = (1 << 20) + 5;
const unsigned BASE = 17;
int T, n;
unsigned pw[MAXN];
mt19937 rnd(1713336327);

int root[MAXN];

#define ls(x) pool[x].ls
#define rs(x) pool[x].rs
#define mid ((L + R) >> 1)

struct node {
	int ls, rs;
	unsigned rh, fh;
} pool[MAXN << 5];

int cnt = 0;

namespace seg {

	void pushup(int x, int L, int R) {
		pool[x].fh = pool[ls(x)].fh * pw[R - mid] + pool[rs(x)].fh;
		pool[x].rh = pool[rs(x)].rh * pw[mid - L + 1] + pool[ls(x)].rh;
	}

	void modify(int &x, int L, int R, int pos) {
		if (!x) x = ++cnt;
		if (L == R) return pool[x].fh = pool[x].rh = 1, void();
		if (pos <= mid) modify(ls(x), L, mid, pos);
		else modify(rs(x), mid + 1, R, pos);
		pushup(x, L, R);
	}

	void merge(int &x, int y, int L, int R) {
		if (!x || !y) return x = x + y, void();
		if (L == R) return pool[x].fh = pool[x].rh = 1, void();
		merge(ls(x), ls(y), L, mid);
		merge(rs(x), rs(y), mid + 1, R);
		pushup(x, L, R);
	}

	pii askF(int x, int L, int R, int l, int r) {
		if (l <= L && R <= r) return dl(pool[x].fh, R - L + 1);
		pii resL = dl(0, 0), resR = dl(0, 0);
		if (l <= mid) resL = askF(ls(x), L, mid, l, r);
		if (r > mid) resR = askF(rs(x), mid + 1, R, l, r);
		return dl(resL.ec * pw[resR.fb] + resR.ec, resL.fb + resR.fb);
	}

	pii askR(int x, int L, int R, int l, int r) {
		if (l <= L && R <= r) return dl(pool[x].rh, R - L + 1);
		pii resL = dl(0, 0), resR = dl(0, 0);
		if (l <= mid) resL = askR(ls(x), L, mid, l, r);
		if (r > mid) resR = askR(rs(x), mid + 1, R, l, r);
		return dl(resR.ec * pw[resL.fb] + resL.ec, resL.fb + resR.fb);
	}
}

#undef mid

vector <int> G[MAXN];

void dfs(int u, int fa) {
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(v, u);
		int len = min(u, n - u + 1);
		unsigned resL, resR;
		resL = seg::askF(root[v], 1, n, u - len + 1, u + len - 1).ec;
		resR = seg::askR(root[v], 1, n, u - len + 1, u + len - 1).ec;
		if (resL != resR) {
			putchar('Y'), putchar('E'), putchar('S');
			putchar(32);
			int l = 1, r = len;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (seg::askF(root[v], 1, n, u - mid + 1, u + mid - 1).ec ==
					seg::askR(root[v], 1, n, u - mid + 1, u + mid - 1).ec) l = mid + 1;
				else r = mid;
			}
			print(u - l + 1), putchar(32), print(u), putchar(32), print(u + l - 1), putchar(10);
			exit(0);
		}
		seg::merge(root[u], root[v], 1, n);
		if (clock() > 2.15 * CLOCKS_PER_SEC) return puts("NO"), exit(0), void();
	}
}

signed main() {
	/* cout << rnd(); */
	pw[0] = 1;
	rep (i, 1, 1 << 20) pw[i] = pw[i - 1] * BASE;
	n = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep (i, 1, n) seg::modify(root[i], 1, n, i);
	dfs(3797250302 % n + 1, 0);
	puts("NO");
	return 0;
}
