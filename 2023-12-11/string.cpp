#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

int n, Q;
const int MAXN = 1e6 + 5;
const int BASE = 147744151, MOD = 998244353;

int fa[MAXN], pw[MAXN];
vector <int> s[MAXN];

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

int sum[MAXN][2];

void pushup(int x, int L, int R) {
	int lenL = mid - L + 1, lenR = R - mid;
	sum[x][0] = (sum[ls(x)][0] + sum[rs(x)][0] * pw[lenL] % MOD) % MOD;
	sum[x][1] = (sum[rs(x)][1] + sum[ls(x)][1] * pw[lenR] % MOD) % MOD;
}

void build(int x, int L, int R) {
	if (L == R) return (void) (sum[x][0] = sum[x][1] = L);
	build(ls(x), L, mid);
	build(rs(x), mid + 1, R);
	pushup(x, L, R);
}

void modify(int x, int L, int R, int pos, int k) {
	if (L == R) return (void) (sum[x][0] = sum[x][1] = k);
	if (pos <= mid) modify(ls(x), L, mid, pos, k);
	else modify(rs(x), mid + 1, R, pos, k);
	pushup(x, L, R);
}

pair <int, int> query(int x, int L, int R, int l, int r, int tp) {
	if (l <= L && R <= r) return {sum[x][tp], R - L + 1};
	pair <int, int> res[3];
	res[1].first = 0, res[1].second = 0;
	res[2].first = 0, res[2].second = 0;
	if (l <= mid) res[1] = query(ls(x), L, mid, l, r, tp);
	if (r > mid) res[2] = query(rs(x), mid + 1, R, l, r, tp);
	if (l <= mid && r > mid) {
		res[1].first = (res[tp + 1].first + res[2 - tp].first * pw[res[tp + 1].second] % MOD) % MOD;
		res[2].first = 0;
	}
	return {(res[1].first + res[2].first) % MOD, res[1].second + res[2].second};
}

int siz[MAXN];

void merge(int x, int y) {
	int fax = find(x), fay = find(y);
	if (fax == fay) return;
	if (siz[fax] > siz[fay])
		swap(x, y), swap(fax, fay);
	for (auto v : s[fax]) {
		s[fay].emplace_back(v);
		fa[v] = fay;
		modify(1, 1, n, v, fay);
	}
	siz[fay] += siz[fax];
	s[fax].clear();
	siz[fax] = 0;
}

void solve(int x, int y) {
	int lst = 0;
	for (; ; ) {
		int L = lst, R = (y - x) >> 1;
		while (L <= R) {
			if (query(1, 1, n, x, x + mid, 0) == query(1, 1, n, y - mid, y, 1))
				L = mid + 1;
			else R = mid - 1;
		}
		lst = L + 1;
		if (L > ((y - x) >> 1)) break;
		merge(x + L, y - L);
	}
}

signed main() {
	read(n), read(Q);
	rep (i, 1, n) fa[i] = i, siz[i] = 1, s[i].emplace_back(i);
	pw[0] = 1;
	rep (i, 1, 3e5) pw[i] = pw[i - 1] * BASE % MOD;
	build(1, 1, n);
	while (Q --> 0) {
		int op;
		read(op);
		int a, b, x, y, l, r;
		if (op == 1) {
			read(l), read(r);
			solve(l, r);
		}
		else {
			read(a), read(b), read(x), read(y);
			if (b - a != y - x) {
				puts("Not equal");
				continue;
			}
			auto it1 = query(1, 1, n, a, b, 0).first, it2 = query(1, 1, n, x, y, 0).first;
			if (it1 != it2) {
				puts("Unknown");
			}
			else puts("Equal");
		}
	}
	return 0;
}
