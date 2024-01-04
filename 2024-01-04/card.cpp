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
map <int, int> mst, msnt;
set <int> anon;

namespace BIT {
	int sum[MAXN];

	inline int lowbit(int x) {
		return x & -x;
	}

	void add(int x, int val) {
		for (int i = x; i <= 1e5; i += lowbit(i))
			sum[i] += val;
	}

	int query(int x, int res = 0) {
		for (int i = x; i; i -= lowbit(i))
			res += sum[i];
		return res;
	}
} // namespace BIT

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T --> 0) {
		memset(BIT::sum, 0, sizeof BIT::sum);
		cin >> n >> q;
		rep (i, 1, q) {
			string op;
			int x = 0, y = 0;
			cin >> op;
			if (op == "test") {
				cin >> x >> y;
			}
			int tp = op == "test";
			int nowSize = anon.size() + mst.size();
			if (!tp) {
				if (nowSize >= n) {
					puts("bug");
					continue;
				}
				anon.insert(i);
			}
			else {
				if (y)
					if (!msnt.count(x))
						if (!mst.count(x))
							if (!anon.size()) {puts("bug"); continue;}
							else anon.erase(anon.begin()), msnt[x] = i, BIT::add(i, 1);
						else mst.erase(mst.find(x)), msnt[x] = i, BIT::add(i, 1);
					else {puts("bug"); continue;}
				else
					if (!msnt.count(x))
						if (!mst.count(x))
							if (nowSize >= n) {puts("bug"); continue;}
							else msnt[x] = i, BIT::add(i, 1);
						else {puts("bug"); continue;}
					else msnt[x] = i, BIT::add(i, 1);
			}
			int siz = anon.size() ? BIT::query(*anon.rbegin()) : 0;
			siz = min(siz, (int) anon.size());
			print(mst.size() + anon.size()), putchar(32);
			print(msnt.size() - siz), putchar(10);
		}
	}
	return 0;
}
