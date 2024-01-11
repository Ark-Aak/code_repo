#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

const int MAXN = 1e5 + 5;

int T, n, q;

namespace BIT {
	int sum[MAXN], lazy;

	void init() {
		memset(sum, 0, sizeof sum);
		lazy = n;
	}

	int lowbit(int x) {
		return x & -x;
	}

	void add(int x, int val) {
		if (!x) return (void) (lazy += val);
		for (int i = x; i <= q; i += lowbit(i))
			sum[i] += val;
	}

	int query(int x, int sum = lazy) {
		for (int i = x; i; i -= lowbit(i))
			sum += BIT::sum[i];
		return sum;
	}
} // namespace BIT

namespace seg {
	int sum[MAXN << 2];
	int res[MAXN << 2], pos[MAXN << 2];

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

	void pushup(int x) {
		sum[x] = sum[ls(x)] + sum[rs(x)];
		if (res[ls(x)] < res[rs(x)] + sum[ls(x)])
			res[x] = res[ls(x)], pos[x] = pos[ls(x)];
		else res[x] = res[rs(x)] + sum[ls(x)], pos[x] = pos[rs(x)];
	}

	void build(int x, int L, int R) {
		if (L == R) {
			sum[x] = res[x] = (L ? 0 : n);
			pos[x] = L;
			return;
		}
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
		pushup(x);
	}

	void modify(int x, int L, int R, int p, int val) {
		if (L == R) {
			sum[x] += val;
			res[x] += val;
			return;
		}
		if (p <= mid) modify(ls(x), L, mid, p, val);
		else modify(rs(x), mid + 1, R, p, val);
		pushup(x);
	}

#undef ls
#undef rs
#undef mid
} // namespace seg

//线段树维护的是备选集合减去add操作的数量
//BIT维护的是被ban掉的集合

multiset <int> ad;
int lst[MAXN];

void printAns() {
	if (!seg::res[1]) print(BIT::query(seg::pos[1])), putchar(32);
	else putchar(48), putchar(32);
	int val = BIT::query(q);
	if (ad.size()) val -= BIT::query(*ad.rbegin());
	print(val), putchar(10);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T --> 0) {
		cin >> n >> q;
		BIT::init(); seg::build(1, 0, q);
		memset(lst, 0, sizeof lst);
		ad.clear();
		rep (i, 1, q) {
			string str;
			cin >> str;
			if (str == "add") {
				seg::modify(1, 0, q, i, -1);
				if (seg::res[1] < 0) {
					puts("bug");
					seg::modify(1, 0, q, i, 1);
				}
				else {
					ad.insert(i);
					printAns();
				}
			}
			else {
				int x, y;
				cin >> x >> y;
				auto iter = ad.lower_bound(lst[x]);
				if (y && iter == ad.end()) {
					puts("bug");
					continue;
				}
				seg::modify(1, 0, q, lst[x], -1);
				seg::modify(1, 0, q, i, 1);
				if (y) seg::modify(1, 0, q, *iter, 1);
				if (seg::res[1] >= 0) {
					if (y) ad.erase(iter);
					BIT::add(lst[x], -1), lst[x] = i, BIT::add(i, 1);
					printAns();
				}
				else {
					puts("bug");
					seg::modify(1, 0, q, lst[x], 1);
					seg::modify(1, 0, q, i, -1);
					if (y) seg::modify(1, 0, q, *iter, -1);
				}
			}
		}
	}
	return 0;
}
