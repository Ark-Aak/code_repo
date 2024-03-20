#include <bits/stdc++.h>

#define int ll

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

const int MAXN = 5e4 + 5;

struct Basis {

	vector <int> B;

	Basis() { B.clear(); }

	void clear() { B.clear(); }

	void insert(int x) {
		for (auto i : B) x = min(x, x ^ i);
		if (!x) return;
		for (auto &i : B) i = min(i, i ^ x);
		B.push_back(x);
	}

	void merge(const Basis &x) {
		for (auto i : x.B) insert(i);
	}
};

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

namespace seg {

	Basis sum[MAXN << 2];

	void insert(int x, int L, int R, int p, int v) {
		sum[x].insert(v);
		if (L == R) return;
		if (p <= mid) insert(ls(x), L, mid, p, v);
		else insert(rs(x), mid + 1, R, p, v);
	}

	Basis query(int x, int L, int R, int l, int r) {
		if (l <= L && R <= r) return sum[x];
		Basis res;
		if (l <= mid) res.merge(query(ls(x), L, mid, l, r));
		if (r > mid) res.merge(query(rs(x), mid + 1, R, l, r));
		return res;
	}
} // namespace seg

int n, m;

signed main() {
	n = read(), m = read();
	rep (i, 1, n) {
		int op = read(), x = read(), y = read();
		if (op == 1) seg::insert(1, 1, m, x, y);
		else {
			Basis res = seg::query(1, 1, m, x, y);
			int sum = 0;
			for (auto i : res.B) sum ^= i;
			print(sum), putchar(10);
		}
	}
	return 0;
}
